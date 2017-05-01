#include <stdio.h>
#include "gameboy.h"
#include "gpu.h"
#include "interrupts.h"

#define GET_NTH_BYTE(n, value) (((value) & (1 << (n))) >> (n))

static void	draw_pixel(t_gameboy *gb, int x, int y, uint8_t pixel)
{
    int x_wide = gb->gpu.display.width / SCREEN_WIDTH;
    int y_wide = gb->gpu.display.height / SCREEN_HEIGHT;

    int tmp_x, tmp_y, tmp_x_wide, tmp_y_wide;

    tmp_x_wide = x_wide;
    tmp_y_wide = y_wide;
    tmp_x = x * x_wide;
    tmp_y = y * y_wide;

    while (tmp_y_wide != 0) {
        while (tmp_x_wide != 0) {
            gb->gpu.pixels[(tmp_y * gb->gpu.display.width) + (tmp_x)] = pixel;
            ++tmp_x;
            --tmp_x_wide;
        }
        tmp_x = x * x_wide;
        tmp_x_wide = x_wide;
        ++tmp_y;
        --tmp_y_wide;
    }
}

static void draw_tile(t_gameboy *gb, uint8_t *tile, int x, int y)
{
    for (unsigned j = 0; j < 8; ++j) {
        for (unsigned i = 0; i < 8; ++i) {
            draw_pixel(gb, x + i, y + j,
                    gb->gpu.display.palette[(GET_NTH_BYTE(7 - i, tile[(j * 2) + 1]) << 1) | (GET_NTH_BYTE(7 - i, tile[(j * 2)]))]);
        }
    }

}

static inline uint8_t  *get_tile(t_gameboy *gb, uint8_t tile)
{
    return ((*gb->hregisters.lcdc & LCDC_BGWTD_SELECT) ?
            (gb->memory.start + CHARACTER_RAM_INDEX + (tile * TILE_SIZE)) :
            (gb->memory.start + CHARACTER_RAM_INDEX + 0x1000 + ((int8_t)tile * TILE_SIZE)));
}

static inline uint8_t *get_bg_map(t_gameboy *gb)
{
    return ((*gb->hregisters.lcdc & LCDC_BGTM_SELECT) ?
            (gb->memory.start + BG_MAP_2_INDEX) :
            (gb->memory.start + BG_MAP_1_INDEX));
}

bool		init_gpu(t_gameboy *gb)
{
  gb->gpu.display.width = SCREEN_WIDTH * gb->gpu.display.scale;
  gb->gpu.display.height = SCREEN_HEIGHT * gb->gpu.display.scale;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return (1);
    }
  gb->gpu.display.screen = SDL_SetVideoMode(gb->gpu.display.width, gb->gpu.display.height, 8,
				    SDL_HWSURFACE | SDL_RESIZABLE);
  if (gb->gpu.display.screen == NULL)
    {
      fprintf(stderr, "SDL_SetVideoMode failed: %s\n", SDL_GetError());
      return (1);
    }
  gb->gpu.pixels = gb->gpu.display.screen->pixels;
  gb->gpu.display.palette[0] = SDL_MapRGB(gb->gpu.display.screen->format, 0xFF, 0xFF, 0xFF);
  gb->gpu.display.palette[1] = SDL_MapRGB(gb->gpu.display.screen->format, 0xAA, 0xAA, 0xAA);
  gb->gpu.display.palette[2] = SDL_MapRGB(gb->gpu.display.screen->format, 0x55, 0x55, 0x55);
  gb->gpu.display.palette[3] = SDL_MapRGB(gb->gpu.display.screen->format, 0x00, 0x00, 0x00);
  return (0);
}

static inline void	refresh_screen(t_gameboy *gb)
{
  SDL_Flip(gb->gpu.display.screen);
}

void            dump_tile(t_gameboy *gb, uint8_t *tile)
{
    for (unsigned j = 0; j < 8; ++j) {
        for (unsigned i = 0; i < 8; ++i) {
            uint8_t pixel = gb->gpu.display.palette[
                (GET_NTH_BYTE(7 - i, tile[(j * 2) + 1]) << 1) |
                    (GET_NTH_BYTE(7 - i, tile[(j * 2)]))] != 0xff;

            if (pixel)
                printf("%02hhx ", pixel);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void             dump_background_tile_map(t_gameboy *gb)
{
    uint8_t             *map = get_bg_map(gb);
    uint8_t             *tile;
    unsigned            x = 0, y = 0;


    for (y = 0; y < 18; ++y) {
        for (x = 0; x < 20; ++x) {
            tile = get_tile(gb, map[y * 32 + x]);
            draw_tile(gb, tile, x * 8, y * 8);
        }
    }
    refresh_screen(gb);
}

static void	clear_screen(t_gameboy *gb)
{
  for (unsigned i = 0; i < gb->gpu.display.width * gb->gpu.display.height; ++i) {
      gb->gpu.pixels[i] = 255;
  }

}

static inline void     compare_lyc(t_gameboy *gb)
{
    if (*gb->hregisters.lyc == *gb->hregisters.ly)
    {
        *gb->hregisters.stat |= LYC_COINCIDENCE_BIT;
        ask_lcd_stat_interrupt(gb->hregisters._if);
    }
}

static void     update_gpu(t_gameboy *gb)
{
    uint8_t     mode = *gb->hregisters.stat & 0x3;

    gb->gpu.mode_counter += gb->instruction.cycles;
    switch (mode)
    {
        // H-Blank
        case 0:
            if (gb->gpu.mode_counter >= 204)
            {
                gb->gpu.mode_counter = 0;
                (*gb->hregisters.ly)++;

                if (*gb->hregisters.ly == SCREEN_HEIGHT - 1) {
                    *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, 1);
                    // put image dans le cul;
                }
                else {
                    *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, 2);
                }
            }
            break;
        // V-Blank
        case 1:
            if (gb->gpu.mode_counter >= 456)
            {
                gb->gpu.mode_counter = 0;
                (*gb->hregisters.ly)++;
                if ((*gb->hregisters.ly) == 153)
                {
                    *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, 2);
                    (*gb->hregisters.ly) = 0;
                    ask_vblank_interrupt(gb->hregisters._if);
                }
            }
            break;
        // OAM Used
        case 2:
            if (gb->gpu.mode_counter >= 80)
            {
                gb->gpu.mode_counter = 0;
                *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, 3);
            }
            break;
        // OAM and display RAM Used
        case 3:
            if (gb->gpu.mode_counter >= 172)
            {
                gb->gpu.mode_counter = 0;
                *gb->hregisters.stat = SET_STAT_MODE(*gb->hregisters.stat, 0);
                // TODO: renderscan
            }
            break;
    }
}

void                    dump_vram(t_gameboy *gb)
{
    uint8_t             *tiles = gb->memory.start + VRAM_INDEX;
    unsigned            x = 0, y = 0, i = 0;

    for (y = 0; y < 18; ++y) {
        for (x = 0; x < 20; ++x) {
            draw_tile(gb, &tiles[i * 16], x * 8, y * 8);
            ++i;
        }
    }
    refresh_screen(gb);
}

void		gpu_step(t_gameboy *gb)
{
  unsigned char	lcdc = *gb->hregisters.lcdc;
  SDL_Event event;

  /*clear_screen(gb);*/
  /*dump_background_tile_map(gb);*/
  /*dump_vram(gb);*/
  update_gpu(gb);
  while (SDL_PollEvent(&event)) {
      switch (event.type)
	{
	case SDL_QUIT:
	  gb->stop = true;
          break;
        }
  }
  if (!(lcdc & LCDC_LCD_ENABLE))
      return ;
}

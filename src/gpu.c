#include <stdio.h>
#include "gameboy.h"
#include "gpu.h"

void		draw_pixel(t_gameboy *gb, int x, int y, uint8_t pixel)
{
    int x_wide = gb->gpu.width / 160;
    int y_wide = gb->gpu.height / 144;

    int tmp_x, tmp_y, tmp_x_wide, tmp_y_wide;

    tmp_x_wide = x_wide;
    tmp_y_wide = y_wide;

    tmp_x = x * x_wide;
    tmp_y = y * y_wide;

    while (tmp_y_wide != 0) {
        while (tmp_x_wide != 0) {
            gb->gpu.pixels[(tmp_y * gb->gpu.width) + (tmp_x)] = pixel;
            ++tmp_x;
            --tmp_x_wide;
        }
        tmp_x = x * x_wide;
        tmp_x_wide = x_wide;
        ++tmp_y;
        --tmp_y_wide;
    }
}

bool		init_gpu(t_gameboy *gb)
{
  gb->gpu.width = 160 * 2;
  gb->gpu.height = 144 * 2;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
      return (1);
    }
  gb->gpu.screen = SDL_SetVideoMode(gb->gpu.width, gb->gpu.height, 8,
				    SDL_HWSURFACE);
  if (gb->gpu.screen == NULL)
    {
      fprintf(stderr, "SDL_SetVideoMode failed: %s\n", SDL_GetError());
      return (1);
    }
  gb->gpu.pixels = gb->gpu.screen->pixels;
  gb->gpu.palette[0] = SDL_MapRGB(gb->gpu.screen->format, 0xFF, 0xFF, 0xFF);
  gb->gpu.palette[1] = SDL_MapRGB(gb->gpu.screen->format, 0xAA, 0xAA, 0xAA);
  gb->gpu.palette[2] = SDL_MapRGB(gb->gpu.screen->format, 0x55, 0x55, 0x55);
  gb->gpu.palette[3] = SDL_MapRGB(gb->gpu.screen->format, 0x00, 0x00, 0x00);
  return (0);
}

static inline void	refresh_screen(t_gameboy *gb)
{
  SDL_Flip(gb->gpu.screen);
}

static void	clear_screen(t_gameboy *gb)
{
  for (unsigned i = 0; i < gb->gpu.width * gb->gpu.height; ++i) {
      gb->gpu.pixels[i] = 255;
  }

}

void		gpu_step(t_gameboy *gb)
{
  unsigned char	lcdc = *gb->hregisters.lcdc;
  SDL_Event event;

  clear_screen(gb);
  refresh_screen(gb);
  while (SDL_PollEvent(&event)) {
      switch (event.type)
	{
	case SDL_QUIT:
	  gb->stop = true;
	}
  }
  if (!(lcdc & LCDC_LCD_ENABLE))
    return ;
}

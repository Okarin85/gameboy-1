#include <stdio.h>
#include "gameboy.h"
#include "gpu.h"

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

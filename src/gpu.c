#include <stdio.h>
#include "gameboy.h"
#include "gpu.h"

void		gpu_step(t_gameboy *gb)
{
  unsigned char	lcdc = *gb->hregisters.lcdc;

  if (!(lcdc & LCDC_LCD_ENABLE))
    return ;
}

#ifndef GPU_H_
# define GPU_H_

# include <SDL/SDL.h>

enum e_lcdc
{
  LCDC_LCD_ENABLE = 1 << 7,
  LCDC_WTM_SELECT = 1 << 6,
  LCDC_W_ENABLE = 1 << 5,
  LCDC_BGWTD_SELECT = 1 << 4,
  LCDC_BGTM_SELECT = 1 << 3,
  LCDC_OBJ_SIZE = 1 << 2,
  LCDC_OBJ_ENABLE = 1 << 1,
  LCDC_BG_DISPLAY = 1 << 0,
};

typedef struct	s_gpu
{
  uint8_t	palette[4];
  unsigned	width;
  unsigned	height;
  uint8_t	*pixels;
  SDL_Surface	*screen;
}		t_gpu;

typedef struct s_gameboy	t_gameboy;

bool		init_gpu(t_gameboy *gb);
void		gpu_step(t_gameboy *gb);

#endif /* !GPU_H_ */

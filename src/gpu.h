#ifndef GPU_H_
# define GPU_H_

# include <SDL/SDL.h>
# include <stdbool.h>

# define SCREEN_WIDTH 160
# define SCREEN_HEIGHT 144

# define TILE_SIZE (16)

# define SET_STAT_MODE(value, mode) (((value) & (0xFF ^ 0x3)) | (mode))

# define LYC_COINCIDENCE_BIT (1 << 6)

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

typedef struct s_display
{
  uint8_t	palette[4];
  uint8_t       scale;
  unsigned	width;
  unsigned	height;
  SDL_Surface	*screen;
}               t_display;

typedef struct	s_gpu
{
  uint8_t	*pixels;
  t_display     display;
  unsigned      mode_counter;
}		t_gpu;

typedef struct s_gameboy	t_gameboy;

bool		init_gpu(t_gameboy *gb);
void		dump_vram(t_gameboy *gb);
void		dump_background_tile_map(t_gameboy *gb);
void		gpu_step(t_gameboy *gb);

#endif /* !GPU_H_ */

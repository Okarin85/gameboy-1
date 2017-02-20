#include <stdio.h>
#include "gameboy.h"
#include "memory_rw.h"
#include "interrupts.h"

static void	vblank(t_gameboy *gb)
{
  (void)gb;
}

static void	lcd_stat(t_gameboy *gb)
{
  (void)gb;
}

static void	timer(t_gameboy *gb)
{
  (void)gb;
}

static void	serial(t_gameboy *gb)
{
  (void)gb;
}

static void	joypad(t_gameboy *gb)
{
  (void)gb;
}

void		interrupts_step(t_gameboy *gb)
{
  struct {
      unsigned short	address;
      void		(*function)(t_gameboy *gb);
  } interrupts [] = {
	{0x40, &vblank},
	{0x48, &lcd_stat},
	{0x50, &timer},
	{0x58, &serial},
	{0x60, &joypad},
  };

  if (!(gb->interrupts.master && *gb->hregisters._if && *gb->hregisters.ie))
    return ;
  unsigned char		ints = *gb->hregisters._if & *gb->hregisters.ie;

  for (unsigned i = 0; i < (sizeof(interrupts) / sizeof(interrupts[0])); ++i)
    {
      if (ints & (1 << i))
	{
	  printf("%s = %d\n", "ZOB", i);
	  gb->interrupts.master = false;
	  push_word(gb, gb->registers.pc);
	  gb->registers.pc = interrupts[i].address;
	  (*interrupts[i].function)(gb);
	  break ;
	}
    }
}

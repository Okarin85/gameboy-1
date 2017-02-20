#include "gameboy.h"
#include "timer.h"

void		timer_step(t_gameboy *gb)
{
  unsigned char	tac = *gb->hregisters.tac;

  if (!(tac & TC_TIMER_STOP))
    return ;
  printf("TIMER ENABLED\n");

  unsigned const timings[] = { 4096, 262144, 65536, 16384 };
  unsigned clock_select = timings[tac & TC_CLOCK_SELECT];
}

#include <unistd.h>
#include "memory_rw.h"
#include "gameboy.h"
#include "timer.h"
#include "rom.h"
#include "gpu.h"
#include "cpu.h"

int		init_gameboy(t_gameboy *gb)
{
  if (load_rom(gb) || init_memory(gb))
    return (1);
  init_registers(gb);
  init_hardware_registers(gb);
  gb->interrupts.master = true;
  gb->interrupts.state = ENABLED;
  return (0);
}

int		run_gameboy(t_gameboy *gb)
{
  /*bool start = 0;*/

  while ("MCA")
    {
      cpu_step(gb);
      interrupts_step(gb);
      gpu_step(gb);
      timer_step(gb);
      /*if (gb->registers.pc == 0x2817)*/
      /*{*/
      /*printf("HELLO\n");*/
      /*start = 1;*/
      /*}*/
      /*if (start)*/
      /*{*/
      /*char		useless[1];*/
      /*read(0, useless, 1);*/
      /*}*/
    }
  return (0);
}

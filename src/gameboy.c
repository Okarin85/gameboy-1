#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <unistd.h>
#include "memory_rw.h"
#include "gameboy.h"
#include "timing.h"
#include "timer.h"
#include "rom.h"
#include "gpu.h"
#include "cpu.h"
#include "infos.h"

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
  struct timespec res = {0, 0};
  unsigned tick = 0;
  bool start = false;

  clock_gettime(CLOCK_MONOTONIC_RAW, &res);
  gb->timing.last = res.tv_nsec;
  while (!gb->stop)
    {
      /*if (start || gb->instruction.opcode == 0xFB) {*/
      if (start || gb->registers.pc == 0x319) {
          print_registers(gb);
          dump_background_tile_map(gb);
          start = 1;
      }
      cpu_step(gb);

      if (start) {
          print_instruction_infos(gb, gb->instruction.opcode);
      }

      tick += gb->instruction.cycles;
      if (tick > GB_CPU_FREQUENCY) {
	  tick = 0;
          dump_background_tile_map(gb);
      }
      interrupts_step(gb);
      gpu_step(gb);
      timer_step(gb);
      timing(gb);
      if (start)
        {
          char		useless[1];
          read(0, useless, 1);
        }
    }
  return (0);
}

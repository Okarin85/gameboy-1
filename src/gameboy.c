#include "gameboy.h"
#include "rom.h"
#include "cpu.h"

int		init_gameboy(t_gameboy *gb)
{
  if (load_rom(gb) || init_memory(gb))
    return (1);
  init_registers(gb);
  return (0);
}

int		run_gameboy(t_gameboy *gb)
{
  while ("MCA")
    {
      cpu_step(gb);
    }
  return (0);
}

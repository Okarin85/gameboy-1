#include "gameboy.h"
#include "rom.h"

int		init_gameboy(t_gameboy *gb)
{
  if (load_rom(gb) || init_memory(gb))
    return (1);
  init_registers(gb);
  return (0);
}

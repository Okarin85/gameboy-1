#include "gameboy.h"
#include "rom.h"

int		init_gameboy(t_gameboy *gb)
{
  return (load_rom(gb) || init_memory(gb));
}

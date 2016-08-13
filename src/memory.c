#include <stdlib.h>
#include "gameboy.h"
#include "errors.h"
#include <string.h>

static void	init_cardbridge(t_gameboy *gb)
{
  gb->memory.cb.rst_iv = gb->memory.start + RST_IV_INDEX;
  gb->memory.cb.header = gb->memory.start + HEADER_INDEX;
  gb->memory.cb.rom_bank_0 = gb->memory.start + ROM_BANK_0_INDEX;
  gb->memory.cb.rom_banks = gb->memory.start + ROM_BANKS_INDEX;

  memcpy(gb->memory.start, gb->rom.start, 0x8000);
}

static void	init_vram(char *start, t_vram *vram)
{
  vram->character_ram = start + CHARACTER_RAM_INDEX;
  vram->bg_map_1 = start + BG_MAP_1_INDEX;
  vram->bg_map_2 = start + BG_MAP_2_INDEX;
}

static void	init_ram(char *start, t_ram *ram)
{
  ram->cb = start + CARDBRIDGE_RAM_INDEX;
  ram->internal = start + INTERNAL_RAM_INDEX;
  ram->echo = start + ECHO_RAM_INDEX;
  ram->oam = start + OAM_INDEX;
  ram->high = start + HIGH_RAM_INDEX;
}

int		init_memory(t_gameboy *gb)
{
  if ((gb->memory.start = malloc(MEMORY_SIZE)) == NULL)
    return (perr(FUNC_ERR("malloc")));
  memset(gb->memory.start, 0, MEMORY_SIZE);
  init_cardbridge(gb);
  init_vram(gb->memory.start, &gb->memory.vram);
  init_ram(gb->memory.start, &gb->memory.ram);
  gb->memory.io = (char *)IO_REGISTERS_INDEX;
  gb->memory.interupt = (char *)INTERRUPT_ENABLE_INDEX;
  return (0);
}

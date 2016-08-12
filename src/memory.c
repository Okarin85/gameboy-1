#include <stdlib.h>
#include "gameboy.h"
#include "errors.h"

static void	init_cardbridge(char *start, t_cardbridge *cb)
{
  cb->rst_iv = start + RST_IV_INDEX;
  cb->header = start + HEADER_INDEX;
  cb->rom_bank_0 = start + ROM_BANK_0_INDEX;
  cb->rom_banks = start + ROM_BANKS_INDEX;
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

int		init_memory(t_memory *memory)
{
  if ((memory->start = malloc(MEMORY_SIZE)) == NULL)
    return (perr(FUNC_ERR("malloc")));
  init_cardbridge(memory->start, &memory->cb);
  init_vram(memory->start, &memory->vram);
  init_ram(memory->start, &memory->ram);
  return (0);
}

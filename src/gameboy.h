#ifndef GAMEBOY_H_
# define GAMEBOY_H_

# include "registers.h"

# define MEMORY_SIZE	0x10000

enum			e_memory_map_indexes {
    CARDBRIDGE_INDEX		= 0x0000,
    RST_IV_INDEX		= CARDBRIDGE_INDEX,
    HEADER_INDEX		= 0x0100,
    ROM_BANK_0_INDEX		= 0x0150,
    ROM_BANKS_INDEX		= 0x4000,
    VRAM_INDEX			= 0x8000,
    CHARACTER_RAM_INDEX		= VRAM_INDEX,
    BG_MAP_1_INDEX		= 0x9800,
    BG_MAP_2_INDEX		= 0x9800,
    RAM_INDEX			= 0xA000,
    CARDBRIDGE_RAM_INDEX	= RAM_INDEX,
    INTERNAL_RAM_INDEX		= 0xC000,
    ECHO_RAM_INDEX		= 0xE000,
    OAM_INDEX			= 0xFE00,
    IO_REGISTERS_INDEX		= 0xFF00,
    HIGH_RAM_INDEX		= 0xFF80,
    INTERRUPT_ENABLE_INDEX	= 0xFFFF

};

typedef struct		s_cardbridge
{
  void			*rst_iv;
  void			*header;
  void			*rom_bank_0;
  void			*rom_banks;
}			t_cardbridge;

typedef struct		s_vram
{
  void			*character_ram;
  void			*bg_map_1;
  void			*bg_map_2;
}			t_vram;

typedef struct		s_ram
{
  void			*cb;
  void			*internal;
  void			*echo;
  void			*oam;
  void			*high;
}			t_ram;

typedef struct		s_memory
{
  void			*start;
  t_cardbridge		cb;
  t_vram		vram;
  t_ram			ram;
  void			*io;
  char			*interupt;
}			t_memory;

typedef struct		s_gameboy
{
  t_memory		memory;
  t_registers		registers;
  unsigned		ticks;
}			t_gameboy;

#endif /* !GAMEBOY_H_ */

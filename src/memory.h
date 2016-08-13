#ifndef MEMORY_H_
# define MEMORY_H_

# define MEMORY_SIZE	0x10000
# define L_ENDIAN

typedef struct s_gameboy	t_gameboy;

enum			e_memory_map_indexes {
    CARTBRIDGE_INDEX		= 0x0000,
    RST_IV_INDEX		= CARTBRIDGE_INDEX,
    HEADER_INDEX		= 0x0100,
    ROM_BANK_0_INDEX		= 0x0150,
    ROM_BANKS_INDEX		= 0x4000,
    VRAM_INDEX			= 0x8000,
    CHARACTER_RAM_INDEX		= VRAM_INDEX,
    BG_MAP_1_INDEX		= 0x9800,
    BG_MAP_2_INDEX		= 0x9800,
    RAM_INDEX			= 0xA000,
    CARTBRIDGE_RAM_INDEX	= RAM_INDEX,
    INTERNAL_RAM_INDEX		= 0xC000,
    ECHO_RAM_INDEX		= 0xE000,
    OAM_INDEX			= 0xFE00,
    IO_REGISTERS_INDEX		= 0xFF00,
    HIGH_RAM_INDEX		= 0xFF80,
    INTERRUPT_ENABLE_INDEX	= 0xFFFF

};

typedef struct		s_cartbridge
{
  char			*rst_iv;
  char			*header;
  char			*rom_bank_0;
  char			*rom_banks;
}			t_cartbridge;

typedef struct		s_vram
{
  char			*character_ram;
  char			*bg_map_1;
  char			*bg_map_2;
}			t_vram;

typedef struct		s_ram
{
  char			*cb;
  char			*internal;
  char			*echo;
  char			*oam;
  char			*high;
}			t_ram;

typedef struct		s_memory
{
  char			*start;
  t_cartbridge		cb;
  t_vram		vram;
  t_ram			ram;
  char			*io;
  char			*interupt;
}			t_memory;

int			init_memory(t_gameboy *gb);

#endif /* !MEMORY_H_ */

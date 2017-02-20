#include <stdio.h>
#include "memory.h"
#include "gameboy.h"

char		fetch_byte(t_gameboy *gb, unsigned short address)
{
  return (gb->memory.start[address]);
}

unsigned short	fetch_word(t_gameboy *gb, unsigned short address)
{
  return ((fetch_byte(gb, address) & 0x00FF) |
	  (fetch_byte(gb, address + 1) << 8));
}

void			write_byte(t_gameboy *gb, unsigned short address, unsigned char value)
{
  unsigned short	offset;

  gb->memory.start[address] = value;
  if (address >= INTERNAL_RAM_INDEX && address < OAM_INDEX)
    {
      offset = address - (address > ECHO_RAM_INDEX ? ECHO_RAM_INDEX : INTERNAL_RAM_INDEX);
      if (offset < OAM_INDEX - ECHO_RAM_INDEX)
	gb->memory.ram.echo[offset] = value;
    }
  else
    {
      // Hardware interruptions
      switch (address)
	{
	  // DIV
	case 0xFF04:
	  gb->memory.start[address] = 0;
	  break;
	default:
	  break;
	};
    }
}

void		write_word(t_gameboy *gb, unsigned short address, unsigned short value)
{
  write_byte(gb, address, (unsigned char)(value & 0x00FF));
  write_byte(gb, address + 1, (unsigned char)((value & 0xFF00) >> 8));
}

unsigned char	pop_byte(t_gameboy *gb)
{
  return (gb->memory.start[gb->registers.sp++]);
}

unsigned short	pop_word(t_gameboy *gb)
{
  return ((pop_byte(gb) & 0x00FF) | (pop_byte(gb) << 8));
}

void		push_byte(t_gameboy *gb, unsigned char value)
{
  gb->memory.start[--gb->registers.sp] = value;
}

void		push_word(t_gameboy *gb, unsigned short value)
{
  push_byte(gb, (value & 0xFF00) >> 8);
  push_byte(gb, value & 0x00FF);
}

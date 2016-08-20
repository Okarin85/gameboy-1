#include <string.h>
#include <stdio.h>
#include "gameboy.h"
#include "rom.h"
#include "instructions.h"
#include "infos.h"

static void	print_cartbridge_type(unsigned char ct)
{
  for (unsigned i = 0; i < (sizeof(g_cb_types) / sizeof(g_cb_types[0])); ++i)
    {
      if (g_cb_types[i].key == ct)
	{
	  printf("Cartbridge type: %s\n", g_cb_types[i].value);
	  return ; }
    }
}

static void	print_rom_size(unsigned char rs)
{
  for (unsigned i = 0; i < (sizeof(g_rom_sizes) / sizeof(g_rom_sizes)); ++i)
    {
      if (g_rom_sizes[i].key == rs)
	{
	  printf("Rom size: %s\n", g_rom_sizes[i].value);
	  return ;
	}
    }
}

static void	print_ram_size(unsigned char rs)
{
  for (unsigned i = 0; i < (sizeof(g_ram_sizes) / sizeof(g_ram_sizes)); ++i)
    {
      if (g_ram_sizes[i].key == rs)
	{
	  printf("Ram size: %s\n", g_ram_sizes[i].value);
	  return ;
	}
    }
}

void		print_header_infos(t_header *header)
{
  char		title[17];

  strncpy(title, header->title, sizeof(header->title));
  title[16] = 0;
  printf("Title of the game: %s\n", title);
  print_cartbridge_type(header->cart_type);
  print_rom_size(header->cart_rom_size);
  print_ram_size(header->cart_ram_size);
  printf("_________________________\n\n");
}

void		print_instruction_infos(t_gameboy *gb, unsigned char opcode)
{
  printf("Pc: 0x%04X\n", gb->registers.pc);
  if (g_instructions[opcode].instr_length == 0)
    printf("%s", g_instructions[opcode].debug);
  else if (g_instructions[opcode].instr_length == 1)
    printf(g_instructions[opcode].debug, gb->operand.len8);
  else
    printf(g_instructions[opcode].debug, gb->operand.len16);
  printf("\n_________________________\n\n");
}

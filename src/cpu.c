#include "instructions.h"
#include <stdio.h>

int		cpu_loop(t_gameboy *gameboy)
{
  unsigned char	opcode;

  while ("MCA")
    {

      if (g_instructions[opcode].instr_length != 0)
	(g_instructions[opcode].func)(gameboy);
      else
	fprintf(stderr, "Unimplemented instruction %02X !\n", opcode);
    }
}

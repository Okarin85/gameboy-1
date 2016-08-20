#include <stdio.h>
#include "gameboy.h"
#include "infos.h"
#include "instructions.h"
#include "memory_rw.h"

static void	get_operand(t_gameboy *gb, unsigned char opcode)
{
  if (g_instructions[opcode].instr_length == 1)
    {
      gb->operand.len8 = fetch_byte(gb->memory.start + gb->registers.pc);
      gb->registers.pc += 1;
    }
  else if (g_instructions[opcode].instr_length == 2)
    {
      gb->operand.len16 = fetch_word(gb->memory.start + gb->registers.pc);
      gb->registers.pc += 2;
    }
}

void				cpu_step(t_gameboy *gb)
{
  unsigned char			opcode;
  static unsigned long long	instr_number = 0;

  opcode = gb->memory.start[gb->registers.pc];
  gb->registers.pc += 1;
  get_operand(gb, opcode);
  ++instr_number;
  if (g_instructions[opcode].nb_cycles != 0)
    {
      print_instruction_infos(gb, opcode);
      (g_instructions[opcode].func)(gb);
    }
  else
    {
      fprintf(stderr, "Unimplemented instruction %02X !\n", opcode);
      fprintf(stderr, "%llu\nn", instr_number);
    }
}

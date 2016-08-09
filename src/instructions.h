#ifndef INSTRUCTION_H_
# define INSTRUCTION_H_

typedef void	(t_instruction_func)();

/*
** - instr_length : length of the whole instruction in bytes
*/
typedef struct		s_instruction
{
  char const		*debug;
  t_instruction_func	*func;
  unsigned char		instr_length;
  unsigned char		nb_cycles;
}			t_instruction;

#endif /* !INSTRUCTION_H_ */

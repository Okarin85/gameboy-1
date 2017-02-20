#ifndef GAMEBOY_H_
# define GAMEBOY_H_

# include "cpu.h"
# include "registers.h"
# include "rom.h"
# include "interrupts.h"
# include "memory.h"

typedef struct		s_file
{
  char const		*name;
  long			size;
}			t_file;

typedef struct		s_keys
{
  bool			a;
  bool			b;
  bool			select;
  bool			start;
  bool			left;
  bool			right;
  bool			up;
  bool			down;
}			t_keys;

typedef struct		s_gameboy
{
  t_file		file;
  t_memory		memory;
  t_registers		registers;
  t_hardware_registers	hregisters;
  t_rom			rom;
  t_fetched		instruction;
  t_keys		keys;
  t_interrupts		interrupts;
  unsigned		ticks;
}			t_gameboy;

int		init_gameboy(t_gameboy *gb);
int		run_gameboy(t_gameboy *gb);

#endif /* !GAMEBOY_H_ */

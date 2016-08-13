#ifndef GAMEBOY_H_
# define GAMEBOY_H_

# include "registers.h"
# include "rom.h"
# include "memory.h"


typedef struct		s_file
{
  char const		*name;
  long			size;
}			t_file;

typedef struct		s_gameboy
{
  t_file		file;
  t_memory		memory;
  t_registers		registers;
  t_rom			rom;
  unsigned		ticks;
}			t_gameboy;

int		init_gameboy(t_gameboy *gb);

#endif /* !GAMEBOY_H_ */

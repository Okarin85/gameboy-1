#ifndef GAMEBOY_H_
# define GAMEBOY_H_

# include "registers.h"

typedef struct		s_memory
{
  void			*ram;
}			t_memory;

typedef struct		s_gameboy
{
  t_memory		memory;
  t_registers		registers;
}			t_gameboy;

#endif /* !GAMEBOY_H_ */

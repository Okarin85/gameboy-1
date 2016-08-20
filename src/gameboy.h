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

enum			e_interupts_state {
    ENABLED		= (1 << 1),
    DISABLED		= (1 << 2),
    ENABLE_NEXT		= (1 << 3),
    DISABLE_NEXT	= (1 << 4),
};

typedef union		u_operand
{
  unsigned char		len8;
  unsigned short	len16;
}			t_operand;

typedef struct		s_gameboy
{
  t_file		file;
  t_memory		memory;
  t_registers		registers;
  t_hardware_registers	hregisters;
  t_rom			rom;
  t_operand		operand;
  unsigned		ticks;
  char			interupts;
}			t_gameboy;

int		init_gameboy(t_gameboy *gb);
int		run_gameboy(t_gameboy *gb);

#endif /* !GAMEBOY_H_ */

#ifndef INTERRUPTS_H_
# define INTERRUPTS_H_

# include <stdlib.h>
# include <stdbool.h>

enum			e_interrupts_state {
    ENABLED		= (1 << 1),
    DISABLED		= (1 << 2),
    ENABLE_NEXT		= (1 << 3),
    DISABLE_NEXT	= (1 << 4),
};

typedef struct			s_interrupts
{
  bool				master;
  enum e_interrupts_state	state;
}				t_interrupts;

void		interrupts_step(t_gameboy *gb);

#endif /* !INTERRUPTS_H_ */

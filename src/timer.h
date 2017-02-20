#ifndef TIMER_H_
# define TIMER_H_

typedef struct s_gameboy	t_gameboy;

enum e_timercontrol
{
  TC_TIMER_STOP = (1 << 2),
  TC_CLOCK_SELECT = (1 << 0) | (1 << 1)
};

void		timer_step(t_gameboy *gb);

#endif /* !TIMER_H_ */

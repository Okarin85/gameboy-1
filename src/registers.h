#ifndef REGISTERS_H_
# define REGISTERS_H_

# include <stdbool.h>
# include "memory.h"

typedef struct			s_registers
{
  struct
    {
      union
	{
	  struct
	    {
# ifdef L_ENDIAN
	      unsigned char	f;
	      unsigned char	a;
# else
	      unsigned char	a;
	      unsigned char	f;
# endif /* !L_ENDIAN */
	    };
	  unsigned short	af;
	};
    };

  struct
    {
      union
	{
	  struct
	    {
# ifdef L_ENDIAN
	      unsigned char	c;
	      unsigned char	b;
# else
	      unsigned char	b;
	      unsigned char	c;
#endif /* !L_ENDIAN */
	    };
	  unsigned short	bc;
	};
    };

  struct
    {
      union
	{
	  struct
	    {
# ifdef L_ENDIAN
	      unsigned char	e;
	      unsigned char	d;
# else
	      unsigned char	d;
	      unsigned char	e;
# endif /* !L_ENDIAN */
	    };
	  unsigned short	de;
	};
    };

  struct
    {
      union
	{
	  struct
	    {
# ifdef L_ENDIAN
	      unsigned char	l;
	      unsigned char	h;
# else
	      unsigned char	h;
	      unsigned char	l;
# endif /* !L_ENDIAN */
	    };
	  unsigned short	hl;
	};
    };

  unsigned short		sp;
  unsigned short		pc;
}				t_registers;

typedef struct		s_hardware_registers
{
  char			*p1;
  char			*sb;
  char			*sc;
  char			*div;
  char			*tima;
  char			*tma;
  char			*tac;
  char			*_if;
  char			*nr10;
  char			*nr11;
  char			*nr12;
  char			*nr13;
  char			*nr14;
  char			*nr21;
  char			*nr22;
  char			*nr23;
  char			*nr24;
  char			*nr30;
  char			*nr31;
  char			*nr32;
  char			*nr33;
  char			*nr34;
  char			*nr41;
  char			*nr42;
  char			*nr43;
  char			*nr44;
  char			*nr50;
  char			*nr51;
  char			*nr52;
  char			*wpr;
  char			*lcdc;
  char			*stat;
  char			*scy;
  char			*scx;
  char			*ly;
  char			*lyc;
  char			*dma;
  char			*bgp;
  char			*obp0;
  char			*obp1;
  char			*wy;
  char			*wx;
  char			*ie;
}			t_hardware_registers;

enum			e_flags
{
  CARRY_FLAG = 4,
	     HALF_CARRY_FLAG,
	     SUBSTRACT_FLAG,
	     ZERO_FLAG
};

/*
** 'set' and 'unset' flag can be replaced by :
** registers->f ^= (-bit ^ registers->f) & (1 << value);
*/

# define flag_attr(flag_name, value)							\
 static inline void		attr_##flag_name(t_registers *registers, bool bit)	\
 {											\
 registers->f ^= (-bit ^ registers->f) & (1 << value);				\
 }


# define flag_setter(flag_name, value)						\
 static inline void		set_##flag_name(t_registers *registers)		\
 {										\
 registers->f |= (1 << value);							\
 }

# define flag_unsetter(flag_name, value)					\
 static inline void		unset_##flag_name(t_registers *registers)	\
 {										\
 registers->f &= ~(1 << value);							\
 }

# define flag_getter(flag_name, value)						\
 static inline bool		get_##flag_name(unsigned char flags)		\
{										\
  return ((flags & (1 << value)) >> value);					\
}

flag_attr(carry_flag, CARRY_FLAG)
flag_attr(half_carry_flag, HALF_CARRY_FLAG)
flag_attr(substract_flag, SUBSTRACT_FLAG)
flag_attr(zero_flag, ZERO_FLAG)

flag_setter(carry_flag, CARRY_FLAG)
flag_setter(half_carry_flag, HALF_CARRY_FLAG)
flag_setter(substract_flag, SUBSTRACT_FLAG)
flag_setter(zero_flag, ZERO_FLAG)

flag_unsetter(carry_flag, CARRY_FLAG)
flag_unsetter(half_carry_flag, HALF_CARRY_FLAG)
flag_unsetter(substract_flag, SUBSTRACT_FLAG)
flag_unsetter(zero_flag, ZERO_FLAG)

flag_getter(carry_flag, CARRY_FLAG)
flag_getter(half_carry_flag, HALF_CARRY_FLAG)
flag_getter(substract_flag, SUBSTRACT_FLAG)
flag_getter(zero_flag, ZERO_FLAG)

# define IS_NEG(a)	(a >> ((sizeof(a) * 8) - 1))
# define IS_POS(a)	((~a) >> ((sizeof(a) * 8) - 1))

void		init_hardware_registers(t_gameboy *gb);
void		init_registers(t_gameboy *gb);

void		set_if_zero(t_registers *registers, unsigned char value);
void		set_if_carry(t_registers *registers, unsigned char a, unsigned char b, unsigned char res);
void		set_if_half_carry(t_registers *registers, unsigned char a, unsigned char b);

void		set_if_no_borrow_carry(t_registers *registers, unsigned char a, unsigned char b);
void		set_if_no_borrow_half_carry(t_registers *registers, unsigned char a, unsigned char b);

void		set_if_carry_bit15(t_registers *registers, unsigned short a, unsigned short b, unsigned short res);

void		set_if_half_carry_bit11(t_registers *registers, unsigned short a, unsigned short b);

#endif /* !REGISTERS_H_ */

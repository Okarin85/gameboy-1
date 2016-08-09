#ifndef REGISTERS_H_
# define REGISTERS_H_

# include <stdbool.h>

# define LITTLE_ENDIAN

typedef struct			s_registers
{
  struct
    {
      union
	{
	  struct
	    {
# ifdef LITTLE_ENDIAN
	      unsigned char	f;
	      unsigned char	a;
# else
	      unsigned char	a;
	      unsigned char	f;
# endif
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
# ifdef LITTLE_ENDIAN
	      unsigned char	c;
	      unsigned char	b;
# else
	      unsigned char	b;
	      unsigned char	c;
#endif
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
# ifdef LITTLE_ENDIAN
	      unsigned char	e;
	      unsigned char	d;
# else
	      unsigned char	d;
	      unsigned char	e;
# endif
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
# ifdef LITTLE_ENDIAN
	      unsigned char	l;
	      unsigned char	h;
# else
	      unsigned char	h;
	      unsigned char	l;
# endif
	    };
	  unsigned short	hl;
	};
    };

  unsigned short		sp;
  unsigned short		pc;
}				t_registers;

enum			e_flags
{
  CARRY_FLAG = 4,
	     HALF_CARRY_FLAG,
	     SUBSTRACT_FLAG,
	     ZERO_FLAG
};

/*
** 'set' and 'unset' flag can be replaced by :
** registers->f ^= (-value ^ registers->f) & (1 << CARRY_FLAG);
*/

# define flag_setter(flag_name, value)					\
 inline void		set_##flag_name(t_registers *registers)		\
 {									\
 registers->f |= (1 << value);						\
 }

# define flag_unsetter(flag_name, value)				\
 inline void		unset_##flag_name(t_registers *registers)	\
 {									\
 registers->f &= ~(1 << value);						\
 }

flag_setter(carry_flag, CARRY_FLAG)
flag_setter(half_carry_flag, HALF_CARRY_FLAG)
flag_setter(substract_flag, SUBSTRACT_FLAG)
flag_setter(zero_flag, ZERO_FLAG)

flag_unsetter(carry_flag, CARRY_FLAG)
flag_unsetter(half_carry_flag, HALF_CARRY_FLAG)
flag_unsetter(substract_flag, SUBSTRACT_FLAG)
flag_unsetter(zero_flag, ZERO_FLAG)

#endif /* !REGISTERS_H_ */

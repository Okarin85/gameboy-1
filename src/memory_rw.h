#ifndef FETCH_H_
# define FETCH_H_

static inline char	fetch_byte(void const *address)
{
  return (*((char *)address));
}

unsigned short	fetch_word(void const *address);
unsigned short	inverted_fetch_word(void const *address);

static inline void	write_byte(void *address, unsigned char value)
{
  *(unsigned char *)address = value;
}

void		write_word(void *address, unsigned short value);

#endif /* !FETCH_H_ */

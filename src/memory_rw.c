#include "gameboy.h"

unsigned short	inverted_fetch_word(void const *address)
{
#ifdef L_ENDIAN
  return ((*((unsigned short *)address) & 0x00FF) << 8) |
    ((*((unsigned short *)address) & 0xFF00) >> 8);
#else
  return (*((unsigned short *)address));
# endif /* !L_ENDIAN */
}

unsigned short	fetch_word(void const *address)
{
#ifdef L_ENDIAN
  return (*((unsigned short *)address));
#else
  return ((*((unsigned short *)address) & 0x00FF) << 8) |
    ((*((unsigned short *)address) & 0xFF00) >> 8);
# endif /* !L_ENDIAN */
}

void		write_word(void *address, unsigned short value)
{
#ifdef L_ENDIAN
  *((unsigned short *)address) = value;
#else
  *((unsigned short *)address) = ((value & 0x00FF) << 8) | ((value & 0xFF00) >> 8);
# endif /* !L_ENDIAN */
}

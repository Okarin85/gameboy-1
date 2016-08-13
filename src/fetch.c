#include "gameboy.h"

char		fetch_byte(void const *address)
{
  return (*((char *)address));
}

short		inverted_fetch_word(void const *address)
{
#ifdef L_ENDIAN
  union {
      char	array[2];
      short	value;
  }		fetched;
  char		tmp;

  fetched.value = *((short *)address);
  tmp = fetched.array[0];
  fetched.array[0] = fetched.array[1];
  fetched.array[1] = tmp;
  return (fetched.value);
#else
  return (*((short *)address));
# endif /* !L_ENDIAN */
}

short		fetch_word(void const *address)
{
#ifdef L_ENDIAN
  return (*((short *)address));
#else
  union {
      char	array[2];
      short	value;
  }		fetched;
  char		tmp;

  fetched.value = *((short *)address);
  tmp = fetched.array[0];
  fetched.array[0] = fetched.array[1];
  fetched.array[1] = tmp;
  return (fetched.value);
# endif /* !L_ENDIAN */
}

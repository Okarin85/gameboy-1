#ifndef FETCH_H_
# define FETCH_H_

inline char	fetch_byte(void const *address)
{
  return (*((char *)address));
}

short		fetch_word(void const *address);
short		inverted_fetch_word(void const *address);

#endif /* !FETCH_H_ */

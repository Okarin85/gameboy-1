#ifndef FETCH_H_
# define FETCH_H_

char		fetch_byte(void const *address);
short		fetch_word(void const *address);
short		inverted_fetch_word(void const *address);

#endif /* !FETCH_H_ */

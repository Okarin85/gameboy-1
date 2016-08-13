#include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
#include "errors.h"

long		fsize(FILE *fs)
{
  long		size;

  fseek(fs, 0, SEEK_END);
  size = ftell(fs);
  fseek(fs, 0, SEEK_SET);
  return (size);
}

int		check_file_type(char const *name)
{
#ifdef WIN32
# define IS_REGULAR_FILE(x)	((x) & _S_IFREG)
  struct _stat	buffer;

  if (_stat(name, &buffer) == -1)
#else
# define IS_REGULAR_FILE(x)	(S_ISREG(x))
    struct stat	buffer;

  if (stat(name, &buffer) == -1)
#endif /* !WIN32 */
    {
      perr("Can't load the cardbridge `%s` : %m.\n", name);
      return (-1);
    }
  if (IS_REGULAR_FILE(buffer.st_mode))
    return (buffer.st_size);
  perr("The cardbridge must be a regular file.\n", name);
  return (-1);
}

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "gameboy.h"
#include "rom.h"
#include "utils.h"

static FILE	*check_and_open_file(t_gameboy *gb)
{
  FILE		*fs;

  if ((gb->file.size = check_file_type(gb->file.name)) == -1)
    return (NULL);
  else if (gb->file.size < MIN_ROM_SIZE)
    {
      perr("The rom is too small.");
      return (NULL);
    }
  else if ((fs = fopen(gb->file.name, "r")) == NULL)
    {
      perr(FUNC_ERR("fopen"));
      return (NULL);
    }
  return (fs);
}

static int	dump_rom(t_gameboy *gb, FILE *fs)
{
  long		size;
  long		pos = 0;
  long		readed;

  if ((gb->rom.start = malloc(gb->file.size)) == NULL)
    return (perr(FUNC_ERR("malloc")));
  size = gb->file.size;
  while (size && !feof(fs) && !ferror(fs))
    {
      readed = fread(gb->rom.start + pos, size, 1, fs);
      pos += readed;
      size -= readed;
    }
  return (ferror(fs) ? perr(FUNC_ERR("fread")) : 0);
}

static void	get_rom_header(t_gameboy *gb)
{
}

static int	check_rom_header(t_gameboy *gb)
{
  t_header	*header = &gb->rom.header;

  if (header->sgb_flag == 3)
    return (perr("SGB not supported !\n"));
  else if (header->cart_type != CT_ROM_ONLY)
    return (perr("Only the ROM only cartbridges are supported !\n"));
  return (0);
}

int		load_rom(t_gameboy *gb)
{
  FILE		*fs;

  if ((fs = check_and_open_file(gb)) == NULL || dump_rom(gb, fs))
    return (1);
  get_rom_header(gb);
  if (check_rom_header(gb))
    return (1);
  fclose(fs);
  return (0);
}

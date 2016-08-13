#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "gameboy.h"
#include "fetch.h"
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

/*
** I could have read the whole structure by packing it,
** but for eventual portability problems, I decided to fill it
** field by field
*/
static void	get_rom_header(t_gameboy *gb)
{
  t_header	*header = &gb->rom.header;

  header->start = gb->rom.start + 0x100;
  memcpy(header->nintendo, header->start + 0x04, sizeof(header->nintendo));
  memcpy(header->title, header->start + 0x34, sizeof(header->title));
  header->new_licensee_code = inverted_fetch_word(header->start + 0x44);
  header->sgb_flag = fetch_byte(header->start + 0x46);
  header->cart_type = fetch_byte(header->start + 0x47);
  header->cart_rom_size = fetch_byte(header->start + 0x48);
  header->cart_ram_size = fetch_byte(header->start + 0x49);
  header->destination_code = fetch_byte(header->start + 0x4A);
  header->old_licensee_code = fetch_byte(header->start + 0x4B);
  header->mask_rom_version = fetch_byte(header->start + 0x4C);
  header->header_checksum = fetch_byte(header->start + 0x4D);
  header->global_checksum = inverted_fetch_word(header->start + 0x4E);
}

static int	check_header_checksum(t_gameboy *gb)
{
  unsigned char	checksum = 0;

  printf("Rom checksum : %d\n", gb->rom.header.header_checksum);
  for (unsigned i = 0x34; i <= 0x4C; ++i)
    {
      checksum = checksum - fetch_byte(gb->rom.header.start + i) - 1;
    }
  printf("Obtained checksum : %d\n", checksum);
  return (gb->rom.header.header_checksum != checksum ?
	  perr("The header checksum is invalid ?") : 0);
}

static int	check_rom_header(t_gameboy *gb)
{
  t_header	*header = &gb->rom.header;

  if (header->sgb_flag == 3)
    return (perr("SGB not supported !\n"));
  else if (check_header_checksum(gb))
    return (perr("Invalid header checksum !\n"));
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

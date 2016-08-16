#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infos.h"
#include "gameboy.h"
#include "get_args.h"

int		main(int argc, char *argv[])
{
  t_gameboy	gb;

  memset(&gb, 0, sizeof(gb));
  if (get_args(argc, argv, &gb) || init_gameboy(&gb))
    return (EXIT_FAILURE);
  print_header_infos(&gb.rom.header);
  return (EXIT_SUCCESS);
}

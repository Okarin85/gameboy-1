#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infos.h"
#include "gameboy.h"
#include "get_args.h"

#include "memory_rw.h"
int		main(int argc, char *argv[])
{
  t_gameboy	gb;

  memset(&gb, 0, sizeof(gb));
  if (get_args(argc, argv, &gb) || init_gpu(&gb) || init_gameboy(&gb))
    return (EXIT_FAILURE);
  run_gameboy(&gb);
  SDL_Quit();
  return (EXIT_SUCCESS);
}

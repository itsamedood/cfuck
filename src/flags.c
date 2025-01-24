// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flags.h"

flags_t read_flags(int argc, char **argv)
{
  /* All flags are set to 0 by default. */
  flags_t flags = {};

  for (int i = 0; i < argc; i++)
  {
    char *arg = argv[i];

    if (arg[0] == '-')
    {
      if (strcmp(arg, "-verbose") == 0 || strcmp(arg, "-vb") == 0)
      {
        flags.verbose = 1;
      }

      if (strcmp(arg, "-no_print") == 0 || strcmp(arg, "-np") == 0)
      {
        flags.no_print = 1;
      }

      if (strcmp(arg, "-help") == 0 || strcmp(arg, "-h") == 0)
      {
        // flags.help = 1;
        exit(0);
      }

      if (strcmp(arg, "-version") == 0 || strcmp(arg, "-h") == 0)
      {
        // flags.version = 1;
        exit(0);
      }
    }
  }

  return flags;
}

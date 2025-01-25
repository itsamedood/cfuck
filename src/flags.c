#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flags.h"

flags_t read_flags(flags_t *flags, int argc, char **argv)
{
  for (int i = 0; i < argc; i++)
  {
    char *arg = argv[i];

    if (arg[0] == '-')
    {
      if (strcmp(arg, "-verbose") == 0 || strcmp(arg, "-vb") == 0)
      {
        printf("verbose ON\n");
        flags->verbose = 1;
      }

      if (strcmp(arg, "-no_print") == 0 || strcmp(arg, "-np") == 0)
      {
        if (flags->verbose)
        {
          printf("no_print ON\n");
        }

        flags->no_print = 1;
      }

      if (strcmp(arg, "-help") == 0 || strcmp(arg, "-h") == 0)
      {
        printf("%s\n", CFUCK_USAGE);
        printf("Flags:\n");
        printf("  -verbose  | -vb\n");
        printf("  -no_print | -np\n");
        printf("  -help     | -h\n");
        printf("  -version  | -v\n");
        exit(0);
      }

      if (strcmp(arg, "-version") == 0 || strcmp(arg, "-v") == 0)
      {
        printf("cfuck v%s\n", CFUCK_VERSION);
        exit(0);
      }
    }
  }

  return *flags;
}

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flags.h"
#include "interpreter.h"

/**
 * Handles CTRL+C.
 */
void sigint_handle(int sig)
{
  printf("\nExited by user.\n\n");
  exit(0);
}

/**
 * Runs a 'shell' where you give Brainfuck code,
 * it gets interpreted, some info gets printed, and repeat.
 */
void shell(flags_t *flags)
{
  /* Initialize data. */
  int data[BUFFER_SIZE];

  /* Initialize interpreters state. */
  interpstate_t interpstate = {
    .pointer = 0,
    .loopStart = 0,
  };

  printf("Press CTRL+C to exit.\n");
  for (;;)
  {
    char code[MAX_CODE_LENGTH]; /* Heap moment. */
    printf("cfuck> ");

    /* No buffer overflow for you hackers! */
    if (fgets(code, MAX_CODE_LENGTH, stdin) != NULL)
    {
      size_t len = strlen(code);

      if (len > 0 && code[len-1] == '\n')
      {
        code[len-1] = '\0';
      }
    }

    interpstate = interpret(&interpstate, NULL, data, code);
    printf("Pointer: %d\nValue: %d\n", interpstate.pointer, data[interpstate.pointer]);
  }
}

/**
 * >++++++++[<+++++++++>-]<.    H
 * >+++[<++++++++++>-]<-.       e
 * +++++++..                    l (x2)
 * +++.                         o
 * >++++++++[<---------->-]<++. !
 *
 * All together now!
 * >++++++++[<+++++++++>-]<.>+++[<++++++++++>-]<-.+++++++..+++.>++++++++[<---------->-]<++.
 */
int main(int argc, char **argv)
{
  signal(SIGINT, sigint_handle);
  flags_t flags = {
    .verbose = 0,
    .no_print = 0,
  };

  flags = read_flags(&flags, argc, argv);

  shell(&flags);
  return 0;
}


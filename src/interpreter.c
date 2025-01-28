#include <stdio.h>
#include <stdlib.h>
#include "flags.h"
#include "interpreter.h"

/**
 * Interprets Brainfuck code.
 */
interpstate_t interpret(interpstate_t *interpstate, flags_t *flags, int *data, char *code)
{
  int wasadot;
  int i = 0;
  int j = 0;

  // for (int i = 0; (code[i] != '\0'); i++)
  while (code[i] != '\0' && j < MAX_ITER)
  {
    switch (code[i])
    {
      case '>':
        if (interpstate->pointer < BUFFER_SIZE)
        {
          interpstate->pointer++;
        }
        break;

      case '<':
        if (interpstate->pointer != 0)
        {
          interpstate->pointer--;
        }
        break;

      case '+':
        if (data[interpstate->pointer] < 256)
        {
          data[interpstate->pointer]++;
        }
        break;

      case '-':
        if (data[interpstate->pointer] > 0)
        {
          data[interpstate->pointer]--;
        }
        break;

      case '.':
        wasadot = 1;

        if (flags == NULL || flags->no_print == 0)
        {
          /* Cast to char to get ASCII char (72='H'). */
          printf("%c", (char)data[interpstate->pointer]);
        }

        break;

      /**
       * Would love to know why this broke
       * out of nowhere and demanded {}.
       */
      case ',':
        {
          int input = 0;
          int c = 0;
          int valid = 0;

          while (!valid)
          {
            printf("  ,: ");
            scanf("%d", &input);
            valid = (input < 0 || input > 255) ? 0 : 1;

            /* Clear input buffer. */
            while ((c = getchar()) != '\n' && c != EOF);
          }

          data[interpstate->pointer] = input;
          break;
        }

      case '[':
        interpstate->loopStart = i;
        break;

      case ']':
        if (data[interpstate->pointer] != 0)
        {
          i = interpstate->loopStart;
        }
        else
        {
          interpstate->loopStart = 0;
        }
        break;

      default:
        break;
    }

    i++; // Position in the code.
    j++; // MAX_ITER count.
  }

  /* Error if MAX_ITER is hit. */
  if (j >= MAX_ITER)
  {
    printf("Max iterations hit! Check for infinite an loop!\n");
    exit(1);
  }

  if (wasadot == 1)
  {
    printf("\n");
  }

  return *interpstate;
}

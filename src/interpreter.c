#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"

/**
 * Interprets Brainfuck code.
 */
interpstate_t interpret(interpstate_t *interpstate, int *data, char *code)
{
  int wasadot = 0;

  for (int i = 0; code[i] != '\0'; i++)
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

        /* Cast to char to get ASCII char (72='H') */
        printf("%c", (char)data[interpstate->pointer]);
        break;

      case ',':
        int input, c;
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
  }

  if (wasadot == 1)
  {
    printf("\n");
  }

  return *interpstate;
}

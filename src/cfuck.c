#include <stdio.h>
#include "interpreter.h"

int main()
{
  /* Initialize data. */
  int data[BUFFER_SIZE];

  /* Initialize interpreters state. */
  interpstate_t interpstate = {
    .pointer = 0,
    .loopStart = 0,
  };

  /* ... */
  return 0;
}


#ifndef INTERPRETER_H
#define INTERPRETER_H
#define BUFFER_SIZE 30000
#define MAX_CODE_LENGTH 5001 /* x chars + NULL terminator. */

/**
 * Represents interpreter data.
 */
typedef struct InterpreterState
{
  int pointer;
  int loopStart;
} interpstate_t;

interpstate_t interpret(interpstate_t *interpstate, int *data, char *code);
#endif /* INTERPRETER_H */


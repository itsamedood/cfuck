#ifndef INTERPRETER_H
#define INTERPRETER_H
#define BUFFER_SIZE 30000

typedef struct InterpreterState {
  int pointer;
  int loopStart;
} interpstate_t;

void interpret(interpstate_t *interpstate, int **data, char *code);
#endif /* INTERPRETER_H */


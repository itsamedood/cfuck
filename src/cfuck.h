#ifndef CFUCK_H
#define CFUCK_H
#include "flags.h"

void sigint_handle(int sig);
void shell(flags_t *flags);
int main(int argc, char **argv);
#endif /* CFUCK_H */


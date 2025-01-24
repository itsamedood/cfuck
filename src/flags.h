#ifndef FLAGS_H
#define FLAGS_H

/* Represents valid flags. */
typedef struct Flags
{
  int verbose;
  int no_print;
  // int help;
  // int version;
} flags_t;

flags_t read_flags(int argc, char **argv);
#endif

#ifndef FLAGS_H
#define FLAGS_H
#define CFUCK_USAGE "Usage: cfuck [-flags] [file-path]"
#define CFUCK_VERSION "0.0.0" // Idk how versioning works lol.

/* Represents valid flags. */
typedef struct Flags
{
  int verbose;
  int no_print;
  // int help;
  // int version;
} flags_t;

flags_t read_flags(flags_t *flags, int argc, char **argv);
#endif

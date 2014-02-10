
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "src/file.h"

int
main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "<filename> required\n");
    exit(1);
  }

  char *name = argv[1];
  char *bytes;
  printf("exists: %s\n", file_exists(name) ? "yes" : "no");
  printf("size: %lld\n", file_size(name));

  bytes = file_read(name);
  if (bytes == NULL) {
    puts(strerror(errno));
    return -1;
  }

  puts(bytes);
  return 0;
}
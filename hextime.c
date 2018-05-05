#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void
print_hextime(bool use_seconds) {
  time_t t = time(NULL);
  struct tm *local = localtime(&t);

  printf("%02X:%02X", local->tm_hour, local->tm_min);

  if (use_seconds)
    printf(":%02X", local->tm_sec);

  printf("\n");
}

static void
print_help(const char *argv0) {
  fprintf(stderr, "Usage: %s [--seconds|-s]\n", argv0);
  exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
  bool use_seconds = false;
  if (argc > 1) {
    if (strcmp(argv[1], "--help") == 0 ||
        strcmp(argv[1], "-h") == 0)
      print_help(argv[0]);

    if (strcmp(argv[1], "--seconds") == 0 ||
        strcmp(argv[1], "-s") == 0)
      use_seconds = true;
  }

  print_hextime(use_seconds);
  return 0;
}

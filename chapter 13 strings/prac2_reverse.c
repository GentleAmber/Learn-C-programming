/*
Write a program named reverse.c that echoes its command-line arguments in 
reverse order. Running the program by typing
reverse void and null
should produce the following output:
null and void
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc <= 1) return 1;

  char **p;
  for (p = &argv[argc-1]; p >= &argv[1]; p--) {
    printf("%s ", *p);
  }
  printf("\n");
  return 0;
}
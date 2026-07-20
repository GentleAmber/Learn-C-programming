#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char t[] = "aaaaa"; 
  char *pt = "aaaaa";

  t[2] = 'b';

  for (int i = 0; i < (int) (sizeof(t) / sizeof(t[0])); i++) {
    printf("%c", t[i]);
  }
  printf("\n");

  for (int i = 0; i < 5; i++) {
    printf("%c", *pt++);
  }

  pt--;
  *pt = 'b'; /* WRONG. String literals are unmodifiable because they are stored read-only */

  return 0;
}
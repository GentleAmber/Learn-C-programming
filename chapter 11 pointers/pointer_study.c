#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p, *q, x = 1;

  p = &x;
  q = p;
  printf("p stores: %p\nq stores: %p\n", p, q);
  return 0;
}
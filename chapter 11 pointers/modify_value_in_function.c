#include <stdio.h>
#include <stdlib.h>

void swap_int(int *p1, int *p2) {
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
int main(void) {
  int x = 1, y = 10, *p1=&x,*p2=&y;
  printf("x=%d, y=%d\n", x, y);

  swap_int(p1, p2);
  printf("after swap: x=%d, y=%d\n", x, y);
  return 0;
}


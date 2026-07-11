#include <stdio.h>
int main(void) {
  int i, j;
  float x, y;

  // for input 10.3 5 6, i will be 10, x will be 0.3, j will be 5
  scanf("%d%f%d", &i, &x, &j);
  printf("i: %d, x: %f, j: %d.", i, x, j);

  // for input 12.3 45.6 789, x will be 12.3, i will be 45, y will be 0.6
  // This only works as expected when the last scanf and printf are commented,
  // otherwise, there will be characters left in the buffer.
  scanf("%f%d%f", &x, &i, &y);
  printf("x: %f, i: %d, y: %f.", x, i, y);
  return 0;
}
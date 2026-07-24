/*
Write a macro NELEMS(a) that computes the number of elements in a one-dimensional
array a.
*/

#include <stdio.h>
#define NELEMS(a) (sizeof(a) / sizeof(a[0]))
int main(void) {
  
  int a[19] = {0};
  printf("a's length: %d\n", NELEMS(a));
  return 0;
}
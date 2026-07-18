/*
Suppose that high, low, and middle are all pointer variables of the same type, and that
low and high point to elements of an array. Why is the following statement illegal, and
how could it be fixed?
middle = (low + high) / 2;

****Attempted answer****
Illegal reason: expression must have integral type.
Arithmetic operations between pointers are illegal. Pointers can only have operations
with variables of the same type

****REAL ANSWER****
It's illegal because pointers cannot be added (the result doesn't have logical meaning
and is supremely large, pointing to somewhere probably out of bound).
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *high = &a[9], *middle, *low = a;

  int diff = high - low;
  middle = low + diff / 2;

  printf("middle=%d\n", *middle);
  return 0;
}
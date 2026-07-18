/*
Write the following function:
int *find_largest(int a[], int n);
When passed an array a of length n, the function will return a pointer to the array’s largest
element.
*/
#include <stdio.h>
#include <stdlib.h>

int *find_largest(int a[], int n);

int main(void) {
  int a[7] = {3, 24, 9, 10, -9, 2, 30};
  int *p = find_largest(a, 7);

  printf("The largest num: %d. Its address: %p\n", *p, p);
  return 0;
}

int *find_largest(int a[], int n) {
  int *p = &a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > *p) {
      *p = a[i];
    }
  }

  return p;
}
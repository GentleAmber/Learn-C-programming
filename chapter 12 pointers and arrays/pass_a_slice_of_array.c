#include <stdio.h>
#include <stdlib.h>

int find_largest(int a[], int n);
int main(void) {
  
  int a[6] = {100, 2, 3, 4, 5, 6};
  int lar = find_largest(&a[1], 5);

  printf("largest: %d\n", lar);
  return 0;
}

int find_largest(int a[], int n) {
  int lar = a[0];
  for (int i = 0; i < n; i++) {
    if (lar < a[i]) {
      lar = a[i];
    }
  }
  return lar;
}
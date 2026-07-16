#include <stdio.h>

// Initially, low should be the index of the first element of an array
void make_zero(int a[], int a_length);

int main(void) {
  int a[10] = {1,1,1,1,1,1,1,1,1,1};
  make_zero(a, 10);
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", a[i]);
  }
  
}

void make_zero(int a[], int a_length) {
  for (int i = 0; i < a_length; i++)
    a[i] = 0;
}
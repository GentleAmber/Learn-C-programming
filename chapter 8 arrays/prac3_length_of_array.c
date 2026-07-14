/*
Modify the reverse.c program of Section 8.1 to use the expression (int)
(sizeof(a) / sizeof(a[0])) (or a macro with this value) for the array length.
*/
#include <stdio.h>
#define SIZE ((int) (sizeof(a) / sizeof(a[0])))
#define LEN 4

int main(void) {
  printf("Enter %d numbers: ", LEN);

  int a[LEN];
  for (int i = 0; i < SIZE; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = SIZE - 1; i >= 0; i--) {
    printf("%d ", a[i]);
  }

  return 0;
}
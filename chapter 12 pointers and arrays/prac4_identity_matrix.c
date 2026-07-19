/*
Section 8.2 had a program fragment in which two nested for loops initialized the array
ident for use as an identity matrix. Rewrite this code, using a single pointer to step
through the array one element at a time.
Original program:
#define N 10
double ident[N][N];
int row, col;
for (row = 0; row < N; row++)
 for (col = 0; col < N; col++)
 if (row == col)
 ident[row][col] = 1.0;
 else
 ident[row][col] = 0.0;

*/

#include <stdio.h>
#include <stdlib.h>
#define N 15

int main(void) {
  double ident[N][N];
  double *p;
  for (p = ident[0]; p < ident[0] + N * N; p++) {
    if ((p - ident[0]) % (N + 1) == 0) {
      *p = 1.0;
    } else
      *p = 0;
  }

  for (double *q = ident[0]; q < ident[0] + N * N; q++) {
    printf("%.0lf ", *q);
    if ((q - ident[0] - (N - 1)) % N == 0) 
      printf("\n");
  }
  printf("\n");

  return 0;
}
/*
Write a program that reads a 5 × 5 array of integers and then prints the row sums and the
column sums:
*/
#include <stdio.h>
#define ROW 5
#define COL 5

int main(void) {
  int a[ROW][COL], row_total[ROW] = {0}, col_total[COL] = {0};
  
  for (int i = 0; i < ROW; i++) {
    printf("Enter row %hd: ", i + 1);
    for (int j = 0; j < COL; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      row_total[i] += a[i][j];
      col_total[j] += a[i][j];
    }
  }
  
  printf("Row totals: ");
  for (int i = 0; i < ROW; i++)
  {
    printf("%d ", row_total[i]);
  }
  printf("\nColumn totals: ");
  for (int i = 0; i < COL; i++)
  {
    printf("%d ", col_total[i]);
  }
  
  return 0;
}

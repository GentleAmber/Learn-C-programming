#include <stdio.h>

int OVERALL_ROW = 6;
int LEFT_ROW = 2;
int LEFT_COLUMN = 2;
int RIGHT_COLUMN = 5;
/*
* Bottom dot takes up 1 column and 1 row
* For OVERALL_ROW = 6, LEFT_ROW = 2, 
* LEFT_COLUMN = 2, RIGHT_COLUMN = 5, 
* the pattern is:
*        *
*       *
*      *
* *   *
*  * *
*   *
*/ 

int main(void) {
  for (int i = 1; i <= OVERALL_ROW; i++) {
    int right_border_column = LEFT_COLUMN + RIGHT_COLUMN + 1 - (i -1);
    for (int j = 1; j <= right_border_column; j++) {
      // Before reaching the starting row of the left part of the tick 
      if (i < OVERALL_ROW - LEFT_ROW) {
        if (j != right_border_column) {
          printf(" ");
        } else {
          printf("*\n");
        }
      // The starting row of the left part of the tick
      } else {
        if (j == i - (OVERALL_ROW - LEFT_ROW) + 1) {
          printf("*");
        } else if (j == right_border_column) {
          printf("*\n");
        } else {
          printf(" ");
        }
      }
    } 
  }

  return 0;
}
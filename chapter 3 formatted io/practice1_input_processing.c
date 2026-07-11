#include <stdio.h>

/**
 * Write a program that accepts a date from the user in the 
 * form mm/dd/yyyy and then displays it in the form yyyymmdd
 */
int main(void) {
  int m, d, y;
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m, &d, &y);

  printf("You entered the date %.4d%.2d%.2d", y, m, d);
  return 0;
}
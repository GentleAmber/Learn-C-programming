/*
Write a program that reads an integer entered by the user and displays it in octal (base 8):
Enter a number between 0 and 32767: 1953
In octal, your number is: 03641
The output should be displayed using five digits, even if fewer digits are sufficient.
*/

#include <stdio.h>

int main(void) {

  int input, remainder;

  printf("Enter a number between 0 and 32767: ");
  scanf("%d", &input);
  remainder = input;

  // Get the base from highest to lowest (max: 8^4, lowest: 8^0) 
  // and calculate the factor for each base
  for (int power = 4; power >= 0; power--) {
    int base = 1;
    for (int j = 1; j <= power; j++) {
      base *= 8;
    }
    printf("%d", remainder / base);
    remainder = remainder %= base;
  }

  return 0;
}
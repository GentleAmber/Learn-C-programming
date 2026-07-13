/*
 Write a program that uses Newton’s method to compute the square root of a positive floating-point number:
Enter a positive number: 3
Square root: 1.73205
Let x be the number entered by the user. Newton’s method requires an initial guess y for the
square root of x (we’ll use y = 1). Successive guesses are found by computing the average of
y and x/y. The following table shows how the square root of 3 would be found:
Note that the values of y get progressively closer to the true square root of x. For greater
accuracy, your program should use variables of type double rather than float. Have the
program terminate when the absolute value of the difference between the old value of y and
the new value of y is less than the product of .00001 and y.
*/

#include <stdio.h>
#include <math.h>

int main(void) {
  double x, y = 1;
  printf("Enter a positive floating number: ");
  scanf("%lf", &x);
  while(fabs(y - (y + x/y) / 2) >= 0.00001 * y) {
    y = (y + x/y) / 2;
  }
  printf("%lf has the square root of: %lf", x, y);
  return 0;
}


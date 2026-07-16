/*
Consider the following “mystery” function:
void pb(int n)
{
 if (n != 0) {
 pb(n / 2);
 putchar('0' + n % 2);
 }
}
Trace the execution of the function by hand. Then write a program that calls the function,
passing it a number entered by the user. What does the function do?

****Answer****
This function prints the binary number of the argument.
*/

#include <stdio.h>

void pb(int n);

int main(void) {
  printf("pb(20):\n");
  pb(20);
  printf("\npb(31):\n");
  pb(31);
  printf("\n");
  return 0;
}

void pb(int n)
{
 if (n != 0) {
 pb(n / 2);
 putchar('0' + n % 2);
 }
}
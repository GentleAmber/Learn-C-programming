/*
Write a program that asks the user to enter a fraction, then reduces the fraction to lowest
terms:
Enter a fraction: 6/12
In lowest terms: 1/2
*/

#include <stdio.h>

int main(void) {
  int numerator, denominator, nume_lowest, deno_lowest, sm, lg, remainder, gcd;
  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  if (numerator > denominator) {
    sm = denominator;
    lg = numerator;
  } else {
    sm = numerator;
    lg = denominator;
  }

  while (sm != 0) {
    remainder = lg % sm;
    lg = sm;
    sm = remainder;
  }

  gcd = lg; 
  nume_lowest = numerator / gcd;
  deno_lowest = denominator / gcd;

  switch (deno_lowest) {
  case 1:
    printf("In lowest terms: %d", nume_lowest);
    break;
  
  default:
    printf("In lowest terms: %d/%d", nume_lowest, deno_lowest);
    break;
  }

  return 0;
}
/*
Modify Programming Project 6 from Chapter 3 so that the user may add, subtract, multiply,
or divide two fractions (by entering either +, -, *, or / between the fractions).

Project 6 from Chapter 3:
Modify the addfrac.c program of Section 3.2 so that the user enters both fractions at the
same time, separated by a plus sign:
Enter two fractions separated by a plus sign: 5/6+3/4
The sum is 38/24
*/

#include <stdio.h>

int main(void) {
  int numerator1, denominator1, numerator2, denominator2, nume_result, deno_result;
  char sign;

  printf("Enter two fractions separated by a sign (e.g, 5/6-1/3): ");
  scanf("%d/%d%c%d/%d", &numerator1, &denominator1, &sign, &numerator2, &denominator2);
  
  switch (sign)
  {
  case '+':
    nume_result = numerator1 * denominator2 + numerator2 * denominator1;
    deno_result = denominator1 * denominator2;
    break;
  case '-':
    nume_result = numerator1 * denominator2 - numerator2 * denominator1;
    deno_result = denominator1 * denominator2;
  case '*':
    nume_result = numerator1 *  numerator2;
    deno_result = denominator1 * denominator2;
    break;
  case '/':
    nume_result = numerator1 * denominator2;
    deno_result = numerator2 * denominator1;
    break;
  default:
    printf("Sign is illegal. Has to be * or / or - or +.");
    return -1;
  }

  if (nume_result < 0)
    printf("The result is -%d/%d", nume_result, deno_result);
  else
  printf("The result is %d/%d", nume_result, deno_result);

  return 0;
}
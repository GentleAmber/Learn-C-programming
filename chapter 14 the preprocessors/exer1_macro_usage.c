/*
Write parameterized macros that compute the following values.
(a) The cube of x.
(b) The remainder when n is divided by 4.
(c) 1 if the product of x and y is less than 100, 0 otherwise.

Do your macros always work? 
If not, describe what arguments would make them fail.
*/

#include <stdio.h>
#include <stdlib.h>
#define CUBE(x) ((x) * (x) * (x))
#define REMAINDER_BY_4(n) ((n) % 4)
#define PRODUCT_LESS_100(x, y) ((x) * (y) < 100 ? 1 : 0)

int main(void) {
  int x = 3, neg_int = -5, y = 34;
  float f = 4.1f;

  printf("cube(%d) = %d\n", x, CUBE(x));
  printf("cube(%d) = %d\n", neg_int, CUBE(neg_int));
  printf("cube(%f) = %f\n", f, CUBE(f));

  printf("%d % 4 = %d\n", neg_int, REMAINDER_BY_4(neg_int));
  printf("%d % 4 = %d\n", x, REMAINDER_BY_4(x));
  // printf("%f % 4 = %f\n", f, REMAINDER_BY_4(f));
  /* Expansions must have int value */

  printf("Is %d * %f less than 100: %d\n", x, f, PRODUCT_LESS_100(x,f));
  printf("Is %d * %d less than 100: %d\n", x, y, PRODUCT_LESS_100(x,y));



  return 0;
}
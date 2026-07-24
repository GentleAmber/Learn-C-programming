#include <stdio.h>
#include <stdlib.h>
#define A 1
/* ## used to concatenate tokens into one */
#define GENERIC_MAX(type) \
type type##_max (type a, type b) { \
  return a > b ? a : b; \
}
/* # used to create string literals */
#define PRINT_INT(n) printf(#n" = %d\n", n); 
/* Create longer Macros */
#define ECHO(s) (gets(s), puts(s))
#define CHECK_ZERO(divisor) \
if (divisor == 0) { \
  printf("Divisor is 0 on line %d in file %s.\n", __LINE__, __FILE__); \
}

GENERIC_MAX(float)
GENERIC_MAX(int)

int main(void) {
  printf("A*2 = %d\n", A*2);
  /* Give A a new define */
  #undef A
  #define A 2
  printf("A*2 = %d\n", A*2);
  
  printf("float_max(1.2, 2.1): %f\n", float_max(1.2, 2.1));
  printf("int_max(1, 4): %d\n", int_max(1, 4));
  
  PRINT_INT(3);

  char str[30], *s=str;
  // ECHO(s);

  int i = 1, j = 0;
  CHECK_ZERO(j);
  // int k = i / j;
  
  return 0;
}
/*
The square2.c program of Section 6.3 will fail (usually by printing strange answers) if
i* i exceeds the maximum int value. Run the program and determine the smallest value
of n that causes failure. Try changing the type of i to short and running the program
again. (Don’t forget to update the conversion specifications in the call of printf!) Then
try long. From these experiments, what can you conclude about the number of bits used to
store integer types on your machine?

Answer:
1) smallest value of n that causes failure: 46341 
2) smallest value of n that causes failure for short int i: 182
3) smallest value of n that causes failure for long int i: 46341

Number of bits on my pc (64-bit) 
for int: 32, 
for short int: 16, 
for long int: 32
*/

#include <stdio.h>

int main(void)
{
  int n;
  long int m;
  // expe_1(n = 46341);
  // expe_2_short_i(n = 256);
  expe_2_long_i(m = 46341l);
  return 0;
}

int expe_1(int n) {
  int i;

  printf("This program prints a table of squares.\n");
  printf("Number of entries in table: %d\n", n);
  for (i = 1; i <= n; i++)
  if (i >= 46200)
    printf("%20d%20d\n", i, i * i);
  return 0;
}

int expe_2_short_i(int n) {
  short int i;

  printf("This program prints a table of squares with short int i.\n");
  printf("Number of entries in table: %d\n", n);
  for (i = 1; i <= n; i++)
    printf("%10hd%10hd\n", i, i * i);
  return 0;
}

int expe_2_long_i(long int n) {
  long int i;

  printf("This program prints a table of squares with long int i.\n");
  printf("Number of entries in table: %ld\n", n);
  for (i = 1; i <= n; i++) {
    if (i < 46200)
      continue;
    printf("%25ld%25ld\n", i, i * i);
  }
  return 0;
}
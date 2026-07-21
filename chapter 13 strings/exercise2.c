/*
Suppose that we call scanf as follows:
scanf("%d%s%d", &i, s, &j);
If the user enters 12abc34 56def78, what will be the values of i, s, and j after the
call?

*** Answer ***
i: 12, *s: "abc34", j: 56
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i,j;
  char input[25], *s = input;

  scanf("%d%s%d", &i, s, &j);
  printf("i: %d, s: %s, j: %d\n", i, s, j);

  return 0;
}
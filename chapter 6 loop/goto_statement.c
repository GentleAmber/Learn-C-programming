#include <stdio.h>
/*
Show how to replace a continue statement by an equivalent goto statement

int sum = 0, i;

  for (i = 0; i < 10; i++) {
    if (i % 2)
      continue;
    sum += i;
    printf("%d", i);
  }
  printf("\nsum: %d\n", sum);
  
  return 0;
*/
int main(void) {
  int sum = 0, i;

  for (i = 0; i < 10; i++) {
    if (i % 2)
      continue;
    sum += i;
    printf("%d", i);
  }
  printf("\nsum: %d\n", sum);
  
  return 0;
  // int sum = 0, i;

  // for (i = 0; i < 10; i++) {
  //   if (i % 2)
  //     goto i_odd;
  //   sum += i;
  //   printf("%d", i);
  //   i_odd: ;
  // }
  // printf("\nsum: %d\n", sum);
  
  // return 0;
}
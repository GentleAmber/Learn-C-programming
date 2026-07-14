#include <stdio.h>
#include <stdbool.h>
/*
Modify the repdigit.c program of Section 8.1 so that it prints a table showing how
many times each digit appears in the number:
Enter a number: 41271092
Digit: 0 1 2 3 4 5 6 7 8 9
Occurrences: 1 2 2 0 1 0 0 1 0 1
*/
int main(void)
{
  short num_list[10] = {0};
  int input;
  printf("Enter a number: ");
  scanf("%d", &input);

  while (input != 0) {
    num_list[input % 10] += 1;
    input /= 10;
  }
  
  printf("Digit:\t  ");
  for (short i = 0; i < 10; i++)
  {
    printf("  %hd", i);
  }
  printf("\nOccurrences:");
  for (short i = 0; i < 10; i++)
  {
    printf("  %hd", num_list[i]);
  }

  return 0;
}
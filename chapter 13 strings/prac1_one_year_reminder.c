/*
Improve the remind.c program of Section 13.5 in the following ways:

(a) Have the program print an error message and ignore a reminder if the corresponding
day is negative or larger than 31. Hint: Use the continue statement.
(b) Allow the user to enter a day, a 24-hour time, and a reminder. The printed reminder list
should be sorted first by day, then by time. (The original program allows the user to
enter a time, but it’s treated as part of the reminder.)
(c) Have the program print a one-year reminder list. Require the user to enter days in the
form month/day.
*/

#include <stdio.h>
#include <stdlib.h>
#define LEN_INPUT 150
#define LEN_LIST 3285

int main(void) {
  char in[LEN_LIST][LEN_INPUT + 1], *end_program = "0";
  int i = 0;

  for (; i < LEN_LIST; i++) {
    char temp[LEN_INPUT + 1];
    printf("Enter day and reminder: ");
    read_input(temp, LEN_INPUT);

    if (strcmp(temp, end_program) == 0) {
      break;
    } 
    
    strcpy(in[i], temp);
  }

  sort_string(in, i);

  printf("Day Reminder\n");
  for (int j = 0; j < i; j++) {
    for (int q = 0; q < LEN_INPUT + 1; q++) {
      if (in[j][q] != '\0') {
        printf("%c", in[j][q]);
      } else {
        printf("\n");
        break;
      }
    }
  }

  return 0;
}
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
#include <string.h>
#define MSG_LEN 150
#define LIST_LEN 3285

void read_line(char str[], int n);
void clear_buffer(char str[], int n);
void sort_reminder(char str[][MSG_LEN + 1], int n);

int main(void) {
  char reminder_list[LIST_LEN][MSG_LEN + 1], *end_program = "0", 
  temp[MSG_LEN + 1];
  int i = 0;

  for (; i < LIST_LEN; i++) {
    printf("Enter datetime (mm/dd hh:mm) and reminder: ");
    clear_buffer(temp, MSG_LEN + 1);
    read_line(temp, MSG_LEN);

    if (strcmp(temp, end_program) == 0) {
      break;
    } 
    
    strcpy(reminder_list[i], temp);
  }

  sort_reminder(reminder_list, i);

  printf("Year Reminder\n");
  for (int j = 0; j < i; j++) {
    for (int q = 0; q < MSG_LEN + 1; q++) {
      if (reminder_list[j][q] != '\0') {
        printf("%c", reminder_list[j][q]);
      } else {
        printf("\n");
        break;
      }
    }
  }

  return 0;
}

void read_line(char str[], int n) {
  /*
  datetime from index 0 to 3: month, day, hour, minute
  */
  int datetime[4] = {0};
  char datetime_str[4][3], datetime_sentence[13], c, *p;
  clear_buffer(datetime_sentence, 13);
  // Reading date time info and eat all the white spaces afterwards
  scanf("%d/%d %d:%d ", &datetime[0], &datetime[1], &datetime[2], &datetime[3]);
  if (datetime[0] == 0) {
    strcpy(str, "0");
    return;
  }
  // Left padding the numbers and transform them into strings
  for (int i = 0; i < 4; i++) {
    sprintf(datetime_str[i], "%.2d", datetime[i]);
  }

  strcat(datetime_sentence, datetime_str[0]);
  strcat(datetime_sentence, "/");
  strcat(datetime_sentence, datetime_str[1]);
  strcat(datetime_sentence, " ");
  strcat(datetime_sentence, datetime_str[2]);
  strcat(datetime_sentence, ":");
  strcat(datetime_sentence, datetime_str[3]);
  strcat(datetime_sentence, " ");

  strcpy(str, datetime_sentence);
  
  // Till now, str has 12 characters (including white space) and a NULL as the 13th.
  // Let p point at str[12] (the 13th) so that p could continue writing the input
  for (p  = &str[12]; p < str + n; p++) {
    if ((c = getchar()) != '\n' && c != EOF) {
      *p = c;
    } else {
      break;
    }
  }
  *p = '\0';
}

void clear_buffer(char str[], int n) {
  for (int i = 0; i < n; i++) {
    str[i] = '\0';
  }
}

void sort_reminder(char str[][MSG_LEN + 1], int n) {
  if (n <= 1) {
    return;
  }

  char (*large)[MSG_LEN + 1] = str[0], (*p)[MSG_LEN + 1] = str[1],
  temp[1][MSG_LEN + 1];

  for (; p < str + n; p++) {
    if (strncmp(*large, *p, 12) < 0) {
      large = p;
    }
  }

  if (large != str + n - 1) {
    strcpy(temp[0], str[n - 1]);
    strcpy(str[n - 1], large);
    strcpy(large, temp[0]);
  }

  sort_reminder(str, n - 1);
}
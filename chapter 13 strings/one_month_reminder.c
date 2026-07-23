/*
Printing a One-Month Reminder List

To illustrate the use of the C string library, we’ll now develop a program that prints
a one-month list of daily reminders. The user will enter a series of reminders, with
each prefixed by a day of the month. When the user enters 0 instead of a valid day,
the program will print a list of all reminders entered, sorted by day. Here’s what a
session with the program will look like:
Enter day and reminder: 24 Susan's birthday
Enter day and reminder: 5 6:00 - Dinner with Marge and Russ
Enter day and reminder: 26 Movie - "Chinatown"
Enter day and reminder: 7 10:30 - Dental appointment
Enter day and reminder: 12 Movie - "Dazed and Confused"
Enter day and reminder: 5 Saturday class
Enter day and reminder: 12 Saturday class
Enter day and reminder: 0

Day Reminder
 5 Saturday class
 5 6:00 - Dinner with Marge and Russ
 7 10:30 - Dental appointment
 12 Saturday class
 12 Movie - "Dazed and Confused"
 24 Susan's birthday
 26 Movie - "Chinatown"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN_INPUT 150
#define LIST_LEN 300 

/* Read a full sentence into @in. @input_len represents the maximum number of characters
   in a sentence. */
void read_input(char in[], int input_len);
/* Sort @str so that reminders are ordered from the smallest date to the biggest */
void sort_string(char str[][LEN_INPUT + 1], int n);

int main(void) {
  char in[LIST_LEN][LEN_INPUT + 1];
  int i = 0;

  for (; i < LIST_LEN; i++) {
    char *end_program = "0\0", temp[LEN_INPUT + 1];
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

void read_input(char in[], int input_len) {
  int i = 0;

  /*
  Improvements: could use scanf("%2d", &day); to get the date for comparison in 
  an easier way.
  */
  for (; i < input_len; i++) {
    char c;
    if ((c = getchar()) == '\n') {
      in[i] = '\0';
      break;
    } else {
      in[i] = c;
    }
  }

  if (i == input_len - 1 && in[i] != '\0') {
    in[++i] = '\0';
  }
}

void sort_string(char str[][LEN_INPUT + 1], int n) {

  if (n <= 1) return;

  // *lar and *p both have the type of char (*)[LEN_INPUT + 1]. temp is an 
  // array with the space for one row of str.
  char (*lar)[LEN_INPUT + 1] = str, temp[1][LEN_INPUT + 1], 
  (*p)[LEN_INPUT + 1];

  for (p = str; p - str < n; p++) {
    short ifLarger = 0;

    // lar has only one digit as date
    if (lar[0][1] == ' ') {
      // if p has two digits as date, p is larger
      if (p[0][1] != ' ') {
        ifLarger = 1;
        // otherwise if they both have only one digit and p's number is larger, p is 
        // larger
      } else if (lar[0][0] < p[0][0]) {
          ifLarger = 1;
      }
    // lar has two digits, then p has to have two digits to be larger
    } else {
      if (p[0][1] != ' ') {
        if (p[0][0] > lar[0][0]) {
          ifLarger = 1;
        } else if (p[0][0] == lar[0][0] && p[0][1] > lar[0][1]) {
          ifLarger = 1;
        }
      }
    }

    // If p is pointing at a larger date, record the address
    if (ifLarger) {
      lar = p;
    }
  }

  // If the largest date is not the last element of the array, swap
  if (lar - str != n - 1) {
    for (int i = 0; i < LEN_INPUT + 1; i++) {
      temp[0][i] = str[n-1][i];
      str[n-1][i] = lar[0][i];
      lar[0][i] = temp[0][i];
    }
  }

  // Recursively sort until the array is in order
  sort_string(str, n - 1);
}
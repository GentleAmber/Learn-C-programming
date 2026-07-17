/*
Write a program that prompts the user for a number and then displays the number, using
characters to simulate the effect of a seven-segment display:
Enter a number: 491-9014
 _ _ _
|_| |_| | |_| | | | |_|
 | _| | _| |_| | |
Characters other than digits should be ignored. Write the program so that the maximum
number of digits is controlled by a macro named MAX_DIGITS, which has the value 10. If
the number contains more than this number of digits, the extra digits are ignored.

******Analysis******
There are 3 rows (lines), 4 columns (spaces) for one segment-displayed digit. 
Use array1 to store permanent correspondence relation between number and digit display.
Use array2 to store info of columns for one row, and go through each row one by one.
There should also be a space between two digits.

  _0
5|_|1
4|_|2
  3
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITS 10

void clear_digits_array(void);
void process_digit(short position[], short length);
void print_digits_array(void);

/* segments: stores the correspondence between digits and segments */
const short segments[10][7] = 
{
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {[1] = 1, [2] = 1}, // 1
  {[0] = 1, [1] = 1, [3] = 1, [4] = 1, [6] = 1}, // 2
  {[0] = 1, [1] = 1, [6] = 1, [2] = 1, [3] = 1}, // 3
  {[5] = 1, [6] = 1, [1] = 1, [2] = 1}, // 4
  {1, [5]= 1, [6] = 1, [2] = 1, [3] = 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1} // 9 
};
/* digits: stores the column characters for all three row */
char digits[3][MAX_DIGITS][3]; 

int main(void) {
  short position[MAX_DIGITS];
  printf("Enter a number: ");
  int i;
  for (i = 0; i < MAX_DIGITS; ) {
    char c;

    c = getchar();
    if (c == '\n') break;
    else if (c >= 48 && c <= 57){
      position[i] = c - '0';
      i++;
    }
  }

  process_digit(position, i);
  print_digits_array();
  return 0;
}

void clear_digits_array(void){
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < MAX_DIGITS; j++) {
      for (int n = 0; n < 3; n++) {
        digits[i][j][n] = ' ';
      }
    }
  }
}

void process_digit(short position[], short length) {
  // Process digits row by row
  for (int i = 0; i < 3; i++) {
    // For the first row, check if segment 0 (top border) is displayed
    if (i == 0) {
      for (int j = 0; j < length; j++) {
        short digit = position[j];
        if (segments[digit][0]) {
          digits[i][j][0] = ' ';
          digits[i][j][1] = '_';
          digits[i][j][2] = ' ';
        } else {
          digits[i][j][0] = ' ';
          digits[i][j][1] = ' ';
          digits[i][j][2] = ' ';
        }
      }
    // For the second row, check if segment 5, 6, 1 is displayed
    } else if (i == 1) {
      for (int j = 0; j < length; j++) {
        short digit = position[j];
        if (segments[digit][5]) {
          digits[i][j][0] = '|';
        } else {
          digits[i][j][0] = ' ';
        }
        
        if (segments[digit][6]) {
          digits[i][j][1] = '_';
        } else {
          digits[i][j][1] = ' ';
        }

        if (segments[digit][1]) {
          digits[i][j][2] = '|';
        } else {
          digits[i][j][2] = ' ';
        }
      }
    // For the third row, check if segment 4,3,2 is displayed
    } else if (i == 2) {
      for (int j = 0; j < length; j++) {
        short digit = position[j];

        if (segments[digit][4]) {
          digits[i][j][0] = '|';
        } else {
          digits[i][j][0] = ' ';
        }

        if (segments[digit][3]) {
          digits[i][j][1] = '_';
        } else {
          digits[i][j][1] = ' ';
        }

        if (segments[digit][2]) {
          digits[i][j][2] = '|';
        } else {
          digits[i][j][2] = ' ';
        }
      }
    }
  }
}

void print_digits_array(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < MAX_DIGITS; j++) {
      for (int n = 0; n < 3; n++) {
        printf("%c", digits[i][j][n]);
      }
      printf(" ");
    }
    printf("\n");
  }
}

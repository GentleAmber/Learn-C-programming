/*
Modify the read_line function in each of the following ways:

(a) Have it skip white space before beginning to store input characters.
(b) Have it stop reading at the first white-space character. Hint: To determine whether or
not a character is white space, call the isspace function.
(c) Have it stop reading at the first new-line character, then store the new-line character in
the string.
(d) Have it leave behind characters that it doesn’t have room to store.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 100

/* Stores the line (max char: @n) into @str. Returns the number of characters - 1. */
int read_line(char str[], int n);

int main(void) {
  char str[MAX_LEN + 1];
  printf("Enter a line: ");

  int len = read_line(str, MAX_LEN);
  printf("You entered: ");
  for (int i = 0; i <= len; i++) {
    printf("%c", str[i]);
  }
  printf("\n");

  printf("Character length: %d\n", len);
  return 0;
}

/* ver (a): skip white space (including new line) before beginning to store input */
// int read_line(char str[], int n) {
//   char c;
//   int i = 0;
//   for (; i < n; i++) {
//     // if c doesn't hit the end of line, read and store
//     if ((c = getchar()) != '\n' && c != EOF) {
//       // if therre is whitespace at the beginning, read and discard them
//       if (i == 0 && isspace(c)) {
//         while (isspace(c)) {
//           c = getchar();
//         }
//       }
//       str[i] = c; 
//     } else {
//       str[i] = '\0';
//       break;
//     }  
//   }

//   if (i == n && str[i] != '\0') {
//     str[n] = '\0';
//   }

//   return i;
// }

/* ver (b): Have it stop reading at the first white-space character */
// int read_line(char str[], int n) {
//   char c;
//   int i = 0;

//   for (; i < n; i++) {
//     // Stops reading for either of the condition
//     if (isspace(c = getchar()) || c == EOF) {
//       str[i] = '\0';
//       break;
//     } else {
//       str[i] = c;
//     }
//   }

//   if (i == n && str[i] != '\0') {
//     str[n] = '\0';
//   }

//   return i;
// }

/* ver (c): Have it stop reading at the first new-line character, then store the new-line character in
the string*/
int read_line(char str[], int n) {
  int i; 
  char c;
  for (; i < n; i++) {
    if ((c = getchar()) != EOF) {
      str[i] = c;
      if (c == '\n') {
        str[++i] = '\0';
        break;
      }
    }
  }

  if (i == n) {
    str[i] = '\0';
  }

  return i;
}

/* ver (d): this is achieved in every implementation. */
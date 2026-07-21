/*
Write a function named censor that modifies a string by replacing every occurrence of
foo by xxx. For example, the string "food fool" would become "xxxd xxxl". Make
the function as short as possible without sacrificing clarity.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* @str: string to be manipulated
   @n: number of characters in @str (excluding '\0' ) */
void censor(char str[], int n);
int main(int argc, char *argv[]) {
  
  if (argc <= 1) return 1;
  else {
    char str[30];
    strcpy(str, argv[1]);
    int n = strlen(str);
    censor(str, n);
    for (int i = 0; i < n; i++) {
      printf("%c", str[i]);
    }
    printf("\n");
  }
  return 0;
}

void censor(char str[], int n) {
  char *p = str, *q;

  // Go through the str until hit NULL
  while (*p++) {
    if (*p == 'f' && p - str <= n -3) {
      q = p;
      for (p = q + 1; p <= q + 2; p++) {
        if (*p != 'o') {
          break;
        } else if (p == q + 2) {
          //use *q to replace the word
          for (; q <= p; q++) {
            *q = 'x';
          }
        } 
      }
    }
  }
}
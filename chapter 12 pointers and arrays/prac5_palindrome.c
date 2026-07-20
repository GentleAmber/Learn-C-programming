/*
Write a program that reads a message, then checks whether it’s a palindrome (the letters
in the message are the same from left to right as from right to left)

Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome

use pointers instead of integers to keep track of positions in the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 100

int main(void) {
  char sentence[MAX_LEN], *p = sentence, input;
  printf("Enter a message: ");

  while ((input = getchar()) != '\n') {
    
    if (p - sentence < MAX_LEN) {
      if ((input >= 'A' && input <= 'Z') || input >= 'a' && input <= 'z') {
        input = toupper(input);
        *p++ = input;
      }
    } else {
      printf("array out of bound.");
      exit(1);
    }
  }

  int half = (p - sentence) / 2;
  p--; // calibrate p back to the end of the sentence
  for (char *q = sentence; q < sentence + half; q++, p--) {
    if (*q != *p) {
      printf("Not a palindrome");
      return 0;
    }
  }
  printf("Palindrome");

  return 0;
}

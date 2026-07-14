/*
Modify Programming Project 11 from Chapter 7 so that the program labels its output:
Enter a first and last name: Lloyd Fosdick
You entered the name: Fosdick, L.
The program will need to store the last name (but not the first name) in an array of characters
until it can be printed. You may assume that the last name is no more than 20 characters long.
*/

#include <stdio.h>
#define LEN 21 // leave one more space for '\n' which will be read by getchar()

int main(void) {

  char last_name[LEN], letter, temp;

  // Store the first letter of the first name and also consume the whitespace
  printf("Enter a first and last name: ");
  for(int i = 0; ; i++) {
    temp = getchar();
    if (i == 0)
      letter = temp;
    if (temp == ' ')
      break;
  }

  // Read the last name and store the '\n' as the last element
  short i;
  for (i = 0; i < LEN; i++) {
    if ((last_name[i] = getchar()) == '\n') 
      break;
  }

  printf("You entered the name: ");
  for (int j = 0; j < i; j++) {
    printf("%c", last_name[j]);
  }
  printf(", %c", letter);

  return 0;
}
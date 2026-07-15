/*
Write a program that reverses the words in a sentence:
Enter a sentence: you can cage a swallow can't you?
Reversal of sentence: you can't swallow a cage can you?
*/

#include <stdio.h>

int main(void) {

  char a[200], l;
  short i = 0, whitespace_mark;
  printf("Enter a sentence: ");
  
  do {
    l = getchar();
    a[i] = l;
    i++;
  } while (l != '.' && l != '?' && l != '!');

  printf("Reversal of sentence: ");
  short j = i - 2; // i: empty element, i - 1: end of sentence (? or ! or .)
  // print words from end to beginning except first word (because no space is
  // in front of the first word)
  for (; j >= 0; j--) {
    if (a[j] == ' ') {
      whitespace_mark = j;
      j++;
      while (j < i - 1 && a[j] != ' ') {
        printf("%c", a[j]);
        j++;
      }
      j = whitespace_mark;
      printf(" ");
    }
  }

  // Print the first word and the end of sentence sign
  while (a[j] != ' ') {
    printf("%c", a[j]);
    j++;
  }
  printf("%c\n", a[i - 1]);

  return 0;
}
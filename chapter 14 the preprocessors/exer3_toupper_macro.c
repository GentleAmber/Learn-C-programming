#include <stdio.h>
#include <string.h>
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
#define verB

int main(void) {
  char str[5], *s = str;
  int i;

  /* 
  verA runs ++i for 3 times. The 1st and 2nd times are in the 
  condition, the 3rd in the return value
  */
  #if defined verA
  strcpy(s, "abcd");
  i = 0;
  putchar(TOUPPER(s[++i]));
  #endif 

  /*
  verB runs ++i 2 times, because when the first bit 'a'<=(c) is false,
  (c)<='z' doesn't get run due to short circuited &&.
  */
  #if defined verB
  strcpy(s, "0123");
  i = 0;
  putchar(TOUPPER(s[++i]));
  #endif
  return 0;
}
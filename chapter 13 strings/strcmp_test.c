#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char d1[3], d2[3];
  printf("Enter a date: ");
  scanf("%2s", d1);
  printf("Enter a date: ");
  scanf("%2s", d2);

  printf("d1: ");
  for (int i = 0; i < 2; i++) {
    printf("%c", d1[i]);
  }
  printf("\nd2: ");
  for (int i = 0; i < 2; i++) {
    printf("%c", d2[i]);
  }
  printf("\nd1 is smaller than d2: %s", strcmp(d1, d2) < 0 ? "true" : "false");
  return 0;
}
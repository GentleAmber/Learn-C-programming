/*
Improve the planet.c program of Section 13.7 by having it ignore 
case when comparing command-line arguments with strings in the planets array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  if (argc <= 1) return 1;
  char *planets[] = {"mercury", "venus", "earth",
  "mars", "jupiter", "saturn",
  "uranus", "neptune", "pluto"};

  char **p, *q, arg_to_lower[10];
  int j;

  for (p = &argv[1]; *p != NULL; p++) {
    for (int i = 0; i < 9; i++) {
      for (q = *p, j = 0; *q; q++, j++) {
        arg_to_lower[j] = tolower(*q);
      }
      arg_to_lower[j] = '\0';
      if (strcmp(planets[i], arg_to_lower) == 0) {
        printf("%s is planet %d\n", *p, i + 1);
        break;
      } else if (i == 8) {
        printf("%s is not a planet\n", *p);
      }
    }
  }

  return 0;
}
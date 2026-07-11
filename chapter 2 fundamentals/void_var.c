#include <stdio.h>

// Global int/float vars that are not initialised always have the value of 0 
int a, b, c;
float d, e;

int main(void)
{
  int f, g, h;
  float i, j;
  printf("--------- Global vars ---------\n");
  printf("gloabal int a: %d\n", a);
  printf("gloabal int b: %d\n", b);
  printf("gloabal int c: %d\n", c);
  printf("gloabal float d: %f\n", d);
  printf("gloabal float e: %f\n", e);

  printf("\n--------- Local vars ---------\n");
  printf("gloabal int f: %d\n", f);
  printf("gloabal int g: %d\n", g);
  printf("gloabal int h: %d\n", h);
  printf("gloabal float i: %f\n", i);
  printf("gloabal float j: %f\n", j);

  return 0;
}

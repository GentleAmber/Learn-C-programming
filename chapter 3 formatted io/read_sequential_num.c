#include <stdio.h>

int main(void) {
  int i, j;
  float x, y;
  // scanf omits white spaces and new lines when looking for numbers
  // which means an input like the following is valid:
  // 54    
  //    2341  
  //      3.4
  // -4.32 
  
  // scanf can back up a step when encountered characters that are not 
  // supposed to be in the current conversion specification.
  // So the following input is also valid: 1-20.3-4.0e3
  // e.g. scanf reads 1, and then -, realising - cannot be in the middle of an int,
  // it goes back to 1 and stores the value in i, then goes on reading.
  scanf("%d%d%f%f", &i, &j, &x, &y);
  printf("%d %d %f %f", i, j, x, y);
  return 0;
}
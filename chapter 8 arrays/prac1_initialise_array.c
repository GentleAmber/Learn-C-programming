#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  bool week[7] = {[0]= true, [6]= true};
  for (short i = 0; i < 7; i++)
  {
    printf("%s\t", week[i] ? "true" : "false");
  }
  
}
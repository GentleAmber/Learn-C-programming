/* Prints int and float values in various formats */
#include <stdio.h>
int main(void)
{
 int i;
 float x;
 i = 40;
 x = 839.214f;
 printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
 printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);

 printf("%12.5e\n", 30.253);
 printf("%.4f\n", 83.162);
 printf("%6.2g\n", .0000009979);

 printf("-------------\n");
 // Exponential notation; left-justified in a field of size 8; one digit after the decimal point
 printf("%-8.1e\n", x);
 // Exponential notation; right-justified in a field of size 10; six digits after the decimal point
 printf("%10.6e\n", x);
 return 0;
}

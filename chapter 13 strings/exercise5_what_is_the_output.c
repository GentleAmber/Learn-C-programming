/* Answer: Grinch (the loop makes every character in s decrease by one) */

#include <stdio.h>
int main(void)
{
 char s[] = "Hsjodi", *p;

 for (p = s; *p; p++)
 --*p;
 puts(s);
 return 0;
}

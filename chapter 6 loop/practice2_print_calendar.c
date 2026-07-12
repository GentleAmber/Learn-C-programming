/*
Write a program that prints a one-month calendar. The user specifies the number of days in
the month and the day of the week on which the month begins:
Enter number of days in month: 31
Enter starting day of the week (1=Sun, 7=Sat): 3
      1  2  3  4  5
6  7  8  9  10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31
*/

#include <stdio.h>

int main(void) {
  int days, starting_day, days_in_first_week;

  printf("Enter number of days in month: ");
  scanf("%d", &days);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &starting_day); 

  days_in_first_week = 8 - starting_day;

  printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\t\n");
  int i, day;
  for (i = 1, day = 1; day <= days; i++) {
    if (i <= 7 - days_in_first_week) 
      printf("\t");
    else if (i % 7 == 0) {
      printf("%d\n", day);
      day++;
    } else {
      printf("%d\t", day);
      day++;
    }
  }
  return 0;
}
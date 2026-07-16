/*
Write a function day_of_year(month, day, year) that returns the day of the year
(an integer between 1 and 366) specified by the three arguments.
*/
#include <stdio.h>

int day_of_year(short month, short day, short year);

int main(void) {
  short month, day, year;

  printf("Enter month, day, year in the format of \"mm dd year\": ");
  scanf("%hd%hd%hd", &month, &day, &year);
  printf("This day is the %dth day of year %hd\n", day_of_year(month, day, year), year);
  
  return 0;
}

int day_of_year(short month, short day, short year) {
  short days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  // centuries that are divisible by 400 are leap year, otherwise, 
  // years that are divisible by 4 are leap year
  if ((year % 100 == 0 && year % 400 == 0) || year % 4 == 0) {
    days_in_months[1] = 29;
  }

  if (month == 1) {
    return day;
  } else {
    month -= 2;
    for (; month >= 0; month--) {
      day += days_in_months[month];
    }
    return day;
  }
}
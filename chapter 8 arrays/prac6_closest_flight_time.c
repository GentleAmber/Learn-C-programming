/*
Modify Programming Project 8 from Chapter 5 so that the departure times are stored in an
array and the arrival times are stored in a second array. (The times are integers, representing
the number of minutes since midnight.) The program will use a loop to search the array of
departure times for the one closest to the time entered by the user.

*********** Project 8 from Chapter 5 ***********
The following table shows the daily flights from one city to another:
Departure time Arrival time
 8:00 a.m. 10:16 a.m.
 9:43 a.m. 11:52 a.m.
 11:19 a.m. 1:31 p.m.
 12:47 p.m. 3:00 p.m.
 2:00 p.m. 4:08 p.m.
 3:45 p.m. 5:55 p.m.
 7:00 p.m. 9:20 p.m.
 9:45 p.m. 11:58 p.m.
Write a program that asks user to enter a time (expressed in hours and minutes, using the 24-
hour clock). The program then displays the departure and arrival times for the flight whose
departure time is closest to that entered by the user:
Enter a 24-hour time: 13:15
Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
*/

#include <stdio.h>
#define LEN 8

int main(void) {
  int departure[LEN] = {8*60, 9*60+43, 11*60+19, 12*60+47, 14*60, 15*60+45, 19*60, 21*60+45};
  int arrival[LEN] = {10*60+16, 11*60+52, 13*60+31, 15*60, 16*60+8, 17*60+55, 21*60+20, 23*60+58};
  int input_h, input_m, input_in_min, difference = 9999;
  short index;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_h, &input_m);

  input_in_min = input_h * 60 + input_m;
  for (int i = 0; i < LEN; i++)
  {
    if (departure[i] - input_in_min < difference && departure[i] - input_in_min > 0) {
      difference = departure[i] - input_in_min;
      index = i;
    }
  }
  
  int dep_h = departure[index] / 60, dep_m = departure[index] % 60,
  arr_h = arrival[index] / 60, arr_m = arrival[index] % 60;
  char dep_c, arr_c;
  if (dep_h > 12) {
    dep_h -= 12;
    dep_c = 'p';
  } else if (dep_h == 12) {
    dep_c = 'p';
  } else {
    dep_c = 'a';
  }

  if (arr_h > 12) {
    arr_h -= 12;
    arr_c = 'p';
  } else if (arr_h == 12) {
    arr_c = 'p';
  } else {
    arr_c = 'a';
  }

  printf("Closest departure time is %.1d:%.2d %c.m., arriving at %.1d:%.2d %c.m.",
  dep_h, dep_m, dep_c, arr_h, arr_m, arr_c);
  return 0;
}
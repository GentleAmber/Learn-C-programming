/*
Quicksort
Let’s develop a recursive function named quicksort that uses the Quicksort
algorithm to sort an array of integers. To test the function, we’ll have main read 10
numbers into an array, call quicksort to sort the array, then print the elements
in the array:
Enter 10 numbers to be sorted: 9 16 47 82 4 66 12 3 25 51
In sorted order: 3 4 9 12 16 25 47 51 66 82
*/

#include <stdio.h>

// Initially, low should be the index of the first element of an array
void split(int a_length, int low, int high);
int a[10];

int main(void) {

  printf("Enter 10 numbers to be sorted: ");
  for(int i = 0; i < 10; i++) {
    scanf("%d", &a[i]);
  }

  split(10, 0, 9);

  for(int i = 0; i < 10; i++) {
    printf("%d\t", a[i]);
  }
  return 0;
}

void split(int a_length, int low, int high) {
  int par_num = a[low];
  short par_index = low;

  // If the length of array is 1, no need to sort
  if (low >= high) {
    return;
  }

  while(low < high) {
    // Wherever the hole (par_index) is, leave the according pointer (low/high) still
    // and compare the other pointer with par_num. If the position is right (e.g., 
    // number pointed by low is lower than par_num, let the pointer keep moving, otherwise
    // put the moving pointer's number to the hole).
    // Only when low == high, fill the par_num in that spot.
    if (par_index == low) {
      if (a[high] < par_num) {
        a[low] = a[high];
        low++;
        par_index = high;
      } else {
        high--;
      }
    } else if (par_index == high) {
      if (a[low] > par_num) {
        a[high] = a[low];
        high--;
        par_index = low;
      } else {
        low++;
      }
    }
  }

  // Now low == high. Fill the par_num back into the hole.
  a[low] = par_num;
  
  // Then start sorting the array on the hole's left and the array on the right
  split(low, 0, low - 1);//这里的第二个参数绝不是0.是什么明天再想想
  split(a_length - low - 1, low + 1, a_length - 1);
}
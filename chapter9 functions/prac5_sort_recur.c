/*
Write a program that asks the user to enter a series of integers (which it stores in an array),
then sorts the integers by calling the function selection_sort. When given an array
with n elements, selection_sort must do the following:
1. Search the array to find the largest element, then move it to the last position in the array.
2. Call itself recursively to sort the first n – 1 elements of the array.
*/
#include <stdio.h>

void selection_sort(int arr[], int arr_length);

int main(void) {

  // For speed, an initialised array is used rather than user input.
  int arr[21] = 
  {0, 32, -1, 0, 5,
  90, 2112, 42, 32, 1,
  92, 67, 92, 13, 12,
  -95, 12, 43, 12, 73, 81};

  selection_sort(arr, 21);
  
  for (int i = 0; i < 21; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

void selection_sort(int arr[], int arr_length) {

  // The last call of function in the recursive chain
  if (arr_length == 1) return;

  int largest_index = 0, largest = arr[0], temp;
  for (int i = 1; i < arr_length; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
      largest_index = i;
    }
  }
  if (largest_index < arr_length - 1) {
    temp = arr[arr_length - 1];
    arr[arr_length - 1] = largest;
    arr[largest_index] = temp;
  }

  selection_sort(arr, arr_length - 1);
}
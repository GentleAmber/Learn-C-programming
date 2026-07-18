#include <stdio.h>
#include <stdlib.h>

/* This function finds the largest and second largest elements in @a, and
 * stores them with the pointers. */

void find_two_largest(int a[], int n, int *largest,
int *second_largest);

int main(void) {
  
  int a[10] = {903, 2039, 4892, 23, 10, -23, 4903, 8291, 3829, 1234};
  for (int i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  int *largest = &a[0], *second_largest = &a[9];
  printf("[main] : *largest contains address for a[0], which is: %p\n", largest);
  printf("[main] : *largest's own address: %p\n", &largest);

  find_two_largest(a, 10, largest, second_largest);
  printf("The largest num: %d. The second largest num: %d.\n", *largest,
  *second_largest);

  return 0;
}

void find_two_largest(int a[], int n, int *largest,
int *second_largest) {
  printf("[find_two_largest] : *largest contains address for a[0], which is: %p\n", largest);
  printf("[find_two_largest] : *largest's own address: %p\n", &largest);

  for (int i = 0; i < n; i++) {
    if (a[i] > *largest) {
      *largest = a[i];
      /* largest = &a[i]; wouldn't work because what's passed as a pointer is the address
      (as the value of the pointer), and this value of address is stored at a different 
      address in the function, with the original pointer untouched.*/
    } else if (a[i] > *second_largest){
      *second_largest = a[i];
    }
  }
}
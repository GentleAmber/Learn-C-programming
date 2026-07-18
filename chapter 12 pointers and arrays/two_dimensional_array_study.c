#include <stdio.h>
#include <stdlib.h>

void print_address(int a[][3], int n);
void print_nth_row(int a[][3], int row);
void print_nth_column(int a[][3], int n, int col);
int main(void) {
  
  int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  printf("size of an array element: %zu\n", sizeof(a[0][0]));
  // print_address(a, 3);
  print_nth_column(a, 3, 1); // expecting: 2, 5, 8
  // print_nth_row(a, 2); //expecting: 7, 8, 9


  return 0;
}

void print_address(int a[][3], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      printf("a[%d][%d]'s address: %p\n", i, j, &a[i][j] );
    }
  }
}

void print_nth_row(int a[][3], int row) {
  int *p;
  printf("%dth row of the array: ", row);
  /* a[row] is the pointer to the start of that row of a[][] */
  for (p = a[row]; p < a[row] + 3; p++) {
    printf("%d, ", *p);
  }
  printf("\n");
}

void print_nth_column(int a[][3], int n, int col){
  printf("%dth columns of the array: \n", col);
  // Initially let p points to the @col th column of first row
  // Every loop when p++, p points to the same column in the next row

  // Textbook method
  // declares p as a pointer to an array of 3 ints (so that p++ makes the value 
  // change by 12, and (*p)[col] could also work)
  int (*p)[3];

  // a[0] stores &a[0][0]. p stores &a[0], so *p == a[0]
  for (p = &a[0]; p < &a[n]; p++) {
    printf("%d, ", (*p)[col]);
    printf("value in p: %p\n", p);
  }
  // Original method 
  // for (int *p = a[0] + col; p < a[0] + col + 3 * n; p += n) {
  //   printf("%d ", *p);
  // }
  printf("\n");
}
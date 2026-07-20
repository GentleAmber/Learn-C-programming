#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int arr[3][2] = {{1, 8}, {9, 0}, {6, 5}}, (*lar)[2], temp[1][2], (*p)[2], lar_index;

  lar = arr;
  for (p = arr; p - arr < 3; p++) {
    /* Mistake-prone： use p[0] rather than p[0][0]. Mind that p[0] dereferences to an array, not a scalar */
    /* *(p + i) will mean p advances i * sizeof(int[2]), not p advances i * sizeof(int) */
    if (p[0][0] > lar[0][0]) {
      lar_index = p - arr;
      lar = p;
    }
  }

  if (lar_index != 2) {
    for (int i = 0; i < 2; i++) {
      temp[0][i] = arr[2][i];
      arr[2][i] = lar[0][i];
      arr[lar_index][i] = temp[0][i];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }


  return 0;
}
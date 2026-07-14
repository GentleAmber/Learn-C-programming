/*
Write a program that generates a “random walk” across a 10 × 10 array. The array will contain characters (all '.' initially). 
The program must randomly “walk” from element to element, always going up, down, left, or right by one element. 
The elements visited by the program will be labeled with the letters A through Z, 
in the order visited. Here’s an example of the desired output:
A . . . . . . . . .
B C D . . . . . . .
. F E . . . . . . .
H G . . . . . . . .
I . . . . . . . . .
J . . . . . . . Z .
K . . R S T U V Y .
L M P Q . . . W X .
. N O . . . . . . .
. . . . . . . . . . 
Hint: Use the srand and rand functions (see deal.c) to generate random numbers.
*/
// There is chance this program will go into infinite loop when 
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define ROW 10
#define COL 10

char map[ROW][COL];
int check_dead_end(short row, short col);

int main(void) {
  // Let the walk starts from [0][0]. It can be randomised as well.
  // for dir: 0: up, 1: right, 2: down, 3: left
  short dir, current_col = 0, current_row = 0; 

  for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++)
      map[i][j] = '.';
  
  map[current_row][current_col] = 'A';

  srand((unsigned) time(NULL));

  for (short i = 1; i < 26; ) {
    dir = rand() % 4; 
    switch (dir)
    {
    case 0: // walk up
      if (current_row > 0 && map[current_row - 1][current_col] == '.') {
        current_row--;
        map[current_row][current_col] = 'A' + i;
        i++;
      } else if (check_dead_end(current_row, current_col) == 0) 
        goto end_of_loop;
      break;
    case 1: // walk right
      if (current_col < COL - 1 && map[current_row][current_col + 1] == '.') {
        current_col++;
        map[current_row][current_col] = 'A' + i;
        i++;
      } else if (check_dead_end(current_row, current_col) == 0) 
        goto end_of_loop;
      break;
    case 2: // walk down
      if (current_row < ROW - 1 && map[current_row + 1][current_col] == '.') {
        current_row++;
        map[current_row][current_col] = 'A' + i;
        i++;
      } else if (check_dead_end(current_row, current_col) == 0) 
        goto end_of_loop;
      break;
    case 3: // walk left
      if (current_col > 0 && map[current_row][current_col - 1] == '.') {
        current_col--;
        map[current_row][current_col] = 'A' + i;
        i++;
      } else if (check_dead_end(current_row, current_col) == 0) 
        goto end_of_loop;
      break;
    default:
      break;
    }
  }

  end_of_loop:
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      printf("%c ", map[i][j]);
    }
    printf("\n");
  }
  

  return 0;
}

int check_dead_end(short row, short col) {
  if (row == 0 ) {
    if (col == 0) {
      if (map[row + 1][col] != '.'
        && map[row][col + 1] != '.')
        return 0;
    } else if (col == COL - 1) {
      if (map[row][col - 1] != '.'
      && map[row + 1][col] != '.')
        return 0;
    } else {
      if (map[row][col - 1] != '.'
      && map[row][col + 1] != '.'
      && map[row + 1][col] != '.')
        return 0;
    }
  } else if (row == ROW - 1) {
    if (col == 0) {
      if (map[row - 1][col] != '.'
        && map[row][col + 1] != '.')
        return 0;
    } else if (col == COL - 1) {
      if (map[row][col - 1] != '.'
      && map[row - 1][col] != '.')
        return 0;
    } else {
      if (map[row][col - 1] != '.'
      && map[row][col + 1] != '.'
      && map[row - 1][col] != '.')
        return 0;
    }
  } else {
    if (col == 0) {
      if (map[row - 1][col] != '.'
        && map[row][col + 1] != '.'
        && map[row + 1][col] != '.')
        return 0;
    } else if (col == COL - 1) {
      if (map[row][col - 1] != '.'
      && map[row - 1][col] != '.'
      && map[row + 1][col] != '.')
        return 0;
    } else {
      if (map[row][col - 1] != '.'
      && map[row][col + 1] != '.'
      && map[row - 1][col] != '.'
      && map[row + 1][col] != '.')
        return 0;
    }
  }

  return 1;
}
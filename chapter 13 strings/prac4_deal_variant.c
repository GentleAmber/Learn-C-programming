/*
Modify the deal.c program of Section 8.2 so that it prints the full names of the cards it
deals:

Enter number of cards in hand: 5
Your hand:
Seven of clubs
Two of spades
Five of diamonds
Ace of spades
Two of hearts

Hint: Replace rank_code and suit_code by arrays containing pointers to strings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *rank_code[] = {"Ace", "Two", "Three", "Four", "Five", "Six", 
"Seven", "Eight", "Nine", "Ten", "J", "Q", "K"};
char *suit_code[] = {"diamonds", "hearts", "clubs", "spades"};

int main(void) {
  srand((unsigned) time(NULL));
  int hand_num, hand[13][4] = {0};
  
  printf("Enter number of cards in hand: ");
  scanf("%d", &hand_num);
  if (hand_num > 52 || hand_num <= 0) {
    return 1;
  }

  for (int i = 0; i < hand_num; ) {
    int rank = rand() % 13, class = rand() % 4;
    if (!hand[rank][class]) {
      hand[rank][class] = 1;
      i++;
    }
  }

  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      if (hand[i][j] == 1) {
        printf("%s of %s\n", rank_code[i], suit_code[j]);
      }
    }
  }
  return 0;
}
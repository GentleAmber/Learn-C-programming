/*
Classifying a Poker Hand
To show how a C program might be organized, let’s attempt a program that’s a little more 
complex than our previous examples. The program will read and classify
a poker hand. Each card in the hand will have both a suit (clubs, diamonds, hearts,
or spades) and a rank (two, three, four, five, six, seven, eight, nine, ten, jack, queen,
king, or ace). We won’t allow the use of jokers, and we’ll assume that aces are
high. The program will read a hand of FIVE cards, then classify the hand into one of
the following categories (listed in order from best to worst):
straight flush (both a straight and a flush)
four-of-a-kind (four cards of the same rank)
full house (a three-of-a-kind and a pair)
flush (five cards of the same suit)
straight (five cards with consecutive ranks)
three-of-a-kind (three cards of the same rank)
two pairs
pair (two cards of the same rank)
high card (any other hand)
If a hand falls into two or more categories, the program will choose the best one.
For input purposes, we’ll abbreviate ranks and suits as follows (letters may be
either upper- or lower-case):
Ranks: 2 3 4 5 6 7 8 9 t j q k a
Suits: c d h s
If the user enters an illegal card or tries to enter the same card twice, the program
will ignore the card, issue an error message, and then request another card. 
Entering the number 0 instead of a card will cause the program to terminate.

A session with the program will have the following appearance:
Enter a card: 2s
Enter a card: 5s
Enter a card: 4s
Enter a card: 3s
Enter a card: 6s
Straight flush
Enter a card: 8c
Enter a card: as
Enter a card: 8c
Duplicate card; ignored.
Enter a card: 7c
Enter a card: ad
Enter a card: 3h
Pair
Enter a card: 6s
Enter a card: d2
Bad card; ignored.
Enter a card: 2d
Enter a card: 9c
Enter a card: 4h
Enter a card: ts
High card
Enter a card: 0
*/

#include <stdio.h>
#include <stdlib.h>

const char rank[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 't',
                       'j', 'q', 'k', 'a'};
const char suit[4] = {'c', 'd', 'h', 's'};

// Read all 5 cards and store them in @a. Discards bad cards
void read_cards(char a[][2], int a_length);
// Analyse the hand and return an integer representing its class
int analyze_hand(char a[][2], int a_length);
// Receive the result from @analyze_hand(). Print the hand and the result
void print_result(char a[][2], int a_length, int res);

int main(void) {
  char a[5][2];
  while (1) {
    read_cards(a, 5);
    int res = analyze_hand(a, 5);
    print_result(a, 5, res);
  }
  
  return 0;
}

void read_cards(char a[][2], int a_length) {
  for (int i = 0; i < a_length; ) {
    short rank_valid = 0, suit_valid = 0, not_duplicate = 0;
    char i_rank, i_suit;

    printf("Enter a card (e.g. 9c): ");
    i_rank = getchar();
    i_suit = getchar();

    // Check whether to exit the program first
    if (i_rank == '0') {
      printf("Program ends.\n");
      exit(0);
      // otherwise, eats the '\n' and start processing
    } else {
      getchar();
    }
    // Check if card is bad
    for (int j = 0; j < 13; j++) {
      if (rank[j] == i_rank) {
        rank_valid = 1;
        break;
      } 
    }
    for (int j = 0; j < 4; j++) {
      if (suit[j] == i_suit) {
        suit_valid = 1;
        break;
      }
    }

    if (rank_valid && suit_valid) {
      // If the card is good, check if it's repeated
      for (int j = 0; j < i; j++) {
        if (a[j][0] == i_rank && a[j][1] == i_suit) {
          printf("Duplicate card; ignored.\n");
          goto final_test;
        } 
      }
      not_duplicate = 1;
    } else {
      printf("Bad card; ignored.\n");
    }

    final_test:
    if (rank_valid && suit_valid && not_duplicate) {
      a[i][0] = i_rank;
      a[i][1] = i_suit;
      i++;
    }
  }
}

int analyze_hand(char a[][2], int a_length) {
  /*
  classify the hand into one of the following categories (listed in order from best to worst):
  0 straight flush (both a straight and a flush)
  1 four-of-a-kind (four cards of the same rank)
  2 full house (a three-of-a-kind and a pair)
  3 flush (five cards of the same suit)
  4 straight (five cards with consecutive ranks)
  5 three-of-a-kind (three cards of the same rank)
  6 two pairs
  7 pair (two cards of the same rank)
  8 high card (any other hand)
  */
  
  // Register all the rank and suit. Meaning of array elements: number of appearances
  // e.g. rank[1] == 2 means there are two cards whose rank is 3.
  short rank[13] = {0}, suit[4] = {0}; 
  // From index 0 to index 8: straight flush to high card. Meaning of array elements:
  // true or false. e.g. class[0] == 1 means it's a straight flush
  short class[9] = {0}; 
  
  // First register all the ranks and suits
  for (int i = 0; i < a_length; i++) {
    switch (a[i][0])
    {
    case '2': case '3': case '4': case '5': case '6': case '7':
    case '8': case '9': 
      rank[0 + a[i][0] - '2']++;
      break;
    case 't': 
      rank[8]++;
      break;
    case 'j': 
      rank[9]++;
      break;
    case 'q': 
      rank[10]++;
      break;
    case 'k':
      rank[11]++;
      break;
    case 'a':
      rank[12]++;
      break;
    }

    switch (a[i][1])
    {
    case 'c':
      suit[0]++;
      break;
    case 'd':
      suit[1]++;
      break;
    case 'h':
      suit[2]++;
      break;
    case 's':
      suit[3]++;
      break;
    }
  }

  // Then check other classes based on the registered info
  // Straight:
  for (int i = 0; i < 13 - 1; i++) {
    // If current and the next rank are consecutive, start checking if
    // this is a straight hand.
    if (rank[i] && rank[i + 1]) {
      if (i <= 8) {
        short straight_flag = 1;
        for (int j = i + 1; j < i + 4; j++) {
          if (rank[j] && rank[j + 1]) 
            continue;
          else {
            straight_flag = 0;
            break;
          }
        }
        if (straight_flag) {
          class[4] = 1;
        }
      }
    }
  }
  
  // Check classes other than straight. When a class implicitly indicates there's 
  // no space for other classes, break the loop. For example, if a hand is four-of
  // -a-kind or full house, break the loop.
  for (int i = 0; i < 13; i++) {
    // Four of a kind
    if (rank[i] == 4) {
      class[1] = 1;
      break;
    }
    // three of a kind (if already encountered a pair, it's going to be full house)
    if (!class[7] && rank[i] == 3) {
      class[5] = 1;
    }
    // full house 
    if (class[5] && rank[i] == 2 ||
        class[7] && rank[i] == 3) {
      class[2] = 1;
      break;
    }
    // pair
    if (!class[7] && rank[i] == 2) {
      class[7] = 1;
    }
    // two pairs 
    if (class[7] && rank[i] == 2) {
      class[6] = 1;
      break;
    }
  }
  
  // Finally, check for flush and straight flush
  for (int i = 0; i < 4; i++) {
    if (suit[i] == 5) {
      class[3] = 1;
      if (class[4]) {
        class[0] = 1;
      }
      break;
    }
  }

  
  // Return the highest class in the form of int. If the hand is high card (i==8),
  // the loop will break so that the func will return 8
  int i;
  for (i = 0; i < 9; i++) {
    if (class[i]) {
      break;
    }
    if (i == 8) {
      break;
    }
  }
  
  return i;
}

void print_result(char a[][2], int a_length, int res) {
  printf("Hand: ");
  for (int i = 0; i < a_length; i++) {
    printf("%c%c ", a[i][0], a[i][1]);
  }
  printf("\n");
  
  switch (res)
  {
  case 0:
    printf("straight flush\n");
    break;
  case 1:
    printf("four-of-a-kind\n");
    break;
  case 2:
    printf("full house\n");
    break;
  case 3:
    printf("flush\n");
    break;
  case 4:
    printf("straight\n");
    break;
  case 5:
    printf("three-of-a-kind\n");
    break;
  case 6:
    printf("two pairs\n");
    break;
  case 7:
    printf("pair\n");
    break;
  case 8:
    printf("high card\n");
    break;
  }

}

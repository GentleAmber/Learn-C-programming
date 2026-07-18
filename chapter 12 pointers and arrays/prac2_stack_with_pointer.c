#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 10

char stack[STACK_SIZE];
char *top = stack;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
  // printf("is_empty: %s, is_full: %s", is_empty()?"true":"false", is_full()?"true":"false");

  // Test 1
  // push('c');
  // push('b');
  // push('a');
  // while (!is_empty())
  //   printf("%c ", pop());
  // printf("\n");

  // Test 2
  // for (int i = 0; i < STACK_SIZE; i++) {
  //   push('k');
  // }

  // for (int i = 0; i < STACK_SIZE; i++) {
  //   printf("%c ", pop());
  // }

  // printf("\n");
  // printf("is_empty: %s, is_full: %s", is_empty()?"true":"false", is_full()?"true":"false");

  // Test 3
  // for (int i = 0; i < STACK_SIZE + 1; i++) {
  //   push('k');
  // }
  return 0;
}

void make_empty(void) {
  while (!is_empty()) {
    pop();
  }
}

bool is_empty(void) {
  return top == stack;
}

bool is_full(void) {
  return top == (stack + STACK_SIZE);
}

void push(char i) {
  if (!is_full())
    *top++ = i;
  else 
    stack_overflow();
}

char pop(void) {
  if (!is_empty())
    return *--top;
  else 
    stack_underflow();
}

void stack_overflow(void) {
  printf("Stack overflows.\n");
}

void stack_underflow(void) {
  printf("Stack underflows.\n");
}
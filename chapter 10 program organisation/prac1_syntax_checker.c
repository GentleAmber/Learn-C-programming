/*
Modify the stack example of Section 10.2 so that it stores characters instead of integers.
Next, add a main function that asks the user to enter a series of parentheses and/or braces,
then indicates whether or not they’re properly nested:
Enter parentheses and/or braces: ((){}{()})
Parentheses/braces are nested properly
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {

  printf("Enter parentheses and/or braces: ");
  for (int i = 0; i < STACK_SIZE; i++) {
    char c = getchar();
    if (c != '\n') {
    }
  }
  return 0;
}

void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(char i)
{
  if (is_full())
    stack_overflow();
  else
    stack[top++] = i;
}

char pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return stack[--top];
}

void stack_overflow(void) {
  printf("You overflowed the stack.");
  exit(1);
}

void stack_underflow(void) {
  printf("You underflowed the stack.");
  exit(1);
}
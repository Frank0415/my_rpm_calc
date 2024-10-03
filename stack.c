#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *stack) { stack->top = -1; }

void push(Stack *stack, int input) {
  if (stack->top < CAPACITY - 1) // Prevent overflow
  {
    stack->top++;
    stack->array[stack->top] = input;
  } else {
    exit(1);
  }
}

int pop(Stack *stack) {
  if (stack->top >= 0) // Prevent underflow
  {
    int value = stack->array[stack->top];
    stack->top--;
    return value;
  } else {
    printf("bug!%d\n", stack->top);
    exit(1);
  }
}

int peek(Stack *stack) {
  if (stack->top != -1)
    return stack->array[stack->top];
  else
    return -1;
}
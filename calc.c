#include "calc.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

int calc_sub(int num, int num2, char op) {
  switch (op) {
  case '+':
    return num + num2;
  case '-':
    return num - num2;
  case '*':
    return num * num2;
  case '/':
    return num / num2;
  default:
    return 0;
  }
}

void calc(Stack *num, Stack *op) {
  int num2 = pop(num);
  push(num, calc_sub(pop(num), num2, pop(op)));
}

int compare(int prev, int new) {
  char parens[] = "()";
  char add_sub[] = "+-";
  // char mul_div[] = "*/";

  int prev_val = (strchr(parens, prev) != NULL)    ? -1
                 : (strchr(add_sub, prev) != NULL) ? 0
                                                   : 1;
  int new_val = (strchr(parens, new) != NULL)    ? -1
                : (strchr(add_sub, new) != NULL) ? 0
                                                 : 1;

  return new_val - prev_val;
}

void opin(Stack *num, Stack *op, int in) {
  if (in != ')' && in != '(') {
    int prev = peek(op);
    // printf("%d\n", compare(prev, in));
    if (prev == -1 || compare(prev, in) > 0) {
      push(op, in);
    } else {
      calc(num, op);
      opin(num, op, in);
    }
  } else if (in == '(') {
    push(op, in);
  }

  else {
    while (peek(op) != '(') {
      calc(num, op);
    }
    pop(op);
  }
}

void calc_final(Stack *num, Stack *op) {

  while (op->top > -1) {
    // printf("opt:%d\n",op->top);
    calc(num, op);
  }
}
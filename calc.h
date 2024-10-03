#ifndef CALC_H
#define CALC_H

#include "stack.h"
#include "stringvar.h"

void calc(Stack *num, Stack *op);
void opin(Stack *num, Stack *op, int in);
int compare(int prev, int new);
void calc_final(Stack *num, Stack *op);

#endif
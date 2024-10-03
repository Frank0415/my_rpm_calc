/**
 * @file calc.h
 * @brief Header file for the RPM calculator functions.
 *
 * This file contains the declarations of functions used for performing
 * Reverse Polish Notation (RPN) calculations. It includes functions for
 * handling stacks of numbers and operators, comparing operator precedence,
 * and finalizing the calculation.
 */

#ifndef CALC_H
#define CALC_H

#include "stack.h"
#include "stringvar.h"

/**
 * @brief Performs the RPN calculation.
 *
 * This function processes the stacks of numbers and operators to perform
 * the RPN calculation.
 *
 * @param num Pointer to the stack of numbers.
 * @param op Pointer to the stack of operators.
 */
void calc(Stack *num, Stack *op);

/**
 * @brief Handles operator input.
 * This function processes an operator input and updates the stacks of
 * numbers and operators accordingly.
 *
 * @param num Pointer to the stack of numbers.
 * @param op Pointer to the stack of operators.
 * @param in The operator input.
 */
void opin(Stack *num, Stack *op, int in);
/**
 * @brief Compares operator precedence.
 *
 * This function compares the precedence of two operators.
 *
 * @param prev The previous operator.
 * @param new The new operator.
 * @return An integer indicating the result of the comparison.
 */
int compare(int prev, int new);

/**
 * @brief Finalizes the RPN calculation.
 *
 * This function processes any remaining operators in the stack to finalize
 * the RPN calculation.
 *
 * @param num Pointer to the stack of numbers.
 * @param op Pointer to the stack of operators.
 */
void calc_final(Stack *num, Stack *op);

#endif

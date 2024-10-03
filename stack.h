/**
 * @file stack.h
 * @brief Header file for a simple stack implementation.
 *
 * This file contains the definition of a stack data structure and
 * declarations for functions to manipulate the stack.
 */

#ifndef STACK_H
#define STACK_H

#define CAPACITY 100 /**< Maximum capacity of the stack */

/**
 * @struct Stack
 * @brief A structure to represent a stack.
 *
 * @var Stack::top
 * The index of the top element in the stack.
 * @var Stack::array
 * The array to store stack elements.
 */
typedef struct {
  int top;
  int array[CAPACITY];
} Stack;

/** * @brief Initializes the stack.
void add(VStack *stac * * This function sets the initial state of the stack. *
 * @param stack A pointer to the stack to initialize.
 */
void initStack(Stack *stack);

/**
 * @brief Pushes an element onto the stack.
 *
 * This function adds an element to the top of the stack.
 *
 * @param stack A pointer to the stack.
 * @param input The element to push onto the stack.
 */
void push(Stack *stack, int input);

/**
 * @brief Pops an element from the stack.
 *
 * This function removes and returns the top e

int pop(Stack *stack);
int peek(Stack *stack);
lement of the stack.
 *
 * @param stack A pointer to the stack.
 * @return The element popped from the stack.
 */
int pop(Stack *stack);

/**
 * @brief Peeks at the top element of the stack.
 *
 * This function returns the top element of the stack without removing it.
 *
 * @param stack A pointer to the stack.
 * @return The top element of the stack.
 */
int peek(Stack *stack);

#endif
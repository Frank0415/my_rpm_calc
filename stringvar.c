#include "stringvar.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int preprocess(char *input) {
  char *ptr;
  ptr = strchr(input, '=');

  if (ptr != NULL)
    return ptr - input;
  else
    return -1;
}

int splitString(char *input, int *pos) {
  // If we've reached the end of the string, return -2
  if (input[*pos] == '\0') {
    return -2; // End of string
  }

  // Skip any spaces (if necessary)
  while (input[*pos] == ' ') {
    (*pos)++; // Increment the position
  }

  // If the current character is an operator, return -1 and advance position
  if (isOperator(input[*pos])) {
    (*pos)++;  // Move past the operator
    return -1; // Operator found, indicate that it's an operator
  }

  // If the current character is a digit or a letter, move until the next operator or end of the variable
  if (isalnum(input[*pos])) {
    while (isalnum(input[*pos])) {
      (*pos)++; // Move through the variable until we hit a non-alphanumeric character
    }
    return *pos; // Return the position right after the variable
  }

  return -2; // Default case if something unexpected happens (end of processing)
}

int varprocess(char *in, Varible *vari) { return search(vari, in); }

int isOperator(char c) { return strchr("+-*/()", c) != NULL; }

void initvar(Varible *vari) { vari->count = -1; }

void add(Varible *vari, char namein[], int value) {
  vari->count++;
  strcpy(vari->name[vari->count], namein);
  vari->value[vari->count] = value;
}

int search(Varible *vari, char search[]) {
  //printf("search:%s\n", search);
  for (int i = 0; i <= vari->count; i++)
  {
    if (strcmp(vari->name[i], search) == 0)
    {
      return vari->value[i];
    }
  }
  fprintf(stderr, "Error: Variable '%s' not found.\n", search);
  exit(1);
}

void output(Varible *vari) {
  printf("Here are the varibles: \n");
  for (int i = 0; i < (vari->count + 1); i++) {
    printf("| %-10s| %-10d|\n", vari->name[i], vari->value[i]);
  }
}
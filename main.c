#include "calc.h"
#include "stack.h"
#include "stringvar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100

int lineProcess(char *input, Varible *vari);
void assignVar(char *input, Varible *vari);
int vton(char input[], Varible *vari);

void assignVar(char *input, Varible *vari)
{
  int equpos = -1;
  for (size_t i = 0; i < strlen(input); i++)
  {
    if (*(input + i) == '=')
    {
      equpos = i;
    }
  }
  int val;
  if (*(input + equpos + 1) != '-')
    val = lineProcess((input + equpos + 1), vari);
  else
  {
    char temp[MAXLEN + 1] = "0";
    strncpy(temp + 1, input + equpos + 1, MAXLEN);
    val = lineProcess(temp, vari);
  }

  if (equpos != -1)
  {
    char temp[MAXLEN];
    memset(temp, '\0', sizeof(temp));
    add(vari, strncpy(temp, input, equpos), val);
  }
}

int lineProcess(char *input, Varible *vari)
{
  Stack op, num;
  initStack(&op);
  initStack(&num);

  int pos = 0; // Position within the string
  int oldpos;  // Previous position to track number start
  int status;  // Status from splitString

  // Process the input string
  while (oldpos = pos, (status = splitString(input, &pos)) != -2)
  {
    // printf("%d//%d//%d\n", oldpos, pos, status); // Debugging output
    if (status == -1) // Operator found
    {
      opin(&num, &op, *(input + oldpos)); // Process operator
      // printf("operator:%c\n", *(input + oldpos)); // Debug output for operator
    }
    else // Number found
    {

      char temp[MAXLEN];                           // Temporary buffer for number
      memset(temp, '\0', sizeof(temp));            // Clear the buffer
      strncpy(temp, input + oldpos, pos - oldpos); // Copy the number
      temp[pos - oldpos] = '\0';                   // Null-terminate the string
      push(&num, vton(temp, vari));                // Push the number onto the stack
      // printf("peek:%d\n", peek(&num));
    }
  }
  // printf("outloop,optop:%d\n", op.array[0]);
  calc_final(&num, &op);                                 // Perform final calculations
  printf("The result of %s is %d\n", input, peek(&num)); // Print the result
  return peek(&num);
}

int vton(char input[], Varible *vari)
{
  // Check if the input is a number
  int isNumber = 1;
  for (int i = 0; i < strlen(input); i++)
  {
    if (!isdigit(input[i]) && !(i == 0 && input[i] == '-'))
    {
      isNumber = 0;
    }
  }
  if (isNumber)
  {
    return atoi(input);
  }
  // If not a number, search for the variable's value
  int value = search(vari, input);
  if (value == -1)
  {
    fprintf(stderr, "Error: Variable %s not found\n", input);
    exit(EXIT_FAILURE);
  }
  return value;
}

int main()
{
  Varible variable;
  initvar(&variable);

  FILE *file = fopen("test1.txt", "r");
  if (file == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  char line[MAXLEN];
  memset(line, '\0', sizeof(line));
  while (fgets(line, sizeof(line), file))
  {
    // Remove newline character if present
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
    {
      line[len - 1] = '\0';
    }
    assignVar(line, &variable);
    memset(line, '\0', sizeof(line));
  }

  fclose(file);

  output(&variable);
  return 0;
}
#include "calc.h"
#include "stack.h"
#include "stringvar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lineProcess(char *input, Varible *vari) {
  Stack op, num;
  initStack(&op);
  initStack(&num);

  int pos = 0; // Position within the string
  int oldpos;  // Previous position to track number start
  int status;  // Status from splitString

  // Process the input string
  while (oldpos = pos, (status = splitString(input, &pos)) != -2) {
    printf("%d//%d//%d\n", oldpos, pos, status); // Debugging output
    if (status == -1)                            // Operator found
    {
      opin(&num, &op, *(input + oldpos));         // Process operator
      printf("operator:%c\n", *(input + oldpos)); // Debug output for operator
    } else                                        // Number found
    {
      char temp[100];                   // Temporary buffer for number
      memset(temp, '\0', sizeof(temp)); // Clear the buffer
      strncpy(temp, input + oldpos, pos - oldpos); // Copy the number
      temp[pos - oldpos] = '\0';                   // Null-terminate the string
      push(&num, atoi(temp)); // Push the number onto the stack
      printf("peek:%d\n", peek(&num));
    }
  }
  printf("outloop,optop:%d\n", op.array[0]);
  calc_final(&num, &op); // Perform final calculations
  printf("The result of %s is %d\n", input, peek(&num)); // Print the result
}

int main() {
  Varible variable;
  lineProcess("2+4-2*3+114", &variable);
  lineProcess("(2+7)+4*3", &variable);
  lineProcess("2+(7+4)*3", &variable);
  // lineProcess("A=2+7+4*3", &variable);
  // lineProcess("A+(7+4)*3", &variable);
  return 0;
}
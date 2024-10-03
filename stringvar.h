#ifndef STRINGVAR_H
#define STRINGVAR_H

#define CAPACITY 100

typedef struct {
  char name[CAPACITY][CAPACITY];
  int value[CAPACITY];
  int count;
} Varible;

int preprocess(char *input);
int splitString(char *input, int *pos);
int varprocess(char *in, Varible *vari);
int isOperator(char c);

void initvar(Varible *vari);
void add(Varible *vari, char namein[], int value);
int search(Varible *vari, char search[]);
void output(Varible *vari);

#endif
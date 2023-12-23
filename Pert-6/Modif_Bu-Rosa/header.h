#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
  char nim[50], nama[50], nilai[50]; 
}data;

typedef struct elmt *alamatelmt;
typedef struct elmt{
  data kontainer;
  alamatelmt next;
}elemen;

typedef struct {
  elemen* top;
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(data input, stack *S );
void pop(stack *S);
void printStack(stack S);
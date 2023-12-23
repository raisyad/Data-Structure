#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct {
    char label_nim[100], label_nama[100];
    float nilai;
} isiKontainer;

typedef struct {
    int top;
    isiKontainer data[MAX];
} stack;

void createStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(isiKontainer kontainer, stack *S);
void pop(stack *S);
void printStack(stack S);
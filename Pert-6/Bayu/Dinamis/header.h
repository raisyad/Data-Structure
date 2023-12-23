#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 101

typedef struct {
    char label_nim[MAX], label_nama[MAX];
    float nilai;
} isiKontainer;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    isiKontainer kontainer;
    alamatelmt next;
} elemen;

typedef struct {
    elemen *top;
} stack;

void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(isiKontainer kontainer, stack *S);
void pop(stack *S);
void printStack(stack S);
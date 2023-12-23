#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAXCONT 101

typedef struct {
    char label_nim[MAXCONT], label_nama[MAXCONT]; 
}isiKontainer;

typedef struct {
    int top;
    isiKontainer data[MAX];
}stack;

void createStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(isiKontainer kontainer, stack *S);
void pop(stack *S);
void ambil(stack *S, stack *S2, char pilih[]);
void printStack(stack S);
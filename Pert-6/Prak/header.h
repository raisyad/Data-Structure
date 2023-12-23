// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM6 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 101

typedef struct {
    char Name[MAX], Price[MAX];
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
isiKontainer popT(stack *S);
void printStack(stack S);
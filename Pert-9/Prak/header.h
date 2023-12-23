// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char name[101], value[101];
}data;

typedef struct smp *alamatsimpul;
typedef struct smp{
    data kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

void makeTree(data input, tree *T);
void addChild(data input, simpul *root);
void delAll(simpul *root);
void delChild(simpul *del, simpul *root);
simpul* findSimpul(data input, simpul *root);
void printTreePreOrder(simpul *root, int *sumNode);
void printTreePostOrder(simpul *root, int *sumNode);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
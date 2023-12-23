#include <stdio.h>
#include <malloc.h>

typedef struct{
    char a;
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
void delChild(data input, simpul *root);
simpul* findSimpul(data input, simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
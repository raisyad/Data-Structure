#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char sub[10];
    int child, parent, ganjil, genap;
} isiKontainer;

typedef struct smp *alamatsimpul;
typedef struct smp {
    isiKontainer kontainer;
    alamatsimpul right;
    alamatsimpul left;
    alamatsimpul parent;
} simpul;

typedef struct {
    simpul *root;
} tree;

void makeTree(isiKontainer kontainer, tree *T);
void addRight(isiKontainer kontainer, simpul *node);
void addLeft(isiKontainer kontainer, simpul *node);
void delAll(simpul *node);
void delRight(simpul *node);
void delLeft(simpul *node);
void printTreePreOrder(simpul *node, int *sumNode);
void printTreeInOrder(simpul *node, int *sumNode);
void printTreePostOrder(simpul *node, int *sumNode);
simpul* findSimpul(isiKontainer kontainer, simpul *root);
int Process(simpul *node, int *ganjil, int *genap);

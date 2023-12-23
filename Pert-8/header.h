#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char node;
} isiKontainer;

typedef struct smp *alamatsimpul;
typedef struct smp {
    isiKontainer kontainer;
    alamatsimpul right;
    alamatsimpul left;
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
void printTreePreOrder(simpul *node);
void printTreeInOrder(simpul *node);
void printTreePostOrder(simpul *node);
void copyTree(simpul *node1, simpul **node2);
int isEqual(simpul *node1, simpul *node2);

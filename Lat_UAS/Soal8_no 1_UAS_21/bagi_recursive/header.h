#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int c;
}data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    data kontainer;
    alamatsimpul right;
    alamatsimpul left;
}simpul;

typedef struct
{
    simpul* root;
}tree;

void makeTree(int akar, tree *T);
void addRight(int akar, simpul *node);
void addLeft(int akar, simpul *node);
void delAll(simpul *node);
void delRight(simpul *node);
void delLeft(simpul *node);
void printTreePreOrder(simpul *node, int idx);
void printTreeInOrder(simpul *node);
void printTreePostOrder(simpul *node);
void copyTree(simpul *node1, simpul**node2);
int isEqual(simpul *node1, simpul *node2);
simpul* findSimpul(int cari, simpul *node);
void devide(simpul *node, int akar, int bagi);
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char a;
}dataNode;

typedef struct
{
    int b;
}dataEdge;

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp
{
    char kontainer;
    int visit;
    alamatsimpul next;
    alamatjalur arc;
}simpul;

typedef struct jlr
{
    alamatjalur next_jalur;
    simpul *tujuan;
}jalur;

typedef struct
{
    simpul* first;
}graph;

void createEmpty(graph *G);
void addSimpul(char c, graph *G);
void addJalur(simpul *awal, simpul *tujuan);
simpul* findSimpul(char c, graph G);
void printGraph(graph G);
void findJalur(simpul *awal, simpul *tujuan, int *direct, int *undirect, int *jalan);
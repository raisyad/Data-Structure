// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char node;
} isiKontainer;

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp
{
    // char kontainer;
    isiKontainer kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainerJalur;
    alamatjalur nextJalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul *first;
} graph;

void createEmpty(graph *G);
void addSimpul(isiKontainer kontainer, graph *G);
void addJalur(simpul *awal, simpul *tujuan);
simpul *findSimpul(isiKontainer kontainer, graph G);
void delJalur(char ctujuan, simpul *awal);
void delAllJalur(simpul *awal);
void delSimpul(isiKontainer kontainer, graph *G);
void printGraph(graph G);
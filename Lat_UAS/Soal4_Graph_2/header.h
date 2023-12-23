// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char node;
    char nameOfCountry[300], CountryJalanTujuan[300];
    int bobot;
} isiKontainer;

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp
{
    char kontainer[300];
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
void addSimpul(char kota[], graph *G);
void addJalur(simpul *awal, simpul *tujuan, int bobot);
simpul* findSimpul(char kota[], graph G, int *finded);
void delJalur(char ctujuan[], simpul *awal);
void delAllJalur(simpul *awal);
void delSimpul(char c[], graph *G);
void printGraph(graph G);

void carijalur(simpul *asoy, char find[200], int *dapet, char awal[200], int *bobot);
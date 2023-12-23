// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 300

typedef struct {
    char node;
    char nameOfCountry[MAX], CountryJalanTujuan[MAX];
    int bobot;
} isiKontainer;

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp {
    char kontainer;
    int visited;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr {
    int kontainerJalur;
    alamatjalur nextJalur;
    simpul *tujuan;
} jalur;

typedef struct {
    simpul *first;
} graph;

void createEmpty(graph *G);
void addSimpul(char kota, graph *G);
void addJalur(simpul *awal, simpul *tujuan);
simpul* findSimpul(char kota, graph G, int *ketemu);
void TrackingMap(simpul *root, int *ketemu, char path[], int *index);
void printGraph(graph G);

// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP5 dalam mata kuliah Struktur Data
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
    char kontainer[MAX];
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

void createEmpty(graph *G); // Prosedur Buat Graph Kosong
void addSimpul(char kota[], graph *G); // Prosedur Menambahkan Simpul
void addJalur(simpul *awal, simpul *tujuan, int bobot); // Prosedur Menambahkan Jalur
simpul* findSimpul(char kota[], graph G, int *ketemu); // Prosedur mencari simpul
void TrackingMap(simpul *root, char pointA[], char pointB[], char temp[], int sumJalur, int i); // Prosedur Explore Titik Awal Ketujuan
void printGraph(graph G); 

// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP4 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    //pembuatan type bungkusan
    char name[105], child[105], parent[105];
    int level;
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

// Kumpulan prosedur
void makeTree(data input, tree *T); // Pembuatan pohon
void addChild(data input, simpul *root); // Memasukkan anak dari parent
simpul* findSimpul(data input, simpul *root); // Mencari simpul
void printTreePreOrder(simpul *root); // Proses output
void delKnock(simpul *del, simpul *root); // Menghapus anak dari parent
void delAll(simpul *root); // Menghapus semua dari root yang dituju
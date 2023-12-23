// Saya [Raisyad Jullfikar] 2106238 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
// Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan 
// seperti yang telah dispesifikasikan. Aamiin.
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 500 // Set MAX 500 untuk setiap array
#define initlevel 1 // Set level 1 untuk di main

// struct penampung data pada simpul tree
typedef struct{
    char name[MAX], child[MAX], parent[MAX], component[MAX][MAX];
    // Char name, child/anak, parent/ortu, dan component sesuai permintaan
    int level, price, iterComp;
    // Int set level tiap input, harga input, iteraasiComponent
}data;

typedef struct smp *alamatsimpul; // Alamat simpul/node
typedef struct smp{
    data kontainer; // Data dalam simpul
    alamatsimpul sibling; // Penunjuk sibling/saudara
    alamatsimpul child; // Penunjuk anak/child
    alamatsimpul parent; // Penunjuk orang tua/parent
}simpul;

// Tree
typedef struct{
    simpul *root;
}tree;

// -- Asal Muasal Tree Dibuat
// Prosedur membuat Tree
void makeTree(data input, tree *T);

// -- Penginputan Tree/Child
// Prosedur Menambah Child
void addChild(data input, simpul *root);

// -- Splitter text/str
// Prosedur splitter atau pemecah string
void explodeData(char word[MAX], char name[MAX], char parent[MAX], char price[MAX], char iter[MAX]);

// -- stoi Func
// Convert string Number to int Number
int sNumtoiNum(char str[]);

// -- Mencari Panjang dari sebuah integer
// Panjang harga
int findLenNum(simpul *root);

// -- Proses pencarian simpul/Harga
// Prosed mencari simpul Nama
simpul* findSimpul(data input, simpul *root);
// Prosed untuk mencari node/simpul harga
simpul* findMinPrice(int price, simpul *root);

// -- Proses pendelete-an
// Prosedur del All
void delAll(simpul *root);
// Proses remake del child dengan pemindahan pointer
void delKnock(simpul *del, simpul *root);

// -- Proses Pencarian len str per level
// Mencari string terpanjang dari setiap levelnya
void LenStrperLev(simpul *root, int lenStr[], int level);

// -- Proses menampilkan data sesuai levelnya
// Menampilkan sesuai level
void printLevel(simpul *root, int lenStr[], int level);
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP3 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 101 // Mendefinisikan MAX sebanyak 101

typedef struct {
    char YearMusicRilis[MAX], TitleMusic[MAX], NameBand[MAX]; // Deklar Data data yang dibutuhkan
} isiKontainer;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    isiKontainer kontainer;
    alamatelmt next;
} elemen;

typedef struct {
    elemen *top;
} stack;

void createStack(stack *S);                                 // Prosedur untuk membuat stack
int isEmpty(stack S);                                       // fungsi untuk cek apakah stack kosong
int countElement(stack S);                                  // Fungsi untuk menghitung jumlah elemen dalam stack
void push(isiKontainer kontainer, stack *S);                // Prosedur untuk menambahkan elemen baru ke stack
void pop(stack *S);                                         // Prosedur untuk mengeluarkan elemen dari stack
void Classification(stack *s, stack *rock, stack *pop);     // Prosedur untuk mengelompokkan data rock atau pop
void printStackRock(stack s);                               // Prosedur untuk menampilkan elemen rock dalam stack
void printStackPop(stack s);                                // Prosedur untuk menampilkan elemen pop dalam stack
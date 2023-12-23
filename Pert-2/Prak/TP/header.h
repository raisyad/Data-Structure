// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Praktikum TP1 (KBT22) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// struktur listnya
typedef struct {
    char Judul[201];        //char untuk inputan JudulFilm
    char Production[201];   //char untuk inputan ProduksiFilm
    char ratingFilm[201];   //char untuk inputan RatingFilm
    char tempJudul[201], tempProduction[201], tempratingFilm[201]; //char - char untuk tampungan sort dari ke-3 data
}filmGeber; //nama bungkusan

typedef struct elmt *alamatelmt; //membuat sebuah pointer bungkusan didalam struct elmt

typedef struct elmt {
    filmGeber kontainer; //membuat bungkusan kontainer dari struct filmGeber
    alamatelmt next; //membuat bungkusan next dari struct alamatelmt
}elemen; //nama bungkusan

typedef struct {
    elemen *first; //membuat pointer bungkusan first
}list; //nama bungkusan


void createList(list *L);
void addFirst(char Judul[201], char Production[201], char ratingFilm[201], list *L);
void SortingDatas(list *L, char SortedData[201], char methods[201], filmGeber kontainer);
void PrintOutElement (list L);
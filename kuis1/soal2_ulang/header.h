// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Kuis 1 Soal 2 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// struktur listnya
typedef struct {
    char Type[51];
    char Merk[51];
    char Name[51];
}Pengusaha;

typedef struct elmt *alamatelmt;

typedef struct elmt {
    Pengusaha kontainer;
    alamatelmt next;
}elemen;

typedef struct {
    elemen *first;
}list;


void createList(list *L);
int countElement(list L);
void addFirst(Pengusaha kontainer, list *L);
void addAfter(elemen *prev, Pengusaha kontainer, list *L);
void addLast(Pengusaha kontainer, list *L);
void printElement(list L);
void CateList(Pengusaha kontainer, list *L, list *action_1, list *sepatu_2, list *sepeda_3);
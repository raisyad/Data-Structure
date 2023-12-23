// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char Desc[101];
    int Date;
} dataKontainer;

typedef struct elmt *alamatelmt;

typedef struct elmt
{
    dataKontainer kontainer;
    alamatelmt next;
    alamatelmt prev;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countEl(list L);
void addFirst(dataKontainer kontainer, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void sortAscDate(list *L);
void sortAscDesc(list *L);
void printEl(list *L);
void printKD(list *L);
void printRev(list *L);
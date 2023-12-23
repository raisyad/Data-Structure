// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[101], nama[101], nilai[101];
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
void addAfter(elemen *prev, dataKontainer kontainer, list *L);
void addLast(dataKontainer kontainer, list *L);
void addBefore (elemen *before, dataKontainer kontainer, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printEl(list L);
void printRev(list L);
void printReverse(list L);
void delAll(list *L);
void switchEl(list *L);
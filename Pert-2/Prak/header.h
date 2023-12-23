// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LTD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// struktur listnya
typedef struct {
    char name[101];
    char JK[101];
    char bookFrom[101];
}tokoh;

typedef struct elmt *alamatelmt;

typedef struct elmt {
    tokoh kontainer;
    alamatelmt next;
}elemen;

typedef struct {
    elemen *first;
}list;


void createList(list *L);
int countElement(list L);
void addFirst(char name[], char JK[], char bookFrom[], list *L);
void addAfter(elemen *prev, char name[], char JK[], char bookFrom[], list *L);
void addLast(char name[], char JK[], char bookFrom[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);

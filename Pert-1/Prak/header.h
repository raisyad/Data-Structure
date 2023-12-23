// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

#include<stdio.h>
#include<string.h>
#define MAKS 5;

typedef struct {
    char nama[100];
    char level[100];
    char gameFrom[100];
}game;

typedef struct {
    game kontainer;
    int next;
} elemen;

typedef struct {
    int first;
    elemen data[10];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char level[], char gameFrom[], list *L);
void addAfter(int prev, char nama[], char level[], char gameFrom[], list *L);
void addLast(char nama[], char level[], char gameFrom[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);
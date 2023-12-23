// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGS22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include<stdio.h>
#include<string.h>

typedef struct {
  char name[101];
  char date[101];
  char sum[101];
}Animals;

typedef struct {
  Animals kontainer;
  int next;
  int prev;
}elemen;

typedef struct {
  int first;
  int tail;
  elemen data[10];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char name[], char date[], char sum[], list *L);
void addAfter (int before, char name[], char date[], char sum[], list *L);
void addLast(char name[], char date[], char sum[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void delAll (list *L);
void printElement(list L);
void printReverse(list L);
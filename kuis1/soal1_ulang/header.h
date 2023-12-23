// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis 1 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include<stdio.h>
#include<string.h>

typedef struct {
  char kode1[51];
  char kode2[51];
}GenS1;

typedef struct {
  GenS1 kontainer;
  int next;
  int prev;
}elemen;

typedef struct {
  int first;
  int tail;
  elemen data[101];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(GenS1 kontainer, list *L);
void addAfter (int before, GenS1 kontainer, list *L);
void addLast(GenS1 kontainer, list *L);
void printElement(list L);
void swapEl(list *L1, list *L2, int p);
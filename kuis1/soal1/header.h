/*
Saya Raisyad Jullfikar NIM 2106238
mengerjakan soal Kuis 1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/
#include<stdio.h>
#include<string.h>

typedef struct {
  char kode1[51]; //Untuk kode 1
  char kode2[51]; //Untuk kode 2
}GenS1; //Nama bungkusan

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

// Deklar Prosedur dan fungsi dalam mesin
void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char kode1[], char kode2[], list *L);
void addAfter (int before, char kode1[], char kode2[], list *L);
void addLast(char kode1[], char kode2[], list *L);
void printElement(list L);
void SwapEl(list *L1, list *L2, int p);
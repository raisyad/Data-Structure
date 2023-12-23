// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM7 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 101

typedef struct{
  char Name[MAX];
  int Prio;
  char City[MAX];
  int danaBantuan;
}IsiKontainer;

typedef struct elm *alamatelmt;
typedef struct elm{
  IsiKontainer kontainer;
  alamatelmt next;
}elemen;

typedef struct{
  elemen *first;
  elemen *last;
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(IsiKontainer input, queue *Q);
void addPriority(IsiKontainer input, queue *Q, int p);
void del(queue *Q);
IsiKontainer DeltoIn(queue *Q);
void DeltoInS(queue *Q, queue *Q2);
void printQueue(queue Q);
void delLast(queue *Q);
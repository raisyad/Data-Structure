// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis2 qufree22 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXCONTAINER 101

typedef struct{
  char NameofClient[MAXCONTAINER], TypeWork[MAXCONTAINER];
  int Prio;
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

void createEmpty(queue *Q); // Membuat Queue Kosong
int isEmpty(queue Q); // Mengecek apakah queue kosong atau tidak
int countElement(queue Q); // Menghitung element pada sebuah queue
void add(IsiKontainer input, queue *Q); // Menginputkan/Memasukkan elemen pada sebuah queue
void PrioAdd(IsiKontainer input, queue *Q, int priorityAntrian); // Menginputkan/Memasukkan elemen dengan metode yang diprioritaskan
void del(queue *Q); // Mendelete sebuah elemen
void DeltoInS(queue *Q, queue *Q2); // Mendelete dari stack yang satu dan memasukkan/menginputkan ke stack yang lainnya
void delLast(queue *Q); // Mendelete elemen terakhir
void printQueue(queue Q); // Prosedur menampilkan elemen antrian
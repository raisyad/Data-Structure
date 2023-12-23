// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis2 qufree22 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void){
  queue Q, Q2; // Deklar queue Q -> Q1 dan Q2
  IsiKontainer input; //Deklar elemen bungkusan
  
  createEmpty(&Q);  // Buat queue kosong untuk Q
  createEmpty(&Q2); // Buat queue kosong untuk Q2

  int n,markDone; // Deklar var n dan penanda yang pekerjaannya sudah selesai

  scanf("%d", &n); // Input n
  for (int i = 0; i < n; i++) { // Inputkan data kedalam queue Q sebanyak n, dengan metode prioritas
    scanf("%s %s %d", &input.NameofClient, &input.TypeWork, &input.Prio);
    PrioAdd(input, &Q, input.Prio);
  }

  scanf("%d", &markDone); // Input pekerjaan yang sudah selesai
  for (int i = 0; i < markDone; i++) //Lakukan pemindahan elemen dari queue asal ke queue tujuan
    DeltoInS(&Q, &Q2); 
  
  // Proses output
  printf("pekerjaan yang telah selesai:\n");
  printQueue(Q2);
  printf("\n");
  printf("pekerjaan yang masih menanti:\n");
  printQueue(Q);
}
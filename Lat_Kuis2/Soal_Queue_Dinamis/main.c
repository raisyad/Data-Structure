// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM7 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void){
  queue Q;
  queue Q2;
  IsiKontainer input;
  
  createEmpty(&Q);
  createEmpty(&Q2);

  int n,p;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %d %s %d", &input.Name, &input.Prio, &input.City, &input.danaBantuan);
    addPriority(input, &Q, input.Prio);
  }

  scanf("%d", &p);
  for (int i = 0; i < p; i++)
    DeltoInS(&Q, &Q2);
  
  printf("Bantuan Tersalurkan:\n");
  printQueue(Q2);
  printf("\n");
  printf("Antrian berisi:\n");
  printQueue(Q);
}


/*

input--

3
13507701 Nana 64.75
13507702 Rudi 75.11
13507703 Dea 84.63

*/
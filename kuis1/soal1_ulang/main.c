// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis 1 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
  list L1;
  list L2;
  GenS1 InputOfData;
  int n,p;
  
  scanf("%d", &n);
  // List pertama
  createList(&L1);
  for (int i = 0; i < n; i++) {
    scanf ("%s %s", &InputOfData.kode1, &InputOfData.kode2);
    addLast(InputOfData, &L1);
  }

  createList(&L2);
  for (int i = 0; i < n; i++) {
    scanf ("%s %s", &InputOfData.kode1, &InputOfData.kode2);
    addLast(InputOfData, &L2);
  }
  scanf("%d", &p);
  swapEl(&L1,&L2,p);
}
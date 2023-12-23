// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Kuis 1 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
  list L1;  // LIST Pertama
  list L2;  // LIST Kedua
  GenS1 InputOfData; //Buat Bungkusan untuk Inputan
  int n,p; //Deklar n inputan dan berapa p yang ditukar
  createList(&L1); //Pembuatan LIST pertama
  scanf ("%d", &n); //input sebanyak n

  // INPUT LIST PERTAMA
  for (int i = 0; i < n; i++) { 
    scanf ("%s %s", &InputOfData.kode1, &InputOfData.kode2);
    addLast(InputOfData.kode1, InputOfData.kode2, &L1);
  }

  // INPUT LIST KEDUA
  createList(&L2);
  for (int i = 0; i < n; i++) {
    scanf ("%s %s", &InputOfData.kode1, &InputOfData.kode2);
    addLast(InputOfData.kode1, InputOfData.kode2, &L2);
  }
  scanf ("%d", &p); // Inputan sebanyak P yang ditukar
  SwapEl(&L1,&L2,p); //Pemanggilan prosedur swap dengan hasil outputnya

  return 0;
}
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGS22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
  list L;
  createList(&L);
  Animals InputOfData;
  scanf ("%s %s %s", &InputOfData.name, &InputOfData.date, &InputOfData.sum);
  addFirst(InputOfData.name, InputOfData.date, InputOfData.sum, &L);
  scanf ("%s %s %s", &InputOfData.name, &InputOfData.date, &InputOfData.sum);
  addLast(InputOfData.name, InputOfData.date, InputOfData.sum, &L);
  scanf ("%s %s %s", &InputOfData.name, &InputOfData.date, &InputOfData.sum);
  addAfter(L.first, InputOfData.name, InputOfData.date,InputOfData.sum, &L);
  printf("Data Kebun Binatang\n");
  printf ("===================\n");
  printElement(L);

  delAfter(L.data[L.first].next, &L);
  scanf ("%s %s %s", &InputOfData.name, &InputOfData.date, &InputOfData.sum);
  addAfter(L.first, InputOfData.name, InputOfData.date,InputOfData.sum, &L);
  scanf ("%s %s %s", &InputOfData.name, &InputOfData.date, &InputOfData.sum);
  addAfter(L.data[L.tail].prev, InputOfData.name, InputOfData.date,InputOfData.sum, &L);
  delFirst(&L);
  printf ("===================\n");
  printElement(L);

  scanf ("%s %s %s", &InputOfData.name, &InputOfData.date, &InputOfData.sum);
  addFirst(InputOfData.name, InputOfData.date, InputOfData.sum, &L);
  scanf ("%s %s %s", &InputOfData.name, &InputOfData.date, &InputOfData.sum);
  addAfter(L.data[L.first].next, InputOfData.name, InputOfData.date,InputOfData.sum, &L);
  delLast(&L);
  printf ("===================\n");
  printReverse(L);

  delAll(&L);
  printf ("===================\n");
  printElement(L);
}
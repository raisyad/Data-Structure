// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM5 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void){
  list L;
  mahasiswa mhs;
  matKul matkuls; 
  createList(&L);
  // Nim -> kodebox
  // Nama -> Labelbox

  int n,mark = 0;
  scanf ("%d", &n);
  
  for (int i = 0; i < n; i++){
    scanf("%s %s", &mhs.nim, &mhs.nama);
    addLastB(mhs.nim, mhs.nama, &L);
    eBaris *tunjuks;
    if (i == 0) 
      tunjuks = L.first_row;
    else
      tunjuks = tunjuks->next_row;


    scanf("%s", matkuls.namaBarang);
    addFirstK(matkuls.namaBarang, tunjuks);

    scanf("%s", matkuls.namaBarang);
    addLastK(matkuls.namaBarang, tunjuks);

    scanf("%s", matkuls.namaBarang);
    addAfterK(tunjuks->first_col->next_col, matkuls.namaBarang);

    scanf("%s", matkuls.namaBarang);
    addFirstK(matkuls.namaBarang, tunjuks);
  }

  delAfterK(L.first_row->next_row->first_col->next_col);
  delFirstB(&L);
  delFirstK(L.first_row);
  printElement(L);
  delAllB(&L);
  printElement(L);

}
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM5 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

#include "header.h"

void createList(list *L) { (*L).first_row = NULL; }

// Count Elemen Baris
int countElementB(list L) {
  int hasil = 0;

  if (L.first_row != NULL) {
    // list tidak kosong
    eBaris* bantu;

    // inisialisasi
    bantu = L.first_row;
    while (bantu != NULL) {
      // proses
      hasil += 1;

      // iterasi
      bantu = bantu->next_row;
    }
  }
  return hasil;
}

// Count Elemen Kolom
int countElementK(eBaris L) {
  int hasil = 0;

  if (L.first_col != NULL) {
    // list tidak kosong

    eKolom* bantu;

    // inisialisasi
    bantu = L.first_col;

    while (bantu != NULL) {
      // proses
      hasil += 1;

      // iterasi
      bantu = bantu->next_col;
    }
  }
  return hasil;
}

// Addfirst untuk Baris
void addFirstB(char nim[], char nama[], list *L) {
  eBaris* baru;
  baru = (eBaris *) malloc (sizeof (eBaris));
  strcpy(baru->kontainer.nim, nim);
  strcpy(baru->kontainer.nama, nama);
  baru->first_col = NULL;

  if((*L).first_row == NULL)
    baru->next_row = NULL;
  else
    baru->next_row = (*L).first_row;
  
  (*L).first_row = baru;
  baru = NULL;
}

// Addfirst untuk Kolom
void addFirstK(char namaBarang[], eBaris *L) {
  eKolom* baru;
  baru = (eKolom *) malloc (sizeof (eKolom));
  strcpy(baru->kontainer_col.namaBarang, namaBarang);

  if((*L).first_col == NULL)
    baru->next_col = NULL;
  else
    baru->next_col = (*L).first_col;
  
  (*L).first_col = baru;
  baru = NULL;
}

// Addafter untuk Baris
void addAfterB(eBaris *prev, char nim[], char nama[]) {
  eBaris* baru;
  baru = (eBaris *) malloc (sizeof (eBaris));
  strcpy(baru->kontainer.nim, nim);
  strcpy(baru->kontainer.nama, nama);
  baru->first_col = NULL;

  if(prev->next_row == NULL)
    baru->next_row = NULL;
  else
    baru->next_row = prev->next_row;

  prev->next_row = baru;
  baru = NULL;
}

// Addafter untuk Kolom
void addAfterK(eKolom* prev, char namaBarang[]) {
  eKolom* baru;
  baru = (eKolom *) malloc (sizeof (eKolom));
  strcpy(baru->kontainer_col.namaBarang, namaBarang);

  if(prev->next_col == NULL)
    baru->next_col = NULL;
  else
    baru->next_col = prev->next_col;
  
  prev->next_col = baru;
  baru = NULL;
}

// Addlast untuk Baris
void addLastB(char nim[], char nama[], list *L) {
  if((*L).first_row == NULL)
    // jika list adalah list kosong
    addFirstB(nim, nama, L);
  else{
    // jika list tidak kosong
    // mencari elemen terakhir list
    eBaris *last = (*L).first_row;

    while(last->next_row != NULL)
    // iterasi
      last = last->next_row;

    addAfterB(last, nim, nama);
  }
}

// Addlast untuk Kolom
void addLastK(char namaBarang[], eBaris *L) {
  if((*L).first_col == NULL)
  // jika list adalah list kosong
    addFirstK(namaBarang, L);
  else{
    // jika list tidak kosong
    // mencari elemen terakhir list
    eKolom *last = (*L).first_col;
    while(last->next_col != NULL)
      // iterasi
      last = last->next_col;

    addAfterK(last, namaBarang);
  }
}

// Delfirst untuk Kolom
void delFirstK(eBaris *L) {
  if((*L).first_col != NULL){
    // jika list bukan list kosong
    eKolom* hapus = (*L).first_col;

    if(countElementK(*L) == 1)
      (*L).first_col = NULL;
    else{
      (*L).first_col = (*L).first_col->next_col;
      hapus->next_col = NULL;
    }
    free(hapus);
  }
}

// Delafter untuk kolom
void delAfterK(eKolom* prev) {
  eKolom* hapus = prev->next_col;
  if(hapus != NULL){
    if(hapus->next_col == NULL)
      prev->next_col = NULL;
    else{
      prev->next_col = hapus->next_col;
      hapus->next_col = NULL;
    }
    free(hapus);
  }
}

// Dellast untuk Kolom
void delLastK(eBaris *L) {
  if((*L).first_col != NULL) {
    // Jika list tidak kosong
    if(countElementK(*L) == 1) {
      // Jika list terdiri dari satu elemen
      delFirstK(L);
    }else {
      // Mencari elemen terakhir list
      eKolom *last = (*L).first_col;
      eKolom *before_last;

      while (last->next_col != NULL) {
        // iterasi
        before_last = last;
        last = last->next_col;
      }
      delAfterK(before_last);
    }
  }
}

// Dellall untuk kolom
void delAllK(eBaris *L) {
  if(countElementK(*L) != 0)
    for(int i = countElementK(*L); i >= 1; i--)
      // proses menghapus elemen list
      delLastK(L);
}

// Delfirst untuk baris
void delFirstB(list *L) {
  if((*L).first_row != NULL) {
    // Jika list bukan list kosong
    eBaris *hapus = (*L).first_row;

    if(hapus->first_col != NULL) 
      // Menghapus semua elemen jika ada
      delAllK(hapus);

    if(countElementB(*L) == 1)
      (*L).first_row = NULL;
    else 
      (*L).first_row = (*L).first_row->next_row;
    
    
    hapus->next_row = NULL;
    free(hapus);
  }else
    printf("List Kosong.\n");
}

// Delafter untuk baris
void delAfterB(eBaris* prev) {
  if(prev != NULL){
    eBaris *hapus = prev->next_row;
    if(hapus != NULL){
      if(hapus->first_col != NULL)
        // Menghapus semua elemen kolom jika ada
        delAllK(hapus);
      
      if(hapus->next_row == NULL)
        prev->next_row = NULL;
      else
        prev->next_row = hapus->next_row;
      
      hapus->next_row = NULL;
      free(hapus);
    }
  }
}

// Dellast untuk Baris
void delLastB(list *L) {
  if((*L).first_row != NULL) {
    // Jika list tidak kosong
    if(countElementB(*L) == 1)
      // Jika list terdiri dari satu elemen
      delFirstB(L);
    else {
      // Mencari elemen terakhir list
      eBaris *last = (*L).first_row;
      eBaris *before_last;

      while (last->next_row != NULL){
        // Iterasi
        before_last = last;
        last = last->next_row;
      }
      delAfterB(before_last);
    }
  }
}

// DelAll untuk Baris
void delAllB(list *L) {
  if(countElementB(*L) != 0){
    for(int i = countElementB(*L); i >= 1; i--)
      // Proses menghapus elemen list
      delLastB(L);
  }
}

// Print Element
void printElement(list L) {
  if(L.first_row != NULL) {
    // Jika list tidak kosong
    // Inisialisasi
    eBaris *bantu = L.first_row;
    int i = 1;

    while (bantu != NULL) {
      // Proses

      printf("%s %s\n", bantu->kontainer.nim, bantu->kontainer.nama);
      eKolom *eCol = bantu->first_col;
      while(eCol != NULL) {
        printf("- %s\n", eCol->kontainer_col.namaBarang);
        eCol = eCol->next_col;
      }
      printf("==================\n");
      // iterasi
      bantu = bantu->next_row;
      i += 1;

    }
  }else 
    // Proses jika list kosong
    printf("list kosong\n");
}

void printRev(list L){
  if(L.first_row != NULL) {
    // Jika list tidak kosong
    // Inisialisasi
    eBaris *bantu = L.first_row;
    int i = 1;

    while (bantu != NULL) {
      // Proses

      printf("Elemen ke : %d\n", i);
      printf("Nim       : %s\n", bantu->kontainer.nim);
      printf("Nama      : %s\n", bantu->kontainer.nama);
      printf("------------\n");
      // iterasi
      

      // int m = 0;
      // eKolom *kolomgimang = bantu->first_col;
      // while(kolomgimang != NULL) {
      //   kolomgimang = kolomgimang->next_col;
      //   m++;
      // }
      // printf("m = %d\n", m);
      // for (int k = m; k > 0; k--) {
      //   kolomgimang = bantu->first_col;
      //   for (int j = 0; j < k - 1; j++)
      //     kolomgimang = kolomgimang->next_col;
        
      //   printf("- namaBarang Kuliah : %s\n", kolomgimang->kontainer_col.namaBarang);
      //   printf("- Nilai       : %s\n", kolomgimang->kontainer_col.nilai);
        
      // }
      //   bantu = bantu->next_row;
      //   i += 1;
    }
       
  }else 
    // Proses jika list kosong
    printf("List Kosong.\n");

}
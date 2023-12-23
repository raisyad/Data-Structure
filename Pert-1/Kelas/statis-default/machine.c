#include"header.h"

void createList(list *L) {
    (*L).first = -1;
    int i;
    
    for (i = 0; i < 10; i++) (*L).data[i].next = -2; // <-- Proses menginisialisasi isi dari array berdasarkan List
}

int countElement(list L) {
    int hasil = 0;
    if (L.first != -1) {
      // List tidak kosong
        int hitung;

        // Menginisialisasi bahwa hitung sama dengan list first
        hitung = L.first;

        while(hitung != -1) {
          // proses penghitungan 
            hasil += 1;
          
          // Jika dia bukan null, maka iterasi
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

int emptyElement(list L) {
    int hasil = -1; //default value, mengecek apakah null atau tidak

    if (countElement(L) < 10) { //ngehitung elemen sebanyak 10 atau arahan
        int ketemu = 0;
        int i = 0;

        while ((ketemu == 0) && (i < 10)) {
            if (L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            }else i += 1;
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L) {
    if (countElement(*L) < 10) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);
        if ((*L).first == -1) (*L).data[baru].next = -1; //Jika list yang ada itu kosong, maka data yang dimasukkan mempunyai value next = NULL
        else (*L).data[baru].next = (*L).first; //Jika list tidak kosong, maka sidata baru next menyapa first

        (*L).first = baru; //Kemudian, barulah first dari yang sebelumnya berpindah ke data baru tadi.
    }else printf ("sudah tidak dapat ditambah\n"); //Jika data yang diinputkan melebihi patokan awal, maka data tidak bisa ditambah kembali
}

void addAfter (int prev, char nim[], char nama[], char nilai[], list *L){
  if (countElement(*L) < 10) {
    int baru = emptyElement(*L);
      strcpy((*L).data[baru].kontainer.nim, nim);
      strcpy((*L).data[baru].kontainer.nama, nama);
      strcpy((*L).data[baru].kontainer.nilai, nilai);

      if((*L).data[prev].next == -1) { // Jika prev next yang dituju tidak mempunyai list selanjutnya atau kata lain yaitu NULL
        // Maka, set baru next = -1
        (*L).data[baru].next = -1;
      }else { //Jika prev next yang dituju merupakan ditengah atau diawal, maka
        (*L).data[baru].next = (*L).data[prev].next;
      }
      (*L).data[prev].next = baru;
  }else printf ("sudah tidak dapat ditambah\n"); //jika array atau alokasi arahan sudah penuh
}

void addLast(char nim[], char nama[], char nilai[], list *L) {
  if ((*L).first == -1) addFirst(nim, nama, nilai, L); //Proses jika list masih kosong
  else { //Jika list yang dituju telah berisi elemen, maka...
    if (countElement(*L) < 10) {
      int prev = (*L).first;

      while ((*L).data[prev].next != -1) prev = (*L).data[prev].next;
      addAfter(prev, nim, nama, nilai, L);
    }else printf ("sudah tidak dapat ditambah\n");
  }
}

void delFirst(list *L){
  if ((*L).first != -1) { //Jika terdapat banyak elemen, maka
    int hapus = (*L).first; //set value list first ke hapus
    if (countElement(*L) == 1) { //jika elemen hanya 1
      (*L).first = -1; //maka -> set first nya null
    }else { // jika elemennya banyak
      (*L).first = (*L).data[hapus].next; //list dengan array first next ditimpa ke list first tadi
    }
    (*L).data[hapus].next = -2; //set list data dengan array hapus next = -2
  }else printf ("List kosong\n");
}

void delAfter(int prev, list *L) {
  int hapus = (*L).data[prev].next;

  if (hapus != -1){
    if ((*L).data[hapus].next == -1) (*L).data[prev].next = -1;
    else (*L).data[prev].next = (*L).data[hapus].next;
    
    (*L).data[hapus].next = -2;
  }
}

void delLast(list *L) {
  if ((*L).first != -1) {
    if (countElement(*L) == 1) delFirst(L);
    else {
      int hapus = (*L).first;
      int prev;

      while ((*L).data[hapus].next != -1) {
        // iterasi
        prev = hapus;
        hapus = (*L).data[hapus].next;
      }
      delAfter(prev, L);
    }
  }else printf ("list kosong\n");
}

void delAll(list *L) {
  int i; 
  for (i = countElement(*L); i >= 1; i--) delLast(L);
}

void printElement(list L) {
    if (L.first != -1) {
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1) {
            printf ("============\n");
            printf ("elemen ke : %d\n", i);
            printf ("nim : %s\n", L.data[tunjuk].kontainer.nim);
            printf ("nama : %s\n", L.data[tunjuk].kontainer.nama);
            printf ("nilai : %s\n", L.data[tunjuk].kontainer.nilai);
            printf("next : %d\n", L.data[tunjuk].next);
            printf ("============\n");

            tunjuk = L.data[tunjuk].next;
            i += 1;
        }
    }else printf ("list kosong\n");
}
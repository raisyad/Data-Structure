#include<stdio.h>
#include<string.h>

typedef struct {
  char nim[10];
  char nama[50];
  char nilai[2];
}nilaiMatkul;

typedef struct {
  nilaiMatkul kontainer;
  int next;
  int prev;
}elemen;

typedef struct {
  int first;
  int tail;
  elemen data[10];
}list;

void createList(list *L) {
  (*L).first = -1;
  (*L).tail = -1;
  int i;
  
  for (i = 0; i < 10; i++) {
    (*L).data[i].prev = -2;
    (*L).data[i].next = -2;
  } // <-- Proses menginisialisasi isi dari array berdasarkan List
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
      if ((*L).first == -1) {
        (*L).data[baru].prev = -1;
        (*L).data[baru].next = -1;
        (*L).tail = baru;
      } else {
        (*L).data[baru].prev = -1;
        (*L).data[baru].next = (*L).first;
        (*L).data[(*L).first].prev = baru;
      }

      (*L).first = baru; //Kemudian, barulah first dari yang sebelumnya berpindah ke data baru tadi.
  }else printf ("sudah tidak dapat ditambah\n"); //Jika data yang diinputkan melebihi patokan awal, maka data tidak bisa ditambah kembali
}

void addAfter (int before, char nim[], char nama[], char nilai[], list *L){
  if (countElement(*L) < 10) {
    int baru = emptyElement(*L);
    strcpy((*L).data[baru].kontainer.nim, nim);
    strcpy((*L).data[baru].kontainer.nama, nama);
    strcpy((*L).data[baru].kontainer.nilai, nilai);
    if (before != -1){
      if ((*L).data[before].next != -1) {
        (*L).data[before].prev = before;
        (*L).data[baru].next = (*L).data[before].next;
        (*L).data[before].next = baru;
        (*L).data[(*L).data[baru].next].prev = baru;
      }else {
        (*L).data[baru].prev = before;
        (*L).data[before].next = baru;
        (*L).data[baru].next = -1;
        (*L).tail = baru;
      }
    }else {

    }
  }else printf ("sudah tidak dapat ditambah\n"); //jika array atau alokasi arahan sudah penuh
}

void addLast(char nim[], char nama[], char nilai[], list *L) {
  if ((*L).first == -1) addFirst(nim, nama, nilai, L); //Proses jika list masih kosong
  else { //Jika list yang dituju telah berisi elemen, maka...
    if (countElement(*L) < 10) {
      addAfter((*L).tail, nim, nama, nilai, L);
    }else printf ("sudah tidak dapat ditambah\n");
  }
}

void delFirst(list *L){
  if ((*L).first != -1) { //Jika terdapat banyak elemen, maka
    int hapus = (*L).first; //set value list first ke hapus
    if (countElement(*L) == 1) { //jika elemen hanya 1
      (*L).first = -1; //maka -> set first nya null
      (*L).tail = -1;
    }else { // jika elemennya banyak
      (*L).first = (*L).data[(*L).first].next; //list dengan array first next ditimpa ke list first tadi
      (*L).data[(*L).first].prev = -1;
    }
    (*L).data[hapus].prev = -2;
    (*L).data[hapus].next = -2;
  }else printf ("List kosong\n");
}

void delAfter(int before, list *L) {
  if (before != -1) {
    int hapus = (*L).data[before].next;
    if (hapus != -1){
      if ((*L).data[hapus].next == -1) {
        (*L).tail = before;
        (*L).data[before].next = -1;
      }else {
        (*L).data[before].next = (*L).data[hapus].next;
        (*L).data[(*L).data[hapus].next].prev = before;
      }
      (*L).data[hapus].next = -2;
      (*L).data[hapus].prev = -2;
    }
  }
}

void delLast(list *L) {
  if ((*L).first != -1) {
    if (countElement(*L) == 1) delFirst(L);
    else {
      delAfter((*L).data[(*L).tail].prev, L);
    }
  }else printf ("list kosong\n");
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

void TukerFor(list *L) {
  elemen temp;
  int depan, belakang;
  depan = (*L).first;
  belakang = (*L).tail;

  for (int i = 0; i < p; i++) {
    temp.kontainer = (*L).data[depan].kontainer;
    (*L).data[depan].kontainer = (*L).data[belakang].kontainer;
    (*L).data[belakang].kontainer = temp.kontainer;
    depan = (*L).data[depan].next;
    belakang = (*L).data[belakang].prev;
  }
}

void Tuker(list *L) {
  elemen temp, depan;
  depan.kontainer = (*L).data[(*L).first].kontainer;
  (*L).data[(*L).first].kontainer = (*L).data[(*L).tail].kontainer;
  (*L).data[(*L).tail].kontainer = depan.kontainer;
}

void Tuker2(list *L) {
  elemen temp, depan;
  depan.kontainer = (*L).data[(*L).data[(*L).first].next].kontainer;
  (*L).data[(*L).data[(*L).first].next].kontainer = (*L).data[(*L).data[(*L).tail].prev].kontainer;
  (*L).data[(*L).data[(*L).tail].prev].kontainer = depan.kontainer;
}

void Tuker3(list *L) {
  elemen temp, depan;
  depan.kontainer = (*L).data[(*L).data[(*L).data[(*L).first].next].next].kontainer;
  (*L).data[(*L).data[(*L).data[(*L).first].next].next].kontainer = (*L).data[(*L).data[(*L).data[(*L).tail].prev].prev].kontainer;
  (*L).data[(*L).data[(*L).data[(*L).tail].prev].prev].kontainer = depan.kontainer;
}

int main(void) {
    list L;
    createList(&L);
    printf ("================\n");
    addLast("1", "Orang_1", "A", &L);
    addLast("2", "Orang_2", "B", &L);
    addLast("3", "Orang_3", "C", &L);
    addLast("4", "Orang_4", "D", &L);
    addLast("5", "Orang_5", "E", &L);
    addLast("6", "Orang_6", "F", &L);
    printElement(L);
    printf ("================\n\n\n");
    TukerFor(&L);
    // Tuker(&L);
    // Tuker2(&L);
    // Tuker3(&L);
    
    printElement(L);
}
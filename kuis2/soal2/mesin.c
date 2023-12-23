// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis2 qufree22 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// Membuat Queue Kosong
void createEmpty(queue *Q) {
  (*Q).first = NULL;
  (*Q).last = NULL;
}

// Mengecek apakah queue kosong atau tidak
int isEmpty(queue Q) {
  int hasil = 0;
  if(Q.first == NULL) //Jika queue kosong, maka...
      hasil = 1;
  return hasil;
}

// Menghitung element pada sebuah queue
int countElement(queue Q) {
  int hasil = 0;
  // Jika Queue tidak kosong
  if(Q.first != NULL) {
      elemen* bantu;
      bantu = Q.first; //Inisialisasi 

      while(bantu != NULL){
        // Proses
        hasil++;

        // iterasi
        bantu = bantu->next;
      }

  }
  return hasil;
}

// Menginputkan/Memasukkan elemen pada sebuah queue
void add(IsiKontainer input, queue *Q) {
  elemen* baru;
  baru = (elemen *) malloc (sizeof (elemen));

  baru->kontainer = input;

  baru->next = NULL;

  if((*Q).first == NULL) //Jika queue tersebut kosong, maka...
    (*Q).first = baru;
  else //Jika queue tersebut terdapat elemennya, maka...
    (*Q).last->next = baru;

  (*Q).last = baru;
  baru = NULL;
}

// Menginputkan/Memasukkan elemen dengan metode yang diprioritaskan
void PrioAdd(IsiKontainer input, queue *Q, int priorityAntrian) {
  elemen* baru;
  elemen* tunjuk;
  baru = (elemen *) malloc (sizeof (elemen));

  baru->kontainer = input;
  baru->next = NULL;

  if(countElement(*Q) != 0) { //Jika queue tersebut tidak kosong, maka..
      tunjuk = (*Q).first;
      if(countElement(*Q) < priorityAntrian) //Cek terlebih dahulu, apakah isi elemen yang ada pada queue lebih kecil dari yang diprioritaskan atau tidak
          add(input, Q); // Jika iya, inputkan seperti biasa
      else  { // Jika tidak lebih kecil, maka...
          if(priorityAntrian - 2 < 0) { //Cek terlebih dahulu jika prioritas dikurang 2 tadi < 0
              baru->next = (*Q).first;
              (*Q).first = baru;
          }
          else{ // Jika tidak, maka..
              for(int i = 0; i < priorityAntrian - 2; i++) // Lakukan iterasi tunjuk, sebanyak prio - 2
                  tunjuk = tunjuk->next;
              // Lakukan proses pointer
              baru->next = tunjuk->next;
              tunjuk->next = baru;
          }
        baru = NULL;
      }
  }else //Jika queue tersebut kosong, maka...
    add(input, Q);
}

// Mendelete sebuah elemen didalam queue
void del(queue *Q) {
  // Jika queue tersebut bukan queue kosong
  if((*Q).first != NULL){
    elemen *hapus = (*Q).first;
    if(countElement(*Q) == 1){
        (*Q).first = NULL;
        (*Q).last = NULL;
    }else{
        (*Q).first = (*Q).first->next;
        hapus->next = NULL;
    }
    free(hapus);
  }
}

// Mendelete dari stack yang satu dan memasukkan/menginputkan ke stack yang lainnya
void DeltoInS(queue *Q, queue *Q2) {
  // Jika queue bukan queue kosong
  if((*Q).first != NULL){
    elemen *tunjuk = (*Q).first;
    elemen *tunjukin = (*Q2).last;
    if(countElement(*Q) == 1) {
        (*Q).first = NULL;
        (*Q).last = NULL;
    }
    else
    {
        (*Q).first = (*Q).first->next;
    }
    if((*Q2).first == NULL)
    {
        (*Q2).first = tunjuk;
        tunjuk->next = NULL;
        (*Q2).last = tunjuk;
    }
    else if(countElement(*Q2) >= 1)
    {
        tunjukin->next = tunjuk;
        tunjuk->next = NULL;
        (*Q2).last = tunjuk;
    }
  }
}

// Mendelete elemen terakhir, tapi masih error bu, ini template raisyad latihan hehe
void delLast(queue *Q) {
  if((*Q).first != NULL) {
    elemen *hapus = (*Q).first, *tunjuk = NULL;
    if(countElement(*Q) == 1)
      del(Q);
    else{
      while(hapus->next != NULL) {
        if (hapus!= NULL) {
          hapus = hapus->next;
          tunjuk = hapus;
        }
      }
      tunjuk->next = NULL;
    }
  }
}

// Prosedur menampilkan elemen antrian
void printQueue(queue Q) {
  if(Q.first != NULL) {
    elemen* bantu = Q.first;
    int i = 1;
    while(bantu != NULL){
        printf("%s %s %d\n", bantu->kontainer.NameofClient, bantu->kontainer.TypeWork, bantu->kontainer.Prio);
        bantu = bantu->next;
        i = i + 1;
    }
  }
}
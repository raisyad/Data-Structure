// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM7 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createEmpty(queue *Q) {
  (*Q).first = NULL;
  (*Q).last = NULL;
}

int isEmpty(queue Q) {
  int hasil = 0;
  if(Q.first == NULL)
      hasil = 1;
  return hasil;
}

int countElement(queue Q) {
  int hasil = 0;
  if(Q.first != NULL){
      /* queue tidak kosong */
      elemen* bantu;
      /* inisialisasi */
      bantu = Q.first;

      while(bantu != NULL){
          /* proses */
          hasil= hasil + 1;

          /* iterasi */
          bantu = bantu->next;
      }

  }
  return hasil;
}

void add(IsiKontainer input, queue *Q) {
  elemen* baru;
  baru = (elemen *) malloc (sizeof (elemen));

  baru->kontainer = input;

  baru->next = NULL;

  if((*Q).first == NULL)
    (*Q).first = baru;
  else
    (*Q).last->next = baru;

  (*Q).last = baru;
  baru = NULL;
}

void addPriority(IsiKontainer input, queue *Q, int p) {
  elemen* baru;
  elemen* tunjuk;
  baru = (elemen *) malloc (sizeof (elemen));

  baru->kontainer = input;
  baru->next = NULL;

  if(countElement(*Q) != 0) {
      tunjuk = (*Q).first;
      if(countElement(*Q) < p)
          add(input, Q);
      else  {
          if(p-2 < 0) {
              baru->next = (*Q).first;
              (*Q).first = baru;
          }
          else{
              for(int i = 0; i<p-2; i++)
                  tunjuk = tunjuk->next;
              
              baru->next = tunjuk->next;
              tunjuk->next = baru;
          }
      }
      baru = NULL;
  }else
    add(input, Q);
}

void del(queue *Q) {
  if((*Q).first != NULL){
    /* jika queue bukan queue kosong */
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

void DeltoInS(queue *Q, queue *Q2) {
  if((*Q).first != NULL){
    /* jika queue bukan queue kosong */
    elemen *tunjuk = (*Q).first;
    elemen *tunjukin = (*Q2).last;
    if(countElement(*Q) == 1)
    {
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
      printf("hai\n");
    }
  }
}

void printQueue(queue Q) {
  if(Q.first != NULL) {
    // printf("Bantuan Tersalurkan:\n");
    elemen* bantu = Q.first;
    int i = 1;
    while(bantu != NULL){
        printf("%s %d %s %d\n", bantu->kontainer.Name, bantu->kontainer.Prio, bantu->kontainer.City, bantu->kontainer.danaBantuan);
        bantu = bantu->next;
        i = i + 1;
    }
  }else
    printf("KOSONG\n");
}
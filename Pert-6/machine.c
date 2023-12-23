#include "header.h"

void createEmpty(stack *S){ (*S).top = NULL; }

int isEmpty(stack S) {
    
  int hasil = 0;
  if(S.top == NULL)
    hasil = 1;
  
  return hasil;
}

int countElement(stack S) {

  int hasil = 0;

  if(S.top != NULL){
    /* stack tidak kosong */

    elemen* bantu;
    /* inisialisasi */
    bantu = S.top;

    while(bantu != NULL) {
      /* proses */
      hasil++;
      /* iterasi */
      bantu = bantu->next;
    }
  }
  return hasil;
}

void push(data input, stack *S) {
    
  elemen* baru;
  baru = (elemen *) malloc (sizeof (elemen));

  baru->kontainer = input;
  
  if((*S).top == NULL)
    //jika stack kosong
    baru->next = NULL;
  else
    //jika stack tidak kosong
    baru->next = (*S).top;
  
  (*S).top = baru;
  baru = NULL;
}

void pop(stack *S) {
  if((*S).top != NULL){
    /*jika stack bukan list kosong*/
    elemen *hapus = (*S).top;

    if(countElement(*S) == 1)
        (*S).top = NULL;
    else
        (*S).top = (*S).top->next;
    
    hapus->next = NULL;
    free(hapus);
  }
}

void printStack(stack S) {

  printf("---------------\n");
  if(S.top != NULL){
      
    elemen* bantu = S.top;
    while(bantu != NULL){
        printf("%s %s %s\n", bantu->kontainer.nim, bantu->kontainer.nama, bantu->kontainer.nilai);

        /* iterasi */
        bantu = bantu->next;
    }
  }
  else
    /* proses jika stack kosong */
    printf("Stack Kosong.\n");
}
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM5 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void){
  list L;
  createList(&L);

  int posInt[101], n;
  scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &posInt[i]);
  }

  int mIter = 1, markB = 0, z = 0, markEl = 0;
  eBaris *tunjuks = NULL;
  eKolom *eCol = NULL;
  for (int i = 1; i <= 9; i++) {
    markB = 0;
    markEl = 0;
    if (mIter == 1){
      for (int x = 0; x < n; x++) {
        if (posInt[x] == 1){
          if (markB == 1) {
            eCol = tunjuks->first_col;
            while(eCol != NULL) {
              if (posInt[x] == eCol->kontainer_col.ValueLOL) {
                markEl = 1;
              }
              eCol = eCol->next_col;
            }
            if (markEl == 0) {
              addLastK(posInt[x], tunjuks);
            }
          }
          if (markB == 0) {
            addLastB(mIter, &L);
              if (i == 1)
                tunjuks = L.first_row;
            addLastK(posInt[x], tunjuks);
            markB = 1;
          }
        }
      }
    }else {
      for(int x = 0; x < n; x++) {
        markEl = 0;
        if (posInt[x] % mIter == 0) {
          int y = 0;
          if (markB == 1) {
            eCol = tunjuks->first_col;
            while(eCol != NULL) {
              if (posInt[x] == eCol->kontainer_col.ValueLOL) {
                markEl = 1;
              }
              eCol = eCol->next_col;
            }
            if (markEl == 0) {
              addLastK(posInt[x], tunjuks);
            }
          }
          if (markB == 0) {
            addLastB(mIter, &L);
            if (i != 1 && tunjuks != NULL){
              tunjuks = tunjuks->next_row;
            } 
            else 
              tunjuks = L.first_row;
            addLastK(posInt[x], tunjuks);
            markB = 1;
          }
        }
      }
    }
    mIter++;
  }
  printElement(L);

}
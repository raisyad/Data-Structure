#include "header.h"

int main(void){
  list L;
  createList(&L);
  printElement(L);
  printf("=================\n\n");

  addFirstB("1", "Raisyad", &L);
  addFirstK("IF40K1", "A", L.first_row);
  addAfterK(L.first_row->first_col, "IF40Z3","A");
  // addLastK("IF40Z2", "A", L.first_row);


  // addAfterB(L.first_row, "2", "Aceng_Goblok");
  // addFirstK("TI5141", "C", L.first_row->next_row);
  // addLastK("IF5021", "C",L.first_row->next_row);


  // addLastB("3", "Orang_3", &L);
  // addFirstK("IF5321", "A",L.first_row->next_row->next_row);
  printElement(L);
  printf("=================\n\n\n");
  // delFirstB(&L);
  // delAfterB(L.first_row);
  // delLastB(&L);
  
  // delAllB(&L);
  printRev(L);
  printf("=================\n");

}
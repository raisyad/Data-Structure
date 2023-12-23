#include "header.h"

int main(void){
  list L;
  createList(&L);
  IsiContainerRow Company;
  IsiContainerCol Barang;
  int n,m;
  
  eBaris *RowCur;
  char From[101], FromNumber[101], To[101], ToNumber[101];

  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    scanf("%s", &Company.NameOfCompany);
    addLastB(Company, &L);
    if (i == 0)
      RowCur = L.first_row;
    else
      RowCur = RowCur->next_row;

    scanf ("%d", &m);
    for (int z = 0; z < m; z++) {
      scanf ("%s %s", &Barang.TypeBarang, &Barang.CodeBarang);
      addLastK(Barang, RowCur);
    }
  }

  scanf ("%s %s", &From, FromNumber);
  scanf ("%s %s", &To, ToNumber);

  PrintEl(L);
  SwapElement(&L,From,FromNumber,To,ToNumber);
  printf("\n\n===============\n\n");
  PrintEl(L);
  // printf("\n\nYang sudah disortingya\n");
  // SortElRowAsc(&L, Company);
  // SortElRowDesc(&L, Company);
  // PrintEl(L);
  // printf("--%s %s--\n", From, FromNumber);

  // int CounterRow = 1, CounterCol = 1, KetemuRowCurr = 0, KetemuRowTo = 0, KetemuCol = 0, CounterMoveB = 0;
  // eBaris *CurrRow = L.first_row, *ToRow, *CurrRowTJ, *ToRowTJ, *Temp1;
  // eKolom *CurrCol, *CurrColTJ, *ToColTJ;

  // eBaris *TempPrevCurr, *TempPrevTo, *TempSwap;

  // while (CurrRow != NULL){
  //   if ((strcmp(From, CurrRow->kontainer.NameOfCompany) == 0) || (strcmp(ToRow, CurrRow->kontainer.NameOfCompany) == 0)){
  //     if (KetemuRowCurr == 0) {
  //       CurrRowTJ = CurrRow;
  //       KetemuRowCurr = 1;
  //       CounterMoveB++;
  //     }
  //     if (KetemuRowTo == 0) {
  //       ToRowTJ = CurrRow;
  //       KetemuRowTo = 1;
  //       CounterMoveB++;
  //     }

  //     if (CounterMoveB == 2) {
  //       while (TempPrevTo->next_row != ToRowTJ) {
  //         TempPrevTo = TempPrevTo->next_row;
  //       }

  //       if(TempPrevCurr == NULL) {
  //         if (TempPrevTo == CurrRowTJ) {
  //             (*L).first_row = ToRowTJ;           
  //             CurrRowTJ->next_row = ToRowTJ->next_row;  
  //             ToRowTJ->next_row = CurrRowTJ;        
  //         }else {
  //             (*L).first_row = CurrRowTJ->next_row;   
  //             CurrRowTJ->next_row = ToRowTJ->next_row;  
  //             ToRowTJ->next_row = CurrRowTJ;        
  //             TempPrevTo->next_row = ToRowTJ->next_row;  
  //             ToRowTJ->next_row = (*L).first_row;    
  //             (*L).first = ToRowTJ;          
  //         }
  //     }else { 
  //         if (TempPrevTo == CurrRowTJ) {
  //             TempPrevCurr->next_row = ToRowTJ;          
  //             CurrRowTJ->next_row = ToRowTJ->next_row;  
  //             ToRowTJ->next_row = CurrRowTJ;        
  //         }else {
  //             TempPrevCurr->next_row = CurrRowTJ->next_row;  
  //             CurrRowTJ->next_row = ToRowTJ->next_row;  
  //             ToRowTJ->next_row = CurrRowTJ;        
  //             TempPrevTo->next_row = ToRowTJ->next_row;  
  //             ToRowTJ->next_row = TempPrevCurr->next_row;    
  //             TempPrevCurr->next_row = ToRowTJ;          
  //         }
  //       }
  //       TempSwap = CurrRowTJ;
  //       CurrRowTJ = ToRowTJ;
  //       ToRowTJ = TempSwap;
  //     }
  //   }
  //   TempPrevCurr = CurrRow;
  //   CurrRow = CurrRow->next_row;
  //   CounterRow++;
  // }



      // CurrCol = CurrRow->first_col;
      // while (CurrCol != NULL) {
      //   if (KetemuCol == 0) {
      //     if (strcmp(FromNumber, CurrCol->kontainer_col.CodeBarang) == 0){
      //       printf("%d - Col\n", CounterCol);
      //       KetemuCol = 1;      
      //     }
      //   }
      //   CurrCol = CurrCol->next_col;
      //   CounterCol++;
      // }








  // printf("=================\n\n");

  // addFirstB("1", "Raisyad", &L);
  // addFirstK("IF40K1", "A", L.first_row);
  // addAfterK(L.first_row->first_col, "IF40Z3","A");
  // addLastK("IF40Z2", "A", L.first_row);


  // addAfterB(L.first_row, "2", "Aceng_Goblok");
  // addFirstK("TI5141", "C", L.first_row->next_row);
  // addLastK("IF5021", "C",L.first_row->next_row);


  // addLastB("3", "Orang_3", &L);
  // addFirstK("IF5321", "A",L.first_row->next_row->next_row);
  // printElement(L);
  // printf("=================\n\n\n");
  // delFirstB(&L);
  // delAfterB(L.first_row);
  // delLastB(&L);
  
  // delAllB(&L);
  // printRev(L);
  // printf("=================\n");

}
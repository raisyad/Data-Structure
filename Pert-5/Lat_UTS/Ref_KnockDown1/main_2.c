#include "bismillah.h"


int main(){
  list L;
  createListbaris(&L);
  int n;
  scanf("%d", &n);
  databaris data1;
  datakolom data2;
  eBaris* asoy = L.first;
  char labelkolom1[100]; //->ini elemen yang ada di baris awal
  char labelkolom2[100]; //->ini elemen yang ada di baris tujuan
  char labelbaris1[100]; //->ini baris awal
  char labelbaris2[100]; //->ini baris tujuan
  // for(int i=0; i<n; i++)
  // {
  //   scanf("%s %s", data1.kb,data1.kb2);
  // }
  // char x[100],y[100],z[100];
  // coba(n, &L);
  for (int i=0; i<n; i++)
  {
    scanf("%s %s",data1.kb,data1.kb2);
    addLastbaris(data1, &L);
    if(i==0)
    {
      asoy = L.first;
    }
    else{
      asoy = asoy->next;
    }
    do
    {
      scanf("%s", &data2.kk);
      if(strcmp(data2.kk, "end") != 0)
      {
        addLastkolom(data2, asoy);
      }

    } while (strcmp(data2.kk, "end") != 0);
    
    // for(int j=0; j<4; j++)
    // {
    //   scanf("%s", data2.kk);
    //   addLastkolom(data2, asoy);
    // }
  }
  // scanf untuk mindahin satu elemn
  //scanf("%s", &labelbaris1);
  //scanf("%s", &labelkolom1);
  //scanf("%s", &labelbaris2);
  //

  // scanf untuk menukar elemen
  scanf("%s", &labelbaris1);
  scanf("%s", &labelkolom1);
  scanf("%s", &labelbaris2);
  scanf("%s", &labelkolom2);
  

  /*
  3
  box_baju bb01
  kemeja
  baju tidur
  bangun
  end
  box_celana bc02
  jeans
  jogger
  pagi
  end
  box_nasi bn03
  kuning
  uduk
  end
  box_baju kemeja
  box_nasi
  */
  // char mekismekdown[100];
  // scanf("%s", &mekismekdown);
  // sorting(&L);
  // sorting(&L);
  // sortingkolomall(&L);
  // printElement(L);
  // tukarFirst(labelbaris1, labelbaris2, labelkolom1, &L);
  // tukarFirst(labelbaris2, labelbaris1, labelkolom2, &L);
  // tukarAfter(labelbaris1, labelbaris2, labelkolom1, labelkolom2, &L);
  // tukarLast(labelbaris1, labelbaris2, labelkolom1, &L);
  printf("ini list sebelum di tukar yak :* \n");
  printf("-------------------------------------\n");
  printElement(L);
  printf("ini list setelah di tukar yak :* \n");
  printf("-------------------------------------\n");
  tukarbeneran(labelbaris1,labelbaris2,labelkolom1,labelkolom2, &L);
  printElement(L);
  // printf("ini setelah di tuker trus di sorting\n");
  // sortingkolomall(&L);
  // printElement(L);
  // printElement(L);
  // sortingkolom(&L, mekismekdown);
  // printkolom(L, mekismekdown);

}
// Saya [Raisyad Jullfikar] 2106238 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
// Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan 
// seperti yang telah dispesifikasikan. Aamiin.
#include"header.h"

int main(void){
  tree T;
  data input, find;
  char str[MAX], name[MAX], parent[MAX], price[MAX], iter[MAX];
  // Deklar str untuk inputan 1 kalimat
  // Deklar name, ortu, harga dan iterasiComponent
  int harga = 0, iterComponent = 0, LenStr[MAX], n, minPrice, curLev = 0, highestLev = -1, countLev = 0;
  // Deklar var Int
  
  scanf ("%d", &n); // Input n
  for (int i = 0; i < n; i++) {
    scanf("%s", str); // Input str/kalimat
    explodeData(str, name, parent, price, iter); // Split string
    harga = sNumtoiNum(price); // Proses stoi untuk harga
    iterComponent = sNumtoiNum(iter); // Proses stoi untuk jumlah iter component
    // Proses penginputan string sebanyak iterComponent
    for (int z = 0; z < iterComponent; z++) {
      scanf("%s", input.component[z]);
    }
    input.iterComp = iterComponent; // Proses pemindahan nilai iterComponent
    input.price = harga; // Proses pemindahan nilai harga
    // Jika parent NULL, maka dia root teratas
    if (strcmp(parent, "null") == 0) {
      input.level = 0; // Set level 0 sebagai akar
      curLev = input.level;
      strcpy(input.name, name);
      makeTree(input, &T);
    }else { // Jika parent tidak NULL, maka dia child
      strcpy(input.name, name);
      strcpy(input.child, parent);
      simpul *searchParent = findSimpul(input, T.root); // Proses pencarian simpul
      input.level = searchParent->kontainer.level + 1; // Set level +1 dari level ortunya
      input.level = input.level; // Set level
      curLev = input.level;
      addChild(input, searchParent); // Lakukan proses add
    }
    if (highestLev < curLev){ // Mencari level tertinggi
      // Digunakan untuk mereset len str, ketika ada data/str yang didelete
      highestLev++;
      countLev++;
    }
  }
  scanf ("%d", &minPrice); // Input harga
  // Before Del
  LenStrperLev(T.root, LenStr, 0); // Find str len per level
  int i = initlevel; // Set level
  // Proses sign len str
  while(LenStr[i+1] != 0) {
    LenStr[i] += LenStr[i - 1];
    i++;
  }
  printLevel(T.root, LenStr, 0); // Proses print per level
  if (T.root != NULL) {
    // Cek root NULL atau bukan
    int end = 0, markDel = 0; // Deklar end to False
    simpul *searchDel; // Deklar simpul pencari yang akan di del
    while (end != 1) {
      simpul *searchMinPrice = findMinPrice(minPrice, T.root);
      // Mencari harga yang dibawah harga inputan
      if (searchMinPrice != NULL) { // Jika tidak null, berarti ada data yang dituju
        strcpy(find.child, searchMinPrice->kontainer.name); // Proses copy
        searchDel = findSimpul(find, T.root); //Pencarian simpul
        if (searchDel != NULL) { // Proses mendelete
          delKnock(searchDel, searchMinPrice->parent); // Del
          if (markDel == 0)
            markDel = 1;
        }
      }else{ // Ketika NULL, berarti tidak ada data yang dituju
        end = 1; // Set end True, perulangan berhenti
        if (markDel == 1) // Penanda bahwa ada data yang didel
          // Reset value to 0 sebanyak i atau sebanyak level sebelumnya
          for (int k = 0; k < countLev; k++){
            LenStr[k] = 0;
            if (k == countLev-1)
              printf("\n");
        }
      }
    }
  }
  // After Del
  LenStrperLev(T.root, LenStr, 0); // Find str len per level
  i = initlevel; // Set level
  // Proses sign len str
  while(LenStr[i+1] != 0) {
    LenStr[i] += LenStr[i - 1];
    i++;
  }
  printLevel(T.root, LenStr, 0); // Proses print per level
}
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP4 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include"header.h"

int main(){
  tree T; //Create Tree
  data input, find, findName; // Deklar var bungkusan
  int output = 1, markDone = 0; //Mark output persis soal
  // -------------- ^ -> Penanda inputan sudah beres
  // Proses input dan sign to tree 
  do {
    int len = 0;
    scanf("%s", &input.name);
    // printf("%s\n", str);
    if (strcmp(input.name, "DONE;") == 0) // Penanda input sudah selesai
      markDone = 1;
    if (markDone == 0){ // Penanda input belum selesai
      if (strcmp(input.name, "MAKETREE") == 0){ // Jika inputan adalah membuat pohon
        // Set level menjadi level 0, dan input nama dari orangtua atau root
        input.level = 0;
        scanf("%s", &input.child);

        // Proses mengubah ';' menjadi string penutup
        len = strlen(input.child);
        input.child[len-1] = '\0';
        // -----

        strcpy(find.name, input.child);
        makeTree(find, &T); // Buat pohon dengan nama inputan
      }else if (strcmp(input.name, "CHILD") == 0){
        scanf("%s", &input.child);
        scanf("%s", &input.parent);

        // Proses mengubah ';' menjadi string penutup
        len = strlen(input.parent);
        input.parent[len-1] = '\0';
        // -----

        strcpy(find.child, input.parent);
        strcpy(findName.name, input.child);

        simpul *temLev = findSimpul(find, T.root);
        // Cari parent terlebih dahulu sebelum memasukkan anaknya
        input.level = temLev->kontainer.level + 1; //level bertambah 1 dari level orangtuanya
        findName.level = input.level; // copykan atau masukkan level tadi

        addChild(findName, temLev); // add anak
      }else if (strcmp(input.name, "DELLCHILD") == 0) {
        scanf("%s", &input.child);
        scanf("%s", &input.parent);

        // Proses mengubah ';' menjadi string penutup
        len = strlen(input.parent);
        input.parent[len-1] = '\0';
        // -----
        // Proses mencari anak dan parentnya
        strcpy(find.child, input.parent); // ortu
        strcpy(findName.child, input.child); // yang akan didel
        simpul *node = findSimpul(find, T.root);
        simpul *findDel = findSimpul(findName, T.root);

        // Proses pendeletean
        delKnock(findDel, node);
      }else if (strcmp(input.name, "PREORDER;") == 0){ //Print preorder
        printf("Output %d:\n=========\n", output);
        printTreePreOrder(T.root);
        output++;
      }
    }
  }while(markDone != 1);
  printf("=========\n");
}
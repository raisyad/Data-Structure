// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP4 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include"header.h"

// Pembuatan pohon
void makeTree(data input, tree *T){
  simpul *node;
  node = (simpul *) malloc (sizeof(simpul));

  node->kontainer = input;
  node->sibling = NULL;
  node->child = NULL;
  (*T).root = node;
}

// Memasukkan anak dari parent
void addChild(data input, simpul *root){ 
  if(root != NULL){
    /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak
    */
    simpul *baru;
    baru = (simpul *) malloc (sizeof(simpul));

    baru->kontainer = input;
    baru->child = NULL;

    if(root->child == NULL){
      /* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
      baru->sibling = NULL;
      root->child = baru;
    }
    else{
      if(root->child->sibling == NULL) {
        /* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
        baru->sibling = root->child;
        root->child->sibling = baru;
      }
      else{
        simpul *last = root->child;
        /*  
          mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul 
          anak terakhir yang baru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, 
          maka selama belum sampai pada simpul anak terakhir, penunjuk last akan berjalan ke simpul anak 
          berikutnya 
        */
        while(last->sibling != root->child) {
            last = last->sibling;
        }
        baru->sibling = root->child;
        last->sibling = baru;
      }
    }
  }
}

// Menghapus semua dari root yang dituju
void delAll(simpul *root) {
  if(root != NULL){
    /* jika simpul root tidak kosong */
    if(root->child != NULL){
      if(root->child->sibling == NULL){
        /* jika hanya memiliki satu simpul anak */
        delAll(root->child);
        root->child = NULL;
      }
      else{
        simpul *bantu;
        simpul *proses;
        bantu = root->child;
        while(bantu->sibling != root->child){
          proses = bantu;
          bantu = bantu->sibling;
          delAll(proses);
        }
      }
      free(root);
    }
    else {
      free(root);
    }
  }
}

// Menghapus anak dari parent
void delKnock(simpul *del, simpul *root) {
  if (root != NULL) {
    if (root->child != NULL) {
      // Deklar simpul
      simpul *hapus = root->child;
      simpul *last = root->child;
      simpul *prev = NULL;
      if (hapus->sibling != NULL) { // If ini jalan ketika anak lebih dari 1 (>= 2)
        while (last->sibling != root->child){
          last = last->sibling;
        }
        // Jika anak pertama yang ingin di hapus
        if (hapus == del) {
          root->child = hapus->sibling;
          last->sibling = root->child;
          hapus->sibling = NULL;
          delAll(hapus);
          if (root->child == last) {
            root->child->sibling = NULL;
          }
        }
        // Syarat ketika yang dihapus bukan yang pertama (tengah atau akhir)
        if (hapus != del){
          // Proses memajukan pointer hapus, hingga berada pada kotak yang sama
          // dengan simpul del
          while (hapus->sibling != del->sibling){
            prev = hapus;
            hapus = hapus->sibling;
          }
          // Jika sudah berada pada kotak yang sama, maka lakukan proses del
          if (hapus == del) {
            prev->sibling = hapus->sibling;
            hapus->sibling = NULL;
            delAll(hapus);
          }
        }
      }else {
        // Jika satu anak dan ingin didel
        if (root->child == NULL) {
          free(root);
        }else {
          root->child = NULL;
          delAll(root->child);
        }
      }
    }
  }
}

// Mencari simpul
simpul* findSimpul(data input, simpul *root){
  simpul *hasil = NULL;
  if(root != NULL){
    // printf("hai1 - ");
    // printf("%s - %s\n", root->kontainer.name, input.value);
    if(strcmp(root->kontainer.name, input.child) == 0){
      // printf("hai2\n");
      hasil = root;
    }
    else{
      simpul *bantu = root->child;
      if(bantu != NULL){
        if(bantu->sibling == NULL){
          /*jika memiliki satu simpul anak*/
          if(strcmp(root->kontainer.name, input.child) == 0){
            hasil = bantu;
          }
          else{
            hasil = findSimpul(input, bantu);
          }
        }
        else{
          /*jika memiliki banyak simpul anak*/
          int ketemu = 0;
          while((bantu->sibling != root->child)&&(ketemu == 0)){
            if(strcmp(root->kontainer.name, input.child) == 0){
              hasil = bantu;
              ketemu = 1;
            }
            else{
              hasil = findSimpul(input, bantu);
              if (hasil != NULL) 
                ketemu = 1;
              bantu = bantu->sibling;
            }
          }
          /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
          if(ketemu == 0){
            if(strcmp(root->kontainer.name, input.child) == 0){
              hasil = bantu;
            }
            else{
              hasil = findSimpul(input, bantu);
            }
          }
        }
      }
    }
  }
  return hasil;
}

// Proses output
void printTreePreOrder(simpul *root){
  if(root != NULL){
    // Print '->' tergantung level pada data saat ini
    for (int i = 0; i < root->kontainer.level; i++) {
      printf("->");
    }
    printf("%s\n", root->kontainer.name);
    simpul *bantu = root->child;
    if(bantu != NULL){
      if(bantu->sibling == NULL){
        /*jika memiliki satu simpul anak*/
        printTreePreOrder(bantu);
      }
      else{
        /*jika memiliki banyak simpul anak*/
        /*mencetak simpul anak*/
        while(bantu->sibling != root->child){
          printTreePreOrder(bantu);
          bantu = bantu->sibling;
        }
        /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
        printTreePreOrder(bantu);
      }
    }
  }
}
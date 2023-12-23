// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include"header.h"

void makeTree(data input, tree *T){
  simpul *node;
  node = (simpul *) malloc (sizeof(simpul));

  node->kontainer = input;
  node->sibling = NULL;
  node->child = NULL;
  (*T).root = node;
}

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

void delAll(simpul *root){
  if(root != NULL){
    /* jika simpul root tidak kosong */
    if(root->child != NULL){
      if(root->child->sibling == NULL){
        /* jika hanya memiliki satu simpul anak */
        delAll(root->child);
        free(root);
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
        free(root);
      }
    }
    else{
      free(root);
    }
  }
}

void delKnock(simpul *del, simpul *root) {
  if (root != NULL){
    if (root->child != NULL) {
      simpul *hapus = root->child;
      if (hapus->sibling != NULL) {
        // Syarat ketik punya 2 anak, dan anak terakhir ingin dihapus
        simpul *last = root->child;
        while (last->sibling != root->child) {
          last = last->sibling;
        }
      }else {
        hapus = NULL;
        free(hapus);
      }
    }
  }
}

void delChild(data input, simpul *root){
  if(root != NULL){
    simpul *hapus = root->child;
    if(hapus != NULL){
      if(hapus->sibling == NULL){
        /*jika hanya mempunyai satu anak*/
        if(strcmp(root->child->kontainer.name, input.name) == 0){
          delAll(root->child);
          root->child = NULL;
        }
      }
      else{
        /*jika memiliki lebih dari satu simpul anak*/
        simpul *prev = NULL;
        /*mencari simpul yang akan dihapus*/
        int ketemu = 0;
        while((hapus->sibling != root->child) && (ketemu == 0)){
          if(strcmp(hapus->kontainer.name, input.name) == 0){
              ketemu = 1;
          }
          else{
            prev = hapus;
            hapus = hapus->sibling;
          }
        }

        /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
        if((ketemu == 0) && (strcmp(hapus->kontainer.name, input.name) == 0)){
            ketemu = 1;
        }

        if(ketemu == 1){
          simpul *last = root->child;
          /* mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir */
          while(last->sibling != root->child){
            last = last->sibling;
          }

          if(prev == NULL){
            /*jika simpul yang dihapus anak pertama*/
            if((hapus->sibling == last)&&(last->sibling == root->child)){
              /*jika hanya ada dua anak*/
              root->child = last;
              last->sibling = NULL;
            }
            else{
              /* jika memiliki simpul anak
              lebih dari dua simpul */
              root->child = hapus->sibling;
              last->sibling = root->child;
            } 
          }
          else{
            if((prev == root->child)&&(hapus->sibling == root->child)){
              /* jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua */
              root->child->sibling = NULL;
            }
            else{
              /* jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul */
              prev->sibling = hapus->sibling;
              hapus->sibling = NULL;
            }
          }
          delAll(hapus);
        }
        else{
          printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
        }
      }
    }
  } 
}

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

void printTreePreOrder(simpul *root){
  if(root != NULL){
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

void printTreePostOrder(simpul *root, int *sumNode){
  if(root != NULL){
    simpul *bantu = root->child;
    if(bantu != NULL){
      if(bantu->sibling == NULL){
        /*jika memiliki satu simpul anak*/
        printTreePostOrder(bantu, sumNode);
      }
      else{
        /*jika memiliki banyak simpul anak*/
        /*mencetak simpul anak*/
        while(bantu->sibling != root->child){
          printTreePostOrder(bantu, sumNode);
          bantu = bantu->sibling;
        }

        /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/

        printTreePostOrder(bantu, sumNode);
      }
    }
    printf("%s %s", root->kontainer.name, root->kontainer.child);
    if (root->kontainer.name && root->kontainer.child && *sumNode != 1)
        printf("-");
    *sumNode = *sumNode - 1;
  }
}

void copyTree(simpul *root1, simpul **root2){
  if(root1 != NULL){
    (*root2) = (simpul *) malloc (sizeof(simpul));
    (*root2)->kontainer = root1->kontainer;
    (*root2)->sibling = NULL;
    (*root2)->child = NULL;
    if(root1->child != NULL){
      if(root1->child->sibling == NULL){
        /*jika memiliki satu simpul anak*/
        copyTree(root1->child, &(*root2)->child);
      }else{
        /*jika memiliki banyak simpul anak*/
        simpul *bantu1 = root1->child;
        simpul *bantu2 = *root2;

        while(bantu1->sibling != root1->child){
          if(bantu2 == (*root2)){
            copyTree(bantu1, &bantu2->child);
            bantu2 = bantu2->child;
          }else{
            copyTree(bantu1, &bantu2->sibling);
            bantu2 = bantu2->sibling;
          }
          bantu1 = bantu1->sibling;
        }
        /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
        copyTree(bantu1, &bantu2->sibling);
        bantu2->sibling->sibling = (*root2)->child;
      }
    }
  }
}

int isEqual(simpul *root1, simpul *root2){
  int hasil = 1;
  if((root1 != NULL)&&(root2 != NULL)){
    if(strcmp(root1->kontainer.name, root2->kontainer.name) != 0){
      hasil = 0;
    }
    else{
      if((root1->child != NULL)&&(root2->child != NULL)){
        if(root1->child->sibling == NULL){
          /*jika memiliki satu simpul anak*/
          hasil = isEqual(root1->child, root2->child);
          if(!hasil) return 0;
        }
        else{
          /*jika memiliki banyak simpul anak*/
          simpul *bantu1 = root1->child;
          simpul *bantu2 = root2->child;

          while(bantu1->sibling != root1->child){
            if((bantu1 != NULL)&&(bantu2 != NULL)){
              hasil = isEqual(bantu1, bantu2);
              if(!hasil) return 0;
              bantu1 = bantu1->sibling;
              bantu2 = bantu2->sibling;
            }
            else{
              hasil = 0;
              break;
            }
          }
          /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
          hasil = isEqual(bantu1, bantu2);
          if(!hasil) return 0;
        }
      }
    }
  }
  else{
    if((root1 != NULL)||(root2 != NULL)){
      hasil = 0;
    }
  }
  return hasil;
}
// Saya [Raisyad Jullfikar] 2106238 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
// Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan 
// seperti yang telah dispesifikasikan. Aamiin.
#include"header.h"

// Prosedur membuat Tree
void makeTree(data input, tree *T){
  // Membuat node
  simpul *node;
  node = (simpul *) malloc (sizeof(simpul));

  // Mengisi data
  node->kontainer = input;
  // Membuat pointer anak dan saudara
  node->sibling = NULL;
  node->child = NULL;
  // Membuat pointer tambahan yaitu parent
  // Set NULL yang menandakan berarti akar atau root teratas
  node->parent = NULL;
  // Memasang node ke root
  (*T).root = node;
}

// Prosedur Menambah Child
void addChild(data input, simpul *root){ 
  if(root != NULL){
    /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak
    */
    simpul *baru;
    // Membuat node baru
    baru = (simpul *) malloc (sizeof(simpul));

    // Mengisikan data
    baru->kontainer = input;
    baru->child = NULL;

    if(root->child == NULL) {
      /* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
      baru->sibling = NULL;
      root->child = baru;
      // Set orang tua dari child yang diinputkan
      baru->parent = root;
    } else {
      if(root->child->sibling == NULL) {
        /* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
        baru->sibling = root->child;
        root->child->sibling = baru;
        // Set orang tua dari child yang diinputkan
        baru->parent = root;
      } else {
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
        // Set orang tua dari child yang diinputkan
        baru->parent = root;
      }
    }
  }
}

// Prosedur del All
void delAll(simpul *root) {
  if(root != NULL){
    /* jika simpul root tidak kosong */
    if(root->child != NULL){
      if(root->child->sibling == NULL){
        /* jika hanya memiliki satu simpul anak */
        delAll(root->child);
        root->child = NULL;
      } else { /* jika tidak hanya memiliki satu simpul anak */
        simpul *bantu;
        simpul *proses;
        bantu = root->child;
        while(bantu->sibling != root->child){
          // Selama bukan simpul ujung/terakhir
          proses = bantu;
          bantu = bantu->sibling;
          delAll(proses); //Panggil fungsinya sendiri
          // Untuk melakukan rekursif
        }
        free(root); // Free root saat ini
      }
    } else {
      free(root); // Free root saat ini
    }
  }
}

// Proses remake del child dengan pemindahan pointer
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
      }else { // jika anak tidak lebih dari 1
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

simpul* findSimpul(data input, simpul *root) {
  simpul *hasil = NULL;
  // Init hasil NULL
  // Mengecek seperti biasa, jika root tidak null
  if(root != NULL) {
    // Jika simpul root nama saat ini merupakan nama yang dicari
    if(strcmp(root->kontainer.name, input.child) == 0){
      // Maka set value hasil menjadi root saat ini
      hasil = root;
    } else { // Jika simpul root nama saat ini tidak merupakan nama yang dicari
      // Init bantu
      simpul *bantu = root->child;
      // Jika root child/bantu tidak null
      if(bantu != NULL){
        if(bantu->sibling == NULL) {
          /*jika memiliki satu simpul anak*/
          // Jika nama saat ini merupakan nama yang dicari
          if(strcmp(bantu->kontainer.name, input.child) == 0) {
            // Maka set value hasil menjadi value root bantu
            hasil = bantu;
          } else { // Jika nama saat ini bukan nama yang dicari
            hasil = findSimpul(input, bantu);
          }
        } else {
          /*jika memiliki banyak simpul anak*/
          int ketemu = 0; // Set ketemu False
          while((bantu->sibling != root->child)&&(ketemu == 0)) {
            // Selama simpul saat ini bukan simpul terakhir
            if(strcmp(bantu->kontainer.name, input.child) == 0) {
              // Jika root bantu saat ini merupakan nama yang dicari
              // Set value hasil dengan root bantu
              // Dan ketemu berubah menjadi True
              hasil = bantu;
              ketemu = 1;
            } else { // Jika root bantu saat ini bukan nama yang dicari
              hasil = findSimpul(input, bantu);
              if (hasil != NULL) // Jika hasil tidak null, maka ketemu set menjadi True
                ketemu = 1;
              bantu = bantu->sibling; // Iterasi
            }
          }
          /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
          if(ketemu == 0){
            // Jika root bantu saat ini merupakan nama yang dicari
            if(strcmp(bantu->kontainer.name, input.child) == 0){
              // Set value hasil dengan root bantu
              hasil = bantu;
            }
            else{
              // Jika root bantu saat ini bukan nama yang dicari
              hasil = findSimpul(input, bantu);
              // Lakukan rekursif
            }
          }
        }
      }
    }
  }
  return hasil;
}

// Prosed untuk mencari node harga
// Mencari node harga < dari harga inputan
simpul* findMinPrice(int price, simpul *root) {
  simpul *hasil = NULL;
  // Mengecek seperti biasa, jika root tidak null
  if(root != NULL){
    // Jika simpul root harga saat ini kurang dari harga inputan
    if(root->kontainer.price < price) {
      // Maka set value hasil menjadi root saat ini
      hasil = root;
    } else { // Ketika simpul root harga saat ini bukan kurang dari harga inputan
      // Init bantu
      simpul *bantu = root->child;
      // Jika root child/bantu tidak null
      if(bantu != NULL){
        if(bantu->sibling == NULL){
          /*jika memiliki satu simpul anak*/
          // Jika harga root saat ini kurang dari harga inputan
          if(bantu->kontainer.price < price){
            // Maka set value hasil menjadi value root bantu
            hasil = bantu;
          } else { //Jika saat ini tidak kurang dari harga inputan
            hasil = findMinPrice(price, bantu);
            // Lakukan rekursif
          }
        } else {
          /*jika memiliki banyak simpul anak*/
          int ketemu = 0; // Set ketemu False
          while((bantu->sibling != root->child) && (ketemu == 0)){
            // Selama simpul saat ini bukan simpul terakhir
            if(bantu->kontainer.price < price) {
              // Jika root harga saat ini kurang dari harga inputan maka,
              // Set value hasil dengan root bantu
              // Dan ketemu berubah menjadi True
              hasil = bantu;
              ketemu = 1;
            } else { 
              // Jika root harga saat ini tidak kurang dari harga inputan maka,
              hasil = findMinPrice(price, bantu);
              // Lakukan proses rekursif
              if (hasil != NULL) // Jika hasil tidak null, maka ketemu set menjadi True
                ketemu = 1;
              bantu = bantu->sibling; // Iterasi
            }
          }
          /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
          if(ketemu == 0) {
            // jika root harga saat ini kurang dari harga inputan
            if(bantu->kontainer.price < price){
              // Set value hasil dengan root bantu
              hasil = bantu;
            } else {
              // jika root harga saat ini tidak kurang dari harga inputan
              hasil = findMinPrice(price, bantu);
              // Lakukan rekursif
            }
          }
        }
      }
    }
  }
  return hasil;
}

// Mencari string terpanjang dari setiap levelnya
void LenStrperLev(simpul *root, int lenStr[], int level) {
  // root dicek terlebih dahulu, apakah null atau tidak seperti biasa
  if(root != NULL) {
    // init bantu
    simpul *bantu = root->child;
    // Tampung len nama saat ini + 4 (terdiri dari '', '|', '-') + panjang dari harga saat ini
    int LenName = strlen(root->kontainer.name) + 4 + findLenNum(root);
    int lenChild = 0, curLen = 0;
    //      ^                     : panjang anak diinit 0
    //                    ^       : panjang saat ini diinit 0
    // For dibawah ini adalah proses mencari string terpanjang dari anak anaknya
    for (int i = 0; i < root->kontainer.iterComp; i++) {
      // Len str child saat ini + 3 (terdiri dari, '' dan '-')
      lenChild = strlen(root->kontainer.component[i]) + 3;
      // len induk dibandingkan dengan len anak, jika len anak lebih besar ketimbang induknya, maka set ulang value len dengan value anak
      if (lenChild > LenName)
        LenName = lenChild;
      // Syarat dibawah ini akan berjalan ketika for akan berakhir
      if (i == root->kontainer.iterComp - 1)
        // State ini merupakan situasi dimana perbandingan antara panjang dari level saat ini dengan panjang saat ini
        curLen = LenName + 1; // Ditambah 1 karena membutuhkan spasi before set the value
        if(lenStr[level] < curLen)
          // Jika perbandingan len dari level saat ini kurang dari len saat ini, maka set kembali value len dari level saat ini
          lenStr[level] = curLen;
    }
    // Program dibawah ini sama seperti preorder pada umumnya, hanya saja menggunakan konsep rekurs
    // Ketika program rekurs telah selesai, level akan berkurang kembali yang asalnya increment terus menerus
    if(bantu != NULL) {
      // Syarat ketika root dari bantu memiliki anak
      if(bantu->sibling == NULL) {
        // ketika bantu memiliki satu simpul anak, maka telusuri simpul si anak
        LenStrperLev(bantu, lenStr, ++level);
        --level; // Decrement menandakan rekurs diatas telah selesai
      } else {
        // ketika bantu memiliki banyak simpul anak, maka telusuri semua simpul sianaknya
        while(bantu->sibling != root->child) {
          // While berjalan ketika saudara dari simpul sekarang bukan simpul terakhir/ujung
          LenStrperLev(bantu, lenStr, ++level);
          --level; // Decrement menandakan rekurs diatas telah selesai
          bantu = bantu->sibling; // iterasi
        }
        // memproses simpul anak terakhir karena belum terproses dalam pengulangan
        LenStrperLev(bantu, lenStr, ++level);
        --level; // Decrement menandakan rekurs diatas telah selesai
      }
    }
  }
}

// Menampilkan sesuai level
void printLevel(simpul *root, int lenStr[], int level) {
  if(root != NULL) {
    simpul *bantu = root->child; // Init bantu
    // Syarat untuk yang level 0 saja
    if (level == 0){
      // Syarat mencetak untuk level 0
      // Mencetak induknya
      printf("|%s - %d\n", root->kontainer.name, root->kontainer.price);
      // Mencetak Componentnya
      for (int z = 0; z < root->kontainer.iterComp; z++)
        printf(" - %s\n", root->kontainer.component[z]);
    } else { // Syarat untuk yang levelnya bukan 0
      // Syarat dibawah ini merupakan syarat menampilkan spasi untuk bagian nama/induk
      if(level > 0) {
        // Proses penampilan spasi dibawah ini dilakukan hanya untuk yang levelnya > 0 atau bisa >= 1
        for (int i = 0; i < lenStr[level - 1]; i++) {
          // Newline yang menandakan ia level berikutnya, yang sebelumnya menampilkan spasi
          if (i == 0)
            printf("\n");
          // Spasi dicetak sebanyak len string pada level saat ini - 1
          printf(" ");
          // Syarat dibawah ini merupakan proses pencetakan nama dengan harganya
          if (i == lenStr[level - 1] - 1)
            printf("|%s - %d\n", root->kontainer.name, root->kontainer.price);
        }
      }
      for (int z = 0; z < root->kontainer.iterComp; z++){
        if(level > 0) {
          // Proses penampilan spasi dibawah ini dilakukan hanya untuk yang levelnya > 0 atau bisa >= 1
          for (int i = 0; i < lenStr[level - 1]; i++) {
            // Spasi dicetak sebanyak len string pada level saat ini - 1
            printf(" ");
          }
        }
        // Mencetak Componentnya
        printf(" - %s\n", root->kontainer.component[z]);
      }
    }
    // Program dibawah ini sama seperti preorder pada umumnya, hanya saja menggunakan konsep rekurs
    // Ketika program rekurs telah selesai, level akan berkurang kembali dari yang asalnya increment terus menerus
    if(bantu != NULL) {
      // Syarat ketika root dari bantu memiliki anak
      if(bantu->sibling == NULL) {
        // ketika bantu memiliki satu simpul anak, maka telusuri simpul si anak
        printLevel(bantu, lenStr, ++level);
        --level; // Decrement menandakan rekurs diatas telah selesai
      } else {
        // ketika bantu memiliki banyak simpul anak, maka telusuri semua simpul sianaknya
        while(bantu->sibling != root->child) {
          // While berjalan ketika saudara dari simpul sekarang bukan simpul terakhir/ujung
          printLevel(bantu, lenStr, ++level);
          --level; // Decrement menandakan rekurs diatas telah selesai
          bantu = bantu->sibling; // iterasi
        }
        // memproses simpul anak terakhir karena belum terproses dalam pengulangan
        printLevel(bantu, lenStr, ++level);
        --level; // Decrement menandakan rekurs diatas telah selesai
      }
    }
  }
}

// Convert string Number to int Number
int sNumtoiNum(char str[]) {
  // Fungsi stoi manual in C
  int num = 0, n = strlen(str);
  //    ^                       : init num 0
  //                  ^         : init n sepanjang str harga (mis : 800, -> n = 3)
  // For dibawah ini merupakan proses stoinya, yang mana angka diconvert dari string ke int, dikurang dengan ascii angkanya sendiri,
  // dan lalu ditambah dari hasil num saat ini yang telah dikali 10
  for (int i = 0; i < n; i++) 
    num = (num * 10) + (str[i] - 48);
  // Jika proses telah selesai, kembalikan value/nilai num
  return num;
}

// Panjang harga
int findLenNum(simpul *root) {
  // Fungsi lenInt
  int len = root->kontainer.price, countDigit = 0;
  //          ^                                   : init len dengan value\nilai dari price (mis: 800, len = 800)
  //                                    ^         : init countDigit 0
  // Proses menghitung len int dengan cara membagi 10, ketika hasil bagi tersebut 0. ..., maka perulangan berhenti
  while (len != 0) {
    len /= 10;
    countDigit++;
  }
  // Jika proses countDigitnya sudah selesai, maka kembali nilai countDigit
  return countDigit;
}

// Prosedur splitter atau pemecah string
void explodeData(char word[MAX], char name[MAX], char parent[MAX], char price[MAX], char iter[MAX]) {
  int len = 0, iterParent = 0, iterPrice = 0, iterCounter = 0, counts = 0, count = 1;
  // Init all var = 0
  len = strlen(word);
  // Init len dengan panjang dari kata
  // For sepanjang kata
  for (int i = 0; i < len; i++) {
    if (counts == 0) { // Untuk bagian nama
      if (word[i] != '#') // Jika dia bukan '#' masukkan kedalam var
        name[i] = word[i];
      else if (word[i] == '#'){ // Jika dia '#' counts maju
        name[i] = '\0';
        counts++;
      }
    }else if (counts == 1) { // Untuk bagian nama simpul ortu
      if (word[i] != '#'){ // Jika dia bukan '#' masukkan kedalam var
        parent[iterParent] = word[i];
        iterParent++;
      }
      else if (word[i] == '#'){ // Jika dia '#' counts maju
        parent[iterParent] = '\0';
        counts++;
      }
    }else if (counts == 2){ // Untuk bagian nilai jual
      if (word[i] != '#'){ // Jika dia bukan '#' masukkan kedalam var
        price[iterPrice] = word[i];
        iterPrice++;
      }else if (word[i] == '#') { // Jika dia '#' counts maju
        price[iterPrice] = '\0';
        counts++;
      }
    }else if (counts == 3){ // Untuk bagian jumlah komponen
      // Tidak ada syarat '#' karena jumlah komponen merupakan
      // bagian yang paling ujung
      iter[iterCounter] = word[i];
      iterCounter++;
    }
  }
  iter[iterCounter] = '\0'; // String penutup untuk bagian count Component
}
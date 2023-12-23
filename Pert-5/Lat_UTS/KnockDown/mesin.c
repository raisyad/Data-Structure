#include "header.h"

void createList(list *L) { (*L).first_row = NULL; }

// Count Elemen Baris
int countElementB(list L) {
  int hasil = 0;

  if (L.first_row != NULL) {
    // list tidak kosong
    eBaris* bantu;

    // inisialisasi
    bantu = L.first_row;
    while (bantu != NULL) {
      // proses
      hasil += 1;

      // iterasi
      bantu = bantu->next_row;
    }
  }
  return hasil;
}

// Count Elemen Kolom
int countElementK(eBaris L) {
  int hasil = 0;

  if (L.first_col != NULL) {
    // list tidak kosong

    eKolom* bantu;

    // inisialisasi
    bantu = L.first_col;

    while (bantu != NULL) {
      // proses
      hasil += 1;

      // iterasi
      bantu = bantu->next_col;
    }
  }
  return hasil;
}

// Addfirst untuk Baris
void addFirstB(IsiContainerRow kontainer, list *L) {
  eBaris* baru;
  baru = (eBaris *) malloc (sizeof (eBaris));
  baru->kontainer = kontainer;

  baru->first_col = NULL;

  if((*L).first_row == NULL)
    baru->next_row = NULL;
  else
    baru->next_row = (*L).first_row;
  
  (*L).first_row = baru;
  baru = NULL;
}

// Addfirst untuk Kolom
void addFirstK(IsiContainerCol kontainer, eBaris *L) {
  eKolom* baru;
  baru = (eKolom *) malloc (sizeof (eKolom));
  baru->kontainer_col = kontainer;

  if((*L).first_col == NULL)
    baru->next_col = NULL;
  else
    baru->next_col = (*L).first_col;
  
  (*L).first_col = baru;
  baru = NULL;
}

// Addafter untuk Baris
void addAfterB(eBaris* prev, IsiContainerRow kontainer) {
  eBaris* baru;
  baru = (eBaris *) malloc (sizeof (eBaris));
  baru->kontainer = kontainer;

  baru->first_col = NULL;

  if(prev->next_row == NULL)
    baru->next_row = NULL;
  else
    baru->next_row = prev->next_row;

  prev->next_row = baru;
  baru = NULL;
}

// Addafter untuk Kolom
void addAfterK(eKolom* prev, IsiContainerCol kontainer) {
  eKolom* baru;
  baru = (eKolom *) malloc (sizeof (eKolom));
  baru->kontainer_col = kontainer;

  if(prev->next_col == NULL)
    baru->next_col = NULL;
  else
    baru->next_col = prev->next_col;
  
  prev->next_col = baru;
  baru = NULL;
}

// Addlast untuk Baris
void addLastB(IsiContainerRow kontainer, list *L) {
  if((*L).first_row == NULL)
    // jika list adalah list kosong
    addFirstB(kontainer, L);
  else{
    // jika list tidak kosong
    // mencari elemen terakhir list
    eBaris *last = (*L).first_row;

    while(last->next_row != NULL)
    // iterasi
      last = last->next_row;

    addAfterB(last, kontainer);
  }
}

// Addlast untuk Kolom
void addLastK(IsiContainerCol kontainer, eBaris *L) {
  if((*L).first_col == NULL)
  // jika list adalah list kosong
    addFirstK(kontainer, L);
  else{
    // jika list tidak kosong
    // mencari elemen terakhir list
    eKolom *last = (*L).first_col;
    while(last->next_col != NULL)
      // iterasi
      last = last->next_col;

    addAfterK(last, kontainer);
  }
}

// Delfirst untuk Kolom
void delFirstK(eBaris *L) {
  if((*L).first_col != NULL){
    // jika list bukan list kosong
    eKolom* hapus = (*L).first_col;

    if(countElementK(*L) == 1)
      (*L).first_col = NULL;
    else{
      (*L).first_col = (*L).first_col->next_col;
      hapus->next_col = NULL;
    }
    free(hapus);
  }
}

// Delafter untuk kolom
void delAfterK(eKolom* prev) {
  eKolom* hapus = prev->next_col;
  if(hapus != NULL){
    if(hapus->next_col == NULL)
      prev->next_col = NULL;
    else{
      prev->next_col = hapus->next_col;
      hapus->next_col = NULL;
    }
    free(hapus);
  }
}

// Dellast untuk Kolom
void delLastK(eBaris *L) {
  if((*L).first_col != NULL) {
    // Jika list tidak kosong
    if(countElementK(*L) == 1) {
      // Jika list terdiri dari satu elemen
      delFirstK(L);
    }else {
      // Mencari elemen terakhir list
      eKolom *last = (*L).first_col;
      eKolom *before_last;

      while (last->next_col != NULL) {
        // iterasi
        before_last = last;
        last = last->next_col;
      }
      delAfterK(before_last);
    }
  }
}

// Dellall untuk kolom
void delAllK(eBaris *L) {
  if(countElementK(*L) != 0)
    for(int i = countElementK(*L); i >= 1; i--)
      // proses menghapus elemen list
      delLastK(L);
}

// Delfirst untuk baris
void delFirstB(list *L) {
  if((*L).first_row != NULL) {
    // Jika list bukan list kosong
    eBaris *hapus = (*L).first_row;

    if(hapus->first_col != NULL) 
      // Menghapus semua elemen jika ada
      delAllK(hapus);

    if(countElementB(*L) == 1)
      (*L).first_row = NULL;
    else 
      (*L).first_row = (*L).first_row->next_row;
    
    
    hapus->next_row = NULL;
    free(hapus);
  }else
    printf("List Kosong.\n");
}

// Delafter untuk baris
void delAfterB(eBaris* prev) {
  if(prev != NULL){
    eBaris *hapus = prev->next_row;
    if(hapus != NULL){
      if(hapus->first_col != NULL)
        // Menghapus semua elemen kolom jika ada
        delAllK(hapus);
      
      if(hapus->next_row == NULL)
        prev->next_row = NULL;
      else
        prev->next_row = hapus->next_row;
      
      hapus->next_row = NULL;
      free(hapus);
    }
  }
}

// Dellast untuk Baris
void delLastB(list *L) {
  if((*L).first_row != NULL) {
    // Jika list tidak kosong
    if(countElementB(*L) == 1)
      // Jika list terdiri dari satu elemen
      delFirstB(L);
    else {
      // Mencari elemen terakhir list
      eBaris *last = (*L).first_row;
      eBaris *before_last;

      while (last->next_row != NULL){
        // Iterasi
        before_last = last;
        last = last->next_row;
      }
      delAfterB(before_last);
    }
  }
}

// DelAll untuk Baris
void delAllB(list *L) {
  if(countElementB(*L) != 0){
    for(int i = countElementB(*L); i >= 1; i--)
      // Proses menghapus elemen list
      delLastB(L);
  }
}

void SortElRowAsc(list *L, IsiContainerRow kontainer) {
  eBaris *tunjuk, *null, *temps, *prev, *current, *prevEl, *tempsV; //inisialisasi
  tunjuk = (eBaris *)malloc(sizeof(eBaris)); null = (eBaris *)malloc(sizeof(eBaris));
  prevEl = (eBaris *)malloc(sizeof(eBaris));
  prev = (eBaris *)malloc(sizeof(eBaris));
  current = (eBaris *)malloc(sizeof(eBaris));
  // tunjuk = (*L).first;
  // prev = (*L).first;
  int mark = 0, loop, res;
  tunjuk = (*L).first_row; //inisialisasi tunjuk dengan L.first
  prev = NULL;
  while (tunjuk != NULL) {
    null = tunjuk->next_row; // set/inisialisasi dengan next dari tunjuk
    while (null != NULL) {
        // Proses mengcompare pointer saat ini dengan pointer next
        if(strcmp(tunjuk->kontainer.NameOfCompany, null->kontainer.NameOfCompany) > 0) {
            //prevEl disini diibaratkan seperti prev sebelum current (tunjuk)
            // ketika next dari prevEl nya itu merupakan pointer dari si nullnya, maka tidak diiterasi
            // namun ketika next dari si prevElny itu bukan merupakan pointer dari si null, maka iterasi (analoginya mereka selalu bersebelahan)
            prevEl = tunjuk; //inisialisasi bahwa prevEl selalu bersama dengan situnjuk
            // perulangan untuk memindahkan prevEl selalu dibelakang dan bersebelahan dengan si null
            while (prevEl->next_row != null) {
                prevEl = prevEl->next_row;
            }
            // ---------

            // jika si prev masih NULL yang berarti tunjuk (currentnya masih belum maju), maka...
            if(prev == NULL) {
                // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                if (prevEl == tunjuk) {
                    (*L).first_row = null;          // pointer null ke L.first_row
                    tunjuk->next_row = null->next_row;  // Kemudian pointer null->next_row ke pointer tunjuk->next_row
                    null->next_row = tunjuk;        // Lalu terakhir pointer tunjuk ke null->next_row
                    // jika prevEl tidak sama dengan value tunjuk, maka...
                }else {
                    (*L).first_row = tunjuk->next_row;  // tunjuk->next_row ke L.first_row
                    tunjuk->next_row = null->next_row;  // kemudian pointer null->next_row ke pointer tunjuk->next_row
                    null->next_row = tunjuk;        // kemudian pointer tunjuk isikan kedalam pointer null->next_row
                    prevEl->next_row = null->next_row;  // lalu pointer null->next_row ke pointer prevEl->next_row
                    null->next_row = (*L).first_row;    // pointer first_row isikan kedalam pointer null->next_row
                    (*L).first_row = null;          // terakhir pointer null isikan/kaitkan kedalam pointer first_row
                }
            }else { // jika si prev tidak NULL, maka...
            // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                if (prevEl == tunjuk) {
                    prev->next_row = null;          // pointer null ke prev->next_row
                    tunjuk->next_row = null->next_row;  // pointer null->next_row ke pointer tunjuk->next_row
                    null->next_row = tunjuk;        // pointer tunjuk ke pointer null->next_row
                }else {
                    prev->next_row = tunjuk->next_row;  // pointer tunjuk->next_row ke pointer prev->next_row
                    tunjuk->next_row = null->next_row;  // pointer null->next_row ke pointer L.first_row
                    null->next_row = tunjuk;        // pointer tunjuk ke pointer null->next_row
                    prevEl->next_row = null->next_row;  // pointer null->next_row ke pointer prevEl->next_row
                    null->next_row = prev->next_row;    // pointer prev->next_row ke pointer null->next_row
                    prev->next_row = null;          // pointer null ke pointer prev->next
                }
            }
            // agar ketika ada data yang ditukar, tunjuk dan null terreset kembali
            tempsV = tunjuk;    // pointer tunjuk arahkan ke bungkusan tempsv
            tunjuk = null;      // kemudian isikan pointer tunjuk dengan value pointer null
            null = tempsV;      // terakhir baru pindahkan kembali isi dari bungkusan tempsv kedalam pointer null
        }
        null = null->next_row; //iterasi
    }
    prev = tunjuk; //inisialisasi
    tunjuk = tunjuk->next_row; //iterasi
  }
}

void SortElRowDesc(list *L, IsiContainerRow kontainer) {
  eBaris *tunjuk, *null, *temps, *prev, *current, *prevEl, *tempsV; //inisialisasi
  tunjuk = (eBaris *)malloc(sizeof(eBaris)); null = (eBaris *)malloc(sizeof(eBaris));
  prevEl = (eBaris *)malloc(sizeof(eBaris));
  prev = (eBaris *)malloc(sizeof(eBaris));
  current = (eBaris *)malloc(sizeof(eBaris));
  // tunjuk = (*L).first;
  // prev = (*L).first;
  int mark = 0, loop, res;
  tunjuk = (*L).first_row; //inisialisasi tunjuk dengan L.first
  prev = NULL;
  while (tunjuk != NULL) {
    null = tunjuk->next_row; // set/inisialisasi dengan next dari tunjuk
    while (null != NULL) {
        // Proses mengcompare pointer saat ini dengan pointer next
        if(strcmp(tunjuk->kontainer.NameOfCompany, null->kontainer.NameOfCompany) < 0) {
            //prevEl disini diibaratkan seperti prev sebelum current (tunjuk)
            // ketika next dari prevEl nya itu merupakan pointer dari si nullnya, maka tidak diiterasi
            // namun ketika next dari si prevElny itu bukan merupakan pointer dari si null, maka iterasi (analoginya mereka selalu bersebelahan)
            prevEl = tunjuk; //inisialisasi bahwa prevEl selalu bersama dengan situnjuk
            // perulangan untuk memindahkan prevEl selalu dibelakang dan bersebelahan dengan si null
            while (prevEl->next_row != null) {
                prevEl = prevEl->next_row;
            }
            // ---------

            // jika si prev masih NULL yang berarti tunjuk (currentnya masih belum maju), maka...
            if(prev == NULL) {
                // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                if (prevEl == tunjuk) {
                    (*L).first_row = null;          // pointer null ke L.first_row
                    tunjuk->next_row = null->next_row;  // Kemudian pointer null->next_row ke pointer tunjuk->next_row
                    null->next_row = tunjuk;        // Lalu terakhir pointer tunjuk ke null->next_row
                    // jika prevEl tidak sama dengan value tunjuk, maka...
                }else {
                    (*L).first_row = tunjuk->next_row;  // tunjuk->next_row ke L.first_row
                    tunjuk->next_row = null->next_row;  // kemudian pointer null->next_row ke pointer tunjuk->next_row
                    null->next_row = tunjuk;        // kemudian pointer tunjuk isikan kedalam pointer null->next_row
                    prevEl->next_row = null->next_row;  // lalu pointer null->next_row ke pointer prevEl->next_row
                    null->next_row = (*L).first_row;    // pointer first_row isikan kedalam pointer null->next_row
                    (*L).first_row = null;          // terakhir pointer null isikan/kaitkan kedalam pointer first_row
                }
            }else { // jika si prev tidak NULL, maka...
            // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                if (prevEl == tunjuk) {
                    prev->next_row = null;          // pointer null ke prev->next_row
                    tunjuk->next_row = null->next_row;  // pointer null->next_row ke pointer tunjuk->next_row
                    null->next_row = tunjuk;        // pointer tunjuk ke pointer null->next_row
                }else {
                    prev->next_row = tunjuk->next_row;  // pointer tunjuk->next_row ke pointer prev->next_row
                    tunjuk->next_row = null->next_row;  // pointer null->next_row ke pointer L.first_row
                    null->next_row = tunjuk;        // pointer tunjuk ke pointer null->next_row
                    prevEl->next_row = null->next_row;  // pointer null->next_row ke pointer prevEl->next_row
                    null->next_row = prev->next_row;    // pointer prev->next_row ke pointer null->next_row
                    prev->next_row = null;          // pointer null ke pointer prev->next
                }
            }
            // agar ketika ada data yang ditukar, tunjuk dan null terreset kembali
            tempsV = tunjuk;    // pointer tunjuk arahkan ke bungkusan tempsv
            tunjuk = null;      // kemudian isikan pointer tunjuk dengan value pointer null
            null = tempsV;      // terakhir baru pindahkan kembali isi dari bungkusan tempsv kedalam pointer null
        }
        null = null->next_row; //iterasi
    }
    prev = tunjuk; //inisialisasi
    tunjuk = tunjuk->next_row; //iterasi
  }
}


// Print Element
void SwapElement(list *L, char From[], char FromNumber[], char To[], char ToNumber[]) {
  int xx = 0;
  if((*L).first_row != NULL) {
    int CounterRow = 1, CounterCol = 1, KetemuRowCurr = 0, KetemuRowTo = 0, KetemuCol = 0, CounterMoveB = 0, Ketemu = 0;
    eBaris *CurrRow, *ToRow, *CurrRowTJ, *ToRowTJ, *Temp1;
    CurrRow = (eBaris *) malloc (sizeof (eBaris));
    ToRow = (eBaris *) malloc (sizeof (eBaris));
    CurrRowTJ = (eBaris *) malloc (sizeof (eBaris));
    ToRowTJ = (eBaris *) malloc (sizeof (eBaris));
    Temp1 = (eBaris *) malloc (sizeof (eBaris));

    CurrRow = (*L).first_row;

    eKolom *CurrCol, *CurrColTJ, *ToColTJ;
    CurrCol = (eKolom *) malloc (sizeof (eKolom));
    CurrColTJ = (eKolom *) malloc (sizeof (eKolom));
    ToColTJ = (eKolom *) malloc (sizeof (eKolom));

    eBaris *TempPrevCurr, *TempPrevPrevCurr, *TempPrevTo, *TempSwap, *TempSwap2, *TempPrev;
    TempPrevCurr = (eBaris *) malloc (sizeof (eBaris));
    TempPrevPrevCurr = (eBaris *) malloc (sizeof (eBaris));
    TempPrevTo = (eBaris *) malloc (sizeof (eBaris));
    TempPrev = (eBaris *) malloc (sizeof (eBaris));
    TempSwap = (eBaris *) malloc (sizeof (eBaris));
    TempSwap2 = (eBaris *) malloc (sizeof (eBaris));
    TempPrevTo = NULL;
    TempPrevCurr = (*L).first_row;
    int markSwap = 0;


    while (CurrRow != NULL){
      if ((strcmp(From, CurrRow->kontainer.NameOfCompany) == 0) || (strcmp(To, CurrRow->kontainer.NameOfCompany) == 0)){
        // if (Ketemu == 1) {
        //   ToRowTJ = CurrRow;
        //   CounterMoveB++;
        //   Ketemu++;
        // }
        if (Ketemu != 0){
          Ketemu++;
        }
        // else if (Ketemu == 2) {
        //   Ketemu++;
        // }
        if (Ketemu == 0) {
          CurrRowTJ = CurrRow;
          CounterMoveB++;
          Ketemu++;
          // printf("hah\n");
        }
        
        // printf("%s-\n", CurrRowTJ->kontainer.NameOfCompany);
        // printf("%s--\n", CurrRow->kontainer.NameOfCompany);
        if (CurrRowTJ != CurrRow) {
          if(CounterMoveB == 1 && markSwap == 0) {
            if (CurrRowTJ == (*L).first_row) { // pTr Current Row sudah next, dan pointer sebelum curr row merupakan L.first
              if (CurrRowTJ->next_row == CurrRow) { //jika pointer sebelum current row merupakan currow pointer prevnya
                printf("HAIII1\n");
                (*L).first_row = CurrRow;
                TempSwap2 = CurrRowTJ;
                CurrRowTJ->next_row = CurrRow->next_row;
                CurrRow->next_row = TempSwap2;

                TempSwap = CurrRow;
                CurrRow = CurrRowTJ;
                CurrRowTJ = TempSwap;
              }else {
                printf("HAIII2\n");
                TempPrev = CurrRowTJ;
                while (TempPrev->next_row != CurrRow) {
                  TempPrev = TempPrev->next_row;
                }
                (*L).first_row = CurrRowTJ->next_row;
                CurrRowTJ->next_row = CurrRow->next_row;
                CurrRow->next_row = CurrRowTJ;
                TempPrev->next_row = CurrRow->next_row;
                CurrRow->next_row = (*L).first_row;
                (*L).first_row = CurrRow;

                // (*L).first_row = CurrRow;
                // TempSwap2 = CurrRowTJ;
                // CurrRow->next_row = CurrRowTJ->next_row;
                // CurrRowTJ->next_row = TempPrev;
                // CurrRow = CurrRowTJ;
                // CurrRowTJ = TempSwap2;
                // TempPrev->next_row = TempSwap2;
                // CurrRowTJ->next_row = CurrRow->next_row;

                // TempPrev->next_row = CurrRow;
                // CurrRow->next_row = TempSwap2;
                // CurrRow->next_row = TempPrev;

                TempSwap = CurrRowTJ;
                CurrRowTJ = CurrRow;
                CurrRow = TempSwap;

              }
            }else {
              if (CurrRowTJ->next_row == CurrRow) { //jika pointer sebelum current row merupakan currow pointer prevnya
                printf("HAIII3\n");
                printf("%s---000\n", (*L).first_row->kontainer.NameOfCompany);
                printf("%s---000\n", TempPrevCurr->kontainer.NameOfCompany);
                printf("%s---000\n", CurrRowTJ->kontainer.NameOfCompany);
                printf("%s---000\n", CurrRow->kontainer.NameOfCompany);
                TempPrevCurr->next_row = CurrRow;
                TempSwap2 = CurrRowTJ;
                CurrRowTJ->next_row = CurrRow->next_row;
                CurrRow->next_row = CurrRowTJ;

                TempPrevCurr = NULL;
                TempSwap = CurrRowTJ;
                CurrRowTJ = CurrRow;
                CurrRow = TempSwap;
              }else {
                printf("HAIII4\n");
                TempPrev = CurrRowTJ;
                while (TempPrev->next_row != CurrRow) {
                  TempPrev = TempPrev->next_row;
                }
                TempPrevCurr->next_row= CurrRowTJ->next_row;
                CurrRowTJ->next_row = CurrRow->next_row;
                CurrRow->next_row = CurrRowTJ;
                TempPrev->next_row = CurrRow->next_row;
                CurrRow->next_row = TempPrevCurr->next_row;
                TempPrevCurr->next_row = CurrRow;

                TempSwap = CurrRowTJ;
                CurrRowTJ = CurrRow;
                CurrRow = TempSwap;

              }

            }
          }
          markSwap++;
        }
      }
      printf("%d--0-\n", Ketemu);
      if (Ketemu == 1) {
        // printf("hallo\n");
        if (TempPrevCurr->next_row != CurrRowTJ){
          printf("%d %s---\n", xx, TempPrevCurr->kontainer.NameOfCompany); 
          TempPrevPrevCurr = TempPrevCurr;       
          TempPrevCurr = TempPrevCurr->next_row;
        }
      }
      // TempPrevCurr = CurrRowTJ;
      CurrRow = CurrRow->next_row;
      CounterRow++;
      xx++;
    }
  }
}

void PrintEl(list L) {
    // Jika list tidak kosong
    // Inisialisasi
  if((L).first_row != NULL) {
    eBaris *bantu = L.first_row;
    int i = 1;

    while (bantu != NULL) {
      // Proses

      printf("Elemen ke        : %d\n", i);
      printf("Perusahaan       : %s\n", bantu->kontainer.NameOfCompany);
      eKolom *eCol = bantu->first_col;
      while(eCol != NULL) {
        printf("- Type Barang : %s\n", eCol->kontainer_col.TypeBarang);
        printf("- Code Barang : %s\n", eCol->kontainer_col.CodeBarang);
        eCol = eCol->next_col;
      }
      printf("------------\n");
      // iterasi
      bantu = bantu->next_row;
      i += 1;

    }
  }else 
    // Proses jika list kosong
    printf("List Kosong.\n");
}

// void printRev(list L){
  // if(L.first_row != NULL) {
    // Jika list tidak kosong
    // Inisialisasi
    // eBaris *bantu = L.first_row;
    // int i = 1;

    // while (bantu != NULL) {
      // Proses

      // printf("Elemen ke : %d\n", i);
      // printf("Nim       : %s\n", bantu->kontainer.nim);
      // printf("Nama      : %s\n", bantu->kontainer.nama);
      // printf("------------\n");
      // iterasi
      

      // int m = 0;
      // eKolom *kolomgimang = bantu->first_col;
      // while(kolomgimang != NULL) {
      //   kolomgimang = kolomgimang->next_col;
      //   m++;
      // }
      // printf("m = %d\n", m);
      // for (int k = m; k > 0; k--) {
      //   kolomgimang = bantu->first_col;
      //   for (int j = 0; j < k - 1; j++)
      //     kolomgimang = kolomgimang->next_col;
        
      //   printf("- Kode Kuliah : %s\n", kolomgimang->kontainer_col.kode);
      //   printf("- Nilai       : %s\n", kolomgimang->kontainer_col.nilai);
        
      // }
      //   bantu = bantu->next_row;
      //   i += 1;
    // }
       
  // }else 
    // Proses jika list kosong
//     printf("List Kosong.\n");

// }
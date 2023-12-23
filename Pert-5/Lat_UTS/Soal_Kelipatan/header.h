// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM5 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
  int ValueOfHeader;
} Header;

typedef struct{
  int ValueLOL;
} Body;

typedef struct eklm *alamatekolom;
typedef struct eklm{
  Body kontainer_col;
  alamatekolom next_col;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
  Header kontainer;
  eKolom *first_col;
  alamatebaris next_row;
}eBaris;

typedef struct{
  eBaris *first_row;
}list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);

// Add untuk bagian baris
void addFirstB(int ValueOfHeader, list *L);
void addAfterB(eBaris* prev, int ValueOfHeader);
void addLastB(int ValueOfHeader, list *L);

// Add untuk bagian kolom
void addFirstK(int ValueLOL, eBaris *L);
void addAfterK(eKolom* prev, int ValueLOL);
void addLastK(int ValueLOL, eBaris *L);

// Del untuk bagian kolom
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);

// Del untuk bagian baris
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);

// Print Elemen
void printElement(list L);
void printRev(list L);
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
  char nim[10];
  char nama[50];
} mahasiswa;

typedef struct{
  char kode[10];
  char nilai[2];
} matKul;

typedef struct eklm *alamatekolom;
typedef struct eklm{
  matKul kontainer_col;
  alamatekolom next_col;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
  mahasiswa kontainer;
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
void addFirstB(char nim[], char nama[], list *L);
void addAfterB(eBaris* prev, char nim[], char nama[]);
void addLastB(char nim[], char nama[], list *L);

// Add untuk bagian kolom
void addFirstK(char kode[], char nilai[], eBaris *L);
void addAfterK(eKolom* prev, char kode[], char nilai[]);
void addLastK(char kode[], char nilai[], eBaris *L);

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
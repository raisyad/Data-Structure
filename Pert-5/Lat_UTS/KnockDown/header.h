#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
  char NameOfCompany[101];
} IsiContainerRow;

typedef struct{
  char TypeBarang[101];
  char CodeBarang[101];
} IsiContainerCol;

typedef struct eklm *alamatekolom;
typedef struct eklm{
  IsiContainerCol kontainer_col;
  alamatekolom next_col;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
  IsiContainerRow kontainer;
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
void addFirstB(IsiContainerRow kontainer, list *L);
void addAfterB(eBaris* prev, IsiContainerRow kontainer);
void addLastB(IsiContainerRow kontainer, list *L);

// Add untuk bagian kolom
void addFirstK(IsiContainerCol kontainer, eBaris *L);
void addAfterK(eKolom* prev, IsiContainerCol kontainer);
void addLastK(IsiContainerCol kontainer, eBaris *L);

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
void SwapElement(list *L, char From[], char FromNumber[], char To[], char ToNumber[]);
void PrintEl(list L);
void printRev(list L);

// Sort Elemen
void SortElRowAsc(list *L, IsiContainerRow kontainer);
void SortElRowDesc(list *L, IsiContainerRow kontainer);
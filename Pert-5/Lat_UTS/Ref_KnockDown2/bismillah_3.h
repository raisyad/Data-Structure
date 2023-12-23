

// ingat solat nomer 1 naik haji nomer 5
// jagan lupa sholatttt!!!!!!!!!!
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//struktur dari list
typedef struct
{
	char nama[100];
}databaris;

typedef struct elmt{
	char menu[100];
    int harga;
}datakolom;

typedef struct eklm *alamatekolom;

typedef struct eklm{
    datakolom kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;

typedef struct ebr
{
    databaris kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct
{
	eBaris *first;
}list;

void createListbaris(list *L);
int countElementbaris(list L);
int countElementkolom(eBaris L);
void addFirstbaris(databaris kb, list *L);
void addFirstkolom(datakolom kk,  eBaris *L);
void addAfterbaris(eBaris* prev, databaris kb);
void addAfterkolom(eKolom* prev_kol, datakolom kk);
void addLastbaris(databaris kb, list *L);
void addLastkolom(datakolom kk,  eBaris *L);
void delFirstkolom(eBaris *L);
void delAfterkolom(eKolom* prev_kol);
void delLastkolom(eBaris *L);
void delAllkolom(eBaris *L);
void delFirstbaris(list *L);
void delAfterbaris(eBaris* prev, list *L);
void delLastbaris(list *L);
void delAllbaris(list *L);
void printElement(list L);
// void coba(int n, list *L);
void sorting(list *L); // -> prosedur untuk menyorting baris
eBaris *getBaris(list L, char label[]); // -> fungsi untuk mencari baris yang dituju
eKolom *getKolom(list L, char label_baris[], char label_kolom[]); // -> fungsi untuk mencari kolom yang dituju
void printkolom(list L, char label[]);
eKolom *getLastKolom(eBaris *L); // -> fungsi untuk mencari kolom terakhir dibaris dituju
// void delAll(list *L);
void sortingkolom(list *L, char label[]); // -> sorting kolom di baris tertentu
void sortingkolomall(list *L); // -> sorting kolom di semua baris
void tukarLast(char labelA[], char labelB[], char namaTukar[], list *L); // -> prosedur untuk memindahkan elemen ke kolom terakhir di baris tujuan
void tukarFirst(char labelA[], char labelB[], char namaTukar[], list *L); // -> prosedur untuk memindahkan elemen ke kolom awal di baris tujuan
void tukarAfter(char labelA[], char labelB[], char namaTukar1[], char namaTukar2[], list *L); // -> prosedur untuk memindahkan elemen ke kolom awal di baris tujuan
void tukarbeneran(char labelA[], char labelB[], char namaTukar1[], char namaTukar2[], list *L);
// void printElement(list L);

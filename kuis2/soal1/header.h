// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis2 stgro22 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include <stdio.h>
#include <string.h>
#define MAX 101
#define MAXCONTAINER 101

typedef struct {
    char NamePemilik[MAXCONTAINER], EkspedisiPaket[MAXCONTAINER] ,DomainPaket[MAXCONTAINER]; 
    int beratPaket;
    char CompareEkspedisi[MAXCONTAINER];
} isiKontainer;

typedef struct {
    int top;
    isiKontainer data[MAX];
} stack;

void createStack(stack *S); // Prosedur untuk membuat stack kosong
int isEmpty(stack S); // Fungsi untuk mengecek apakah stack tersebut kosong atau tidak
int isFull(stack S); // Fungsi untuk mengecek apakah stack tersebut penuh atau tidak
void push(isiKontainer kontainer, stack *S); // Prosedur untuk menambahkan elemen ke dalam stack
void pop(stack *S); // Prosedur untuk mengambil elemen dari stack
void popPush(stack *Sasal, stack *Stujuan); // Prosedur untuk memindahkan elemen dari elemen asal(firstins) ke elemen tujuan(filtered)
void StackFinal(stack S); // prosedur untuk menampilkan isi stack final yang telah terfilter
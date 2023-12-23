#include "header.h"

// prosedur untuk membuat stack kosong
void createStack(stack *S) { (*S).top = -1; } // inisialisasi pointer top dengan -1/NULL

int isEmpty(stack S) // prosedur untuk cek apakah stack kosong
{
    int hasil = 0;
    if (S.top == -1) // jika pointer top menunjuk -1/NULL
        hasil = 1; // tanda stack tsb kosong
    return hasil;
}

int isFull(stack S) // prosedur untuk cek apakah stack penuh
{
    int hasil = 0;
    if (S.top == MAX - 1) // jika pointer top menunjuk pada 9
        hasil = 1; // tanda stack tsb penuh
    return hasil;
}

void push(isiKontainer kontainer, stack *S) { // prosedur untuk menambahkan elemen ke dalam stack
    if (isFull(*S) == 1) // stack penuh jadi tidak bisa ditambahkan lagi
        printf("Stack Penuh.\n");
    else // jika stack belum penuh
    {
        if (isEmpty(*S) == 1) {// jika stack kosong
            (*S).top = 0;
            (*S).data[0] = kontainer;
        }
        else { // jika stack tidak kosong
            (*S).top++;
            (*S).data[(*S).top] = kontainer;
        }
    }
}

void pop(stack *S) {// prosedur untuk mengambil elemen dari stack
    if ((*S).top == 0) // jika stack berisi 1 elemen
        (*S).top = -1;
    else
        if ((*S).top != -1) // jika stack berisi > 1 elemen
            (*S).top = (*S).top - 1;
}

void printStack(stack S) // prosedur untuk menampilkan isi stack
{
    if (S.top != -1) {// jika stack tidak kosong
        printf("--------isi Stack---------\n");
        for (int i = S.top; i >= 0; i--) {// menampilkan dari elemen paling baru masuk
            printf("==================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", S.data[i].label_nim);
            printf("nama : %s\n", S.data[i].label_nama);
            printf("nilai : %f\n", S.data[i].nilai);
        }
        printf("-----------------------\n");
    }
    else
        printf("Stack Kosong.\n");
}
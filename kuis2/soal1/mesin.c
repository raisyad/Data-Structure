// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis2 stgro22 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// Prosedur untuk membuat stack kosong
void createStack(stack *S) { (*S).top = -1; } // inisialisasi pointer top dengan -1 (NULL)

// Fungsi untuk mengecek apakah stack tersebut kosong atau tidak
int isEmpty(stack S) {
    int hasil = 0;
    if (S.top == -1) // jika pointer top menunjuk -1/NULL
        hasil = 1; // tanda stack tsb kosong
    return hasil;
}

// Fungsi untuk mengecek apakah stack tersebut penuh atau tidak
int isFull(stack S) {
    int hasil = 0;
    if (S.top == 50 - 1) // jika pointer top menunjuk pada 49
        hasil = 1; // tanda stack tsb penuh
    return hasil;
}

// Prosedur untuk memindahkan elemen dari elemen asal(firstins) ke elemen tujuan(filtered)
void popPush(stack *S, stack *to) {
    // Jika stack awal/asal tidak menandakan kosong, maka...
    if (isEmpty((*S)) == 0) {
        // Jika elemen yang terdapat pada stack awal/asal hanya ada 1, maka...
        if ((*S).top == 0) { 
            push((*S).data[0], to);      // push/masukkan data ke stack tujuan
            (*S).top = -1;               // ketika sudah mempush, maka top yang dipindah tadi, dijadikan null dengan menandai -1
        }
        // Jika elemen yang terdapat pada stack awal/asal mempunyai lebih dari 1 elemen, maka...
        else {
            push((*S).data[(*S).top], to); // push/masukkan data ke stack tujuan
            (*S).top = (*S).top - 1;       // Decrement iterasi
        }
    }
}

// Prosedur untuk menambahkan elemen ke dalam stack
void push(isiKontainer kontainer, stack *S) {
    if (isFull(*S) == 1) // stack penuh jadi tidak bisa ditambahkan lagi
        printf("Stack Penuh.\n");
     // jika stack belum penuh
    // Jika stack tidak penuh, maka data dapat diinputkan
    if (isFull(*S) == 0){
        if (isEmpty(*S) == 1) { // Jika stack tidak memiliki elemen sama sekali
            (*S).top = 0;
            (*S).data[0] = kontainer;
        }
        else { // Jika stack memiliki elemen/tidak kosong
            (*S).top++;
            (*S).data[(*S).top] = kontainer;
        }
    }
}

// Prosedur untuk mengambil elemen dari stack
void pop(stack *S) { 
    // Jika stack hanya berisi 1 elemen
    if ((*S).top == 0)
        (*S).top = -1;
    // Jika stack berisi lebih dari 1 elemen
    else
        if ((*S).top != -1)
            (*S).top = (*S).top - 1;
}
// prosedur untuk menampilkan isi stack final yang telah terfilter
void StackFinal(stack S) { 
    if (S.top != -1) // jika stack tidak kosong
        for (int i = S.top; i >= 0; i--) // menampilkan dari elemen paling baru masuk
            printf("%s %s %s %d\n", S.data[i].NamePemilik, S.data[i].EkspedisiPaket, S.data[i].DomainPaket, S.data[i].beratPaket);
}
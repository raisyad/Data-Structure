#include "header.h"

// prosedur untuk membuat stack
void createStack(stack *S) { (*S).top = NULL; } // inisialisasi pointer top dengan NULL

int isEmpty(stack S) { // fungsi untuk cek apakah stack kosong
    int hasil = 0;
    if (S.top == NULL) // jika pointer top menunjuk NULL
        hasil = 1; // tanda stack tsb kosong
    return hasil;
}

int countElement(stack S) {// fungsi untuk menghitung jumlah elemen dalam stack
    int hasil = 0;
    if (S.top != NULL){ // jika stack tidak kosong
        elemen *ptr; // deklarasi pointer
        ptr = S.top; // inisialisasi
        //
        while (ptr != NULL) {
         // menghitung hingga ditemukan NULL
            hasil++;
            ptr = ptr->next;
        }
    }
    return hasil;
}

void push(isiKontainer kontainer, stack *S) {// prosedur untuk menambahkan elemen baru ke stack
    elemen *newPtr;                            // deklarasi pointer
    newPtr = (elemen *)malloc(sizeof(elemen)); // inisialisasi
    //
    newPtr->kontainer = kontainer; // copy data
    //
    if ((*S).top == NULL) // jika stack kosong
        newPtr->next = NULL;
    else // jika stack tidak kosong
        newPtr->next = (*S).top;
    
    (*S).top = newPtr;
    newPtr = NULL;
}

void pop(stack *S) {// prosedur untuk mengeluarkan elemen dari stack
    if ((*S).top != NULL) {
                                   // jika stack tidak kosong
        elemen *hapus = (*S).top;  // inisialisasi
        if (countElement(*S) == 1) // jika elemen dalam stack hanya 1
            (*S).top = NULL;
        else // jika elemen dalam stack > 1
            (*S).top = (*S).top->next;
        
        hapus->next = NULL;
        free(hapus);
    }
    else
        printf("Stack Kosong.\n");
}

void printStack(stack S) { // prosedur untuk menampilkan elemen dalam stack
    if (S.top != NULL) {// jika stack tidak kosong
        printf("--------isi Stack---------\n");
        int i = 1;
        elemen *ptr = S.top; // inisialisasi
        while (ptr != NULL)  {// selama elemen yang ditunjuk pointer bukan NULL
            printf("==================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", ptr->kontainer.label_nim);
            printf("nama : %s\n", ptr->kontainer.label_nama);
            printf("nilai : %.2f\n", ptr->kontainer.nilai);
            // iterasi
            ptr = ptr->next;
            i++;
        }
        printf("-----------------------\n");
    }
    else
        printf("Stack Kosong.\n");
}
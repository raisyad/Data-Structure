// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP3 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// prosedur untuk membuat stack
void createStack(stack *S) { (*S).top = NULL; } // inisialisasi pointer top dengan NULL

int isEmpty(stack S) { // fungsi untuk cek apakah stack kosong
    int hasil = 0;
    if (S.top == NULL) // jika pointer top menunjuk NULL
        hasil = 1; // tanda stack tsb kosong
    return hasil;
}

int countElement(stack S) { // fungsi untuk menghitung jumlah elemen dalam stack
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

void push(isiKontainer kontainer, stack *S) { // prosedur untuk menambahkan elemen baru ke stack
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
}

void Classification(stack *s, stack *rock, stack *pops) { // prosedur untuk mengelompokkan data rock atau pop
    if ((*s).top != NULL) {// jika stack tidak kosong
        int i = 1, count = 0;
        elemen *ptr = (*s).top; // inisialisasi
        elemen *tunjuk = NULL;  // inisialisasi
        while (ptr != NULL)  { // selama elemen yang ditunjuk pointer bukan NULL
            tunjuk = NULL;
            count = 0;
            for (int z = 0; z < strlen(ptr->kontainer.TitleMusic); z++) { //Menambahkan ascii sebanyak panjang karakter
                count += ptr->kontainer.TitleMusic[z];
            }

            if (count % 2 == 0) {       //Jika genap, maka masuk kedalam data rock
                push(ptr->kontainer, rock);
            }else if (count % 2 == 1) { //Jika ganjil, maka masuk kedalam data pop
                push(ptr->kontainer, pops);
            }
            ptr = ptr->next;
            pop(s);
        }
    }
    else
        printf("- Stack Kosong\n");
}

void printStackRock(stack s) { // prosedur untuk menampilkan elemen rock dalam stack
    if (s.top != NULL) {// jika stack tidak kosong
        int i = 1;
        elemen *ptr = s.top; // inisialisasi
        while (ptr != NULL)  {// selama elemen yang ditunjuk pointer bukan NULL
            printf("%d. %s\n", i, ptr->kontainer.TitleMusic);
            // iterasi
            ptr = ptr->next;
            i++;
        }
    }
    else
        printf("BUKAN ANAK ROCK!\n");
}

void printStackPop(stack s) { // prosedur untuk menampilkan elemen pop dalam stack
    if (s.top != NULL) {// jika stack tidak kosong
        int i = 1;
        elemen *ptr = s.top; // inisialisasi
        while (ptr != NULL)  {// selama elemen yang ditunjuk pointer bukan NULL
            printf("%d. %s\n", i, ptr->kontainer.TitleMusic);
            // iterasi
            ptr = ptr->next;
            i++;
        }
    }
    else
        printf("BUKAN ANAK POP!\n");
}
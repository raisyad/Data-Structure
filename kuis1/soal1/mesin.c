// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Kuis 1 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// Prosedur membuat elemen
void createList(list *L) {
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 100; i++) {
        (*L).data[i].next = -2;
        (*L).data[i].prev = -2;
    }
}

// Prosedur menghitung elemen
int countElement(list L) {
    int hasil = 0;
    if (L.first != -1) {
        int hitung;
        hitung = L.first;
        while (hitung != -1) {
            hasil = hasil + 1;
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

// Prosedur elemen kosong
int emptyElement(list L) {
    int hasil = -1;

    //Pembatasan elemen sebanyak < 100
    if (countElement(L) < 100) {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 100)) {
            if (L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            }
            else
                i = i + 1;
        }
    }
    return hasil;
}

void addFirst(char kode1[], char kode2[], list *L) {
    //Pembatasan elemen sebanyak < 100
    if (countElement(*L) < 100) {
        // Bikin list baru
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kode1, kode1);
        strcpy((*L).data[baru].kontainer.kode2, kode2);

        // Cari data first yang memiliki NULL
        if ((*L).first == -1) {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }

        // Rubah first dengan baru
        (*L).first = baru;
    }
}

// Prosedur print addAfter
void addAfter(int before, char kode1[], char kode2[], list *L) {
    if (before != -1) {
        if (countElement(*L) < 100) {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.kode1, kode1);
            strcpy((*L).data[baru].kontainer.kode2, kode2);

            if ((*L).data[before].next != -1) {
                (*L).data[baru].prev = before;
                (*L).data[baru].next = (*L).data[before].next;
                (*L).data[before].next = baru;
                (*L).data[(*L).data[baru].next].prev = baru;
            }
            else {
                (*L).data[baru].prev = before;
                (*L).data[before].next = baru;
                (*L).data[baru].next = -1;
                (*L).tail = baru;
            }
        }
    }
}

void addLast(char kode1[], char kode2[], list *L) {
    if ((*L).first == -1) 
        addFirst(kode1,kode2, L);
    else
        addAfter((*L).tail, kode1,kode2, L);
}

// Prosedur PrintElement
void printElement(list L) {
    if (L.first != -1) {
        int pTr = L.first;
        while (pTr != -1) {
            printf("%s ", L.data[pTr].kontainer.kode1);
            printf("%s\n", L.data[pTr].kontainer.kode2);

            // Iterasi
            pTr = L.data[pTr].next;
        }
    }
}

void SwapEl(list *L1, list *L2, int p) {
    // Pemb
    int depan1 = (*L1).first; int depan2 = (*L2).first;
    int belakang1 = (*L1).tail; int belakang2 = (*L2).tail;
    GenS1 temp;
    GenS1 temp2;

    // Tukar Yang bagian depan
    for (int i = 0; i < p; i++) {
        temp = (*L1).data[depan1].kontainer;
        (*L1).data[depan1].kontainer = (*L2).data[depan2].kontainer;
        (*L2).data[depan2].kontainer = temp;
        
        // Iterasi
        depan1 = (*L1).data[depan1].next;
        depan2 = (*L2).data[depan2].next;
    }

    // Tukar yang bagian belakang
    for (int i = 0; i < p; i++) {
        temp2 = (*L1).data[belakang1].kontainer;
        (*L1).data[belakang1].kontainer = (*L2).data[belakang2].kontainer;
        (*L2).data[belakang2].kontainer = temp2;

        // Iterasi
        belakang1 = (*L1).data[belakang1].prev;
        belakang2 = (*L2).data[belakang2].prev;
    }
    // Print Hasil gabungan setelah ditukar 
    printElement((*L1));
    printElement((*L2));
}
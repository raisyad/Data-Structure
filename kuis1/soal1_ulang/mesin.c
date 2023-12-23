// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis 1 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createList(list *L) {
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 101; i++) {
        (*L).data[i].next = -2;
        (*L).data[i].prev = -2;
    }
}

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

int emptyElement(list L) {
    int hasil = -1;

    if (countElement(L) < 101) {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 101)) {
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

void addFirst(GenS1 kontainer, list *L) {

    if (countElement(*L) < 101) {
        // Bikin list baru
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kode1, kontainer.kode1);
        strcpy((*L).data[baru].kontainer.kode2, kontainer.kode2);

        // Cari data first yang memiliki NULL
        if ((*L).first == -1) {
            /*jika list kosong, pasangkan list baru dengan NULL*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else {
            /*jika list tidak kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }

        // Rubah first dengan baru
        (*L).first = baru;
    }
}

void addAfter(int before, GenS1 kontainer, list *L) {
    if (before != -1) {
        if (countElement(*L) < 101) {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.kode1, kontainer.kode1);
            strcpy((*L).data[baru].kontainer.kode2, kontainer.kode2);

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

void addLast(GenS1 kontainer, list *L) {
    if ((*L).first == -1)
        /*proses jika list masih kosong*/
        addFirst(kontainer, L);
    else
        /*proses jika list telah berisi elemen*/
        addAfter((*L).tail, kontainer, L);
}

void printElement(list L) {
    if (L.first != -1) {
        /*inisialisasi*/
        int bantu = L.first;
        while (bantu != -1){

            printf("%s %s\n", L.data[bantu].kontainer.kode1, L.data[bantu].kontainer.kode2);
            /*iterasi*/
            bantu = L.data[bantu].next;
        }
    }
}

void swapEl(list *L1, list *L2, int p) {
    elemen temp;
    int depan1, depan2, belakang1, belakang2;
    depan1 = (*L1).first;
    belakang1 = (*L2).tail;
    depan2 = (*L1).first;
    belakang2 = (*L2).tail;


    // Bagian Depan
    for (int i = 0; i < p; i++) {
        temp.kontainer = (*L1).data[depan1].kontainer;
        (*L1).data[depan1].kontainer = (*L2).data[depan2].kontainer;
        (*L2).data[depan2].kontainer = temp.kontainer;

        depan1 = (*L1).data[depan1].next;
        depan2 = (*L2).data[depan2].next;
    }

    // Bagian Belakang
    for (int i = 0; i < p; i++) {
        temp.kontainer = (*L1).data[belakang1].kontainer;
        (*L1).data[belakang1].kontainer = (*L2).data[belakang2].kontainer;
        (*L2).data[belakang2].kontainer = temp.kontainer;

        belakang1 = (*L1).data[belakang1].prev;
        belakang2 = (*L2).data[belakang2].prev;
    }

    printElement((*L1));
    printElement((*L2));
}
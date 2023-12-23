// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

#include"header.h"

void createList(list *L){
    (*L).first = -1;
    int i;

    for (i = 0; i < MAKS i++) (*L).data[i].next = -2;
}

// fungsi untuk menghitung banyak element yang memiliki isi
int countElement(list L){
    int hasil = 0;
    // pengecekan jika list nya bukan list kosong
    if (L.first != -1) {
        int hitung;
        // variabel hitung berisi nilai pada variabel first di element
        hitung = L.first;
        // perulangan selama nilai pada variabel hitung bukan -1
        // karena jika -1 maka artinya selanjutnya atau next adalah NULL yang artinya element yang berisi cukup sampai di situ
        while (hitung != -1){
            // hasil akan bertambah satu dan nilai variabel hitung akan berisi next dari element saat ini
            hasil = hasil + 1;
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

// fungsi untuk menghasilkan index dari element yang masih kosong
int emptyElement(list L) {
    int hasil = -1;
    if (countElement(L) < 5) {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 5)) {
            if (L.data[i].next == -2){
                hasil = i;
                ketemu = 1;
            }
            else i = i + 1;
            
        }
    }
    return hasil;
}

// prosedur untuk addfirst
void addFirst(char nama[], char level[], char gameFrom[], list *L) {
    if (countElement(*L) < 5) {
        // mencari index yang elemennya kosong
        int baru = emptyElement(*L);
        // mengisi elemen baruu pada index yang bsebelumnya dicari
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.gameFrom, gameFrom);

        // addfirst jika elementnya kosong
        if ((*L).first == -1) (*L).data[baru].next = -1;
        // addfirst jika ada elementnya (tidak kosong)
        else (*L).data[baru].next = (*L).first;
        (*L).first = baru;
    }
    // jika semua element sudah terisi
    else printf("Element sudah penuh\n");
    
}

// prosedur untuk addafter
void addAfter(int prev, char nama[], char level[], char gameFrom[], list *L) {
    if (countElement(*L) < 5) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.gameFrom, gameFrom);

        // addafter setelah data terakhir
        if ((*L).data[prev].next == -1) (*L).data[baru].next = -1;
        // addafter setelah data yang ditentukan atau di tengah (bukan di akhir)
        else (*L).data[baru].next = (*L).data[prev].next;

        (*L).data[prev].next = baru;
    }
    // jika semua element sudah terisi
    else printf("Element sudah penuh\n");
}

// prosedur untuk addlast
void addLast(char nama[], char level[], char gameFrom[], list *L) {
    // jika elementnya kosong makan sama saja seperti menjalankan addfirst
    if ((*L).first == -1) addFirst(nama, level, gameFrom, L);
    
    else {
        if (countElement(*L) < 5) {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1) prev = (*L).data[prev].next;
            addAfter(prev, nama, level, gameFrom, L);
        }
        else printf("Element sudah penuh\n");
    }
}

// prosedur untuk delfirst
void delFirst(list *L) {
    if ((*L).first != -1) {
        int hapus = (*L).first;
        if (countElement(*L) == 1) (*L).first = -1;
        else (*L).first = (*L).data[hapus].next;

        (*L).data[hapus].next = -2;
    }
    else printf("List Kosong.\n");
}

// prosedur untuk delafter
void delAfter(int prev, list *L) {
    int hapus = (*L).data[prev].next;
    if (hapus != -1) {
        if ((*L).data[hapus].next == -1) (*L).data[prev].next = -1;
        else (*L).data[prev].next = (*L).data[hapus].next;

        (*L).data[hapus].next = -2;
    }
}

// prosedur untuk dellast
void delLast(list *L){
    if ((*L).first != -1) {
        if (countElement(*L) == 1) delFirst(L);
        else {
            int hapus = (*L).first;
            int prev;
            while ((*L).data[hapus].next != -1){
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            delAfter(prev, L);
        }
    } else printf("List Kosong.\n");
}

void delAll(list *L){
    int i;
    for (i = countElement(*L); i >= 1; i--) delLast(L);
}

void printElement(list L){
    if (L.first != -1){
        int tunjuk = L.first;
        int i = 1;
        while (tunjuk != -1){
            printf("- %s %s %s\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.level, L.data[tunjuk].kontainer.gameFrom);

            tunjuk = L.data[tunjuk].next;
            i = i + 1;
        }
    }
    else printf("List Kosong.\n");
}
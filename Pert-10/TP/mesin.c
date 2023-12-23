// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP5 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

#include "header.h"

// Prosedur Buat Graph Kosong
void createEmpty(graph *G) { (*G).first = NULL; }

// Prosedur Menambahkan Simpul
void addSimpul(char kota[], graph *G) {
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));

    strcpy(baru->kontainer, kota);
    baru->next = NULL;
    baru->arc = NULL;
    if ((*G).first == NULL) {
        /*jika graf kosong*/
        (*G).first = baru;
    }
    else
    {
        /*menambahkan simpul baru pada akhir
       graph*/
        simpul *last = (*G).first;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = baru;
    }
}

// Prosedur Menambahkan Jalur
void addJalur(simpul *awal, simpul *tujuan, int bobot) {
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    
    baru->kontainerJalur = bobot;
    baru->nextJalur = NULL;
    baru->tujuan = tujuan;
    if (awal->arc == NULL) {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else {
        /*menambahkan jalur baru pada akhir list
       jalur*/
        jalur *last = awal->arc;

        while (last->nextJalur != NULL) {
            last = last->nextJalur;
        }

        last->nextJalur = baru;
    }
}

// Prosedur mencari simpul
simpul* findSimpul(char kota[], graph G, int *ketemu) {
    *ketemu = 0;
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    while ((bantu != NULL) && (*ketemu == 0)) {
        if (strcmp(bantu->kontainer, kota) == 0) {
            hasil = bantu;
            *ketemu = 1;
        }
        else {
            bantu = bantu->next;
        }
    }

    return hasil;
}

// Prosedur DelJalur
void delJalur(char ctujuan[], simpul *awal) {
    jalur *hapus = awal->arc;
    if (hapus != NULL) {
        jalur *prev = NULL;
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0)) {
            if (strcmp(hapus->tujuan->kontainer,ctujuan) == 0) {
                ketemu = 1;
            }
            else {
                prev = hapus;
                hapus = hapus->nextJalur;
            }
        }
        if (ketemu == 1) {
            if (prev == NULL) {
                awal->arc = hapus->nextJalur;
                hapus->nextJalur = NULL;
                hapus->tujuan = NULL; //!
            }
            else {
                if (hapus->nextJalur == NULL) {
                    prev->nextJalur = NULL;
                    prev->tujuan = NULL; //!
                }
                else {
                    prev->nextJalur = hapus->nextJalur;
                    hapus->nextJalur = NULL;
                    hapus->tujuan = NULL; //!
                }
            }
            free(hapus);
        }
    }
}

void delAllJalur(simpul *awal) {
    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->nextJalur;
        awal->arc = bantu;
        hapus->nextJalur = NULL;
        free(hapus);
    }
}

void delSimpul(char c[], graph *G){
    simpul *hapus = (*G).first;
    if(hapus != NULL){
        simpul *prev = NULL;
        /*mencari simpul yang akan dihapus*/
        int ketemu = 0;
        while((hapus != NULL) && (ketemu == 0)){
            if(strcmp(hapus->kontainer, c) == 0) {
                ketemu = 1;
            }
            else{
                prev = hapus;
                hapus = hapus->next;
            }
        }

        if(ketemu == 1){
            /* jika simpul yang akan dihapus ada */
            /* hapus semua jalur dari simpul lain yang mengarah pada simpul yang dihapus */

            simpul *bantu;
            bantu = (*G).first;
            /* memeriksa semua simpul dalam graf */
            while(bantu != NULL){
                /* jika simpul yang ditelusuri tidak sama
                dengan yang dihapus */
                if(bantu != hapus){
                    /* hapus semua jalur yang mengarah pada
                    simpul yang dihapus */
                    delJalur(hapus->kontainer, bantu);
                }
                bantu = bantu->next;
            }

            /* hapus semua jalur */
            delAllJalur(hapus);

            if(prev == NULL){
                /*hapus simpul pertama*/
                (*G).first = hapus->next;
                hapus->next = NULL;
            }
            else{
                if(hapus->next == NULL){
                    /*hapus simpul terakhir*/
                    prev->next = NULL;
                }
                else{
                    /*hapus simpul di tengah*/
                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }
    }
}

void printGraph(graph G) {
    simpul *bantu = G.first;
    if(bantu != NULL) {
        while(bantu != NULL) {
            printf("Lokasi %s\n", bantu->kontainer);
            jalur *bantu_jalur = bantu->arc;

            while(bantu_jalur != NULL) {
                printf("- Jalur %s ke %s - Berbobot %d\n", bantu->kontainer, bantu_jalur->tujuan->kontainer, bantu_jalur->kontainerJalur);
                bantu_jalur = bantu_jalur->nextJalur;
            }
            bantu = bantu->next;
        }
    }
}

// Prosedur Explore Titik Awal Ketujuan
void TrackingMap(simpul *root, char pointA[], char pointB[], char temp[], int sumJalur, int i) {
    if(root != NULL) {
        if(strcmp(root->kontainer, pointB) == 0) { // Cek apakah root sekarang merupakan Tujuannya
            temp[i] = root->kontainer[0]; // Tampung char
            i = i + 1; // Increment
            for (int x = 0; x < i; x++) { // Print Jalurnya beserta bobotnya
                printf("%c ", temp[x]);
                if (x == i - 1)
                    printf("%d\n", sumJalur);
            }
            i = i - 1; // Decrement
            
        }
        else { // Jika root sekarang bukan tujuannya, maka lakukan perulangan dibawah ini 
        // disertai penambahan bobot, rekursif, pengurangan indeks dan bobot setelah rekursifnya selesai.
            jalur *bantu_jalur = root->arc;
            while (bantu_jalur != NULL) {
                if(strcmp(bantu_jalur->tujuan->kontainer, pointA) != 0) {
                    if (strcmp(root->kontainer, pointA) == 0) { // Jika root sekarang adalah posisi awal, reset indeks dan bobot
                        i = 0;
                        sumJalur = 0;
                    }
                    temp[i] = root->kontainer[0]; // Tampung Jalur
                    i = i + 1; // Increment
                    sumJalur = sumJalur + bantu_jalur->kontainerJalur;
                    TrackingMap(bantu_jalur->tujuan, pointA, pointB, temp, sumJalur, i); // Rekursif (Explore root)
                }
                i = i - 1; // Decrement
                sumJalur = sumJalur - bantu_jalur->kontainerJalur; // Decrement
                bantu_jalur = bantu_jalur->nextJalur; // Iterasi
            }  
        }
    }
}
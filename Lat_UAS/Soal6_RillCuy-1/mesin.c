// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createEmpty(graph *G) { (*G).first = NULL; }

void addSimpul(char kota, graph *G) {
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));

    // strcpy(baru->kontainer, kota);
    baru->kontainer = kota;
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

void addJalur(simpul *awal, simpul *tujuan) {
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));

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

simpul* findSimpul(char kota, graph G, int *ketemu) {
    *ketemu = 0;
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    while ((bantu != NULL) && (*ketemu == 0)) {
        if (bantu->kontainer == kota) {
            hasil = bantu;
            *ketemu = 1;
        }
        else {
            bantu = bantu->next;
        }
    }

    return hasil;
}

void delJalur(char ctujuan, simpul *awal) {
    jalur *hapus = awal->arc;
    if (hapus != NULL) {
        jalur *prev = NULL;
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0)) {
            if (hapus->tujuan->kontainer == ctujuan) {
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

void delSimpul(char c, graph *G){
    simpul *hapus = (*G).first;
    if(hapus != NULL){
        simpul *prev = NULL;
        /*mencari simpul yang akan dihapus*/
        int ketemu = 0;
        while((hapus != NULL) && (ketemu == 0)){
            if(hapus->kontainer == c) {
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

void TrackingMap(simpul *root, int *ketemu, char path[], int *index) {
    if (root != NULL && *ketemu != 1) {// selama node bukan null
        path[*index] = root->kontainer;
        *index = *index + 1;
        root->visited = 1; // mengubah boolean visited menjadi 1

        jalur *tunjuk = root->arc; // tunjuk menjadi node jalur
        if (tunjuk != NULL) {
            while (tunjuk != NULL) {
                if (tunjuk->tujuan->visited != 1) {
                    TrackingMap(tunjuk->tujuan, ketemu, path, index); // rekursif
                }
                else{
                    path[*index] = tunjuk->tujuan->kontainer;
                    *index = *index + 1;
                    *ketemu = 1;
                }

                tunjuk = tunjuk->nextJalur; // iterasi
            }
        }else {
            *index = *index - 1;
        }
        root->visited = 0; // mengubah boolean visited dari node menjadi false
    }
}
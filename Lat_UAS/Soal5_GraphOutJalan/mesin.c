// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addSimpul(char kota[], graph *G) {
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    //
    strcpy(baru->kontainer, kota);
    // baru->kontainer = kota;
    //
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
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan, int bobot) {
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    
    baru->kontainerJalur = bobot;
    baru->nextJalur = NULL;
    baru->tujuan = tujuan;
    if (awal->arc == NULL)
    {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else
    {
        /*menambahkan jalur baru pada akhir list
       jalur*/
        jalur *last = awal->arc;

        while (last->nextJalur != NULL)
        {
            last = last->nextJalur;
        }

        last->nextJalur = baru;
    }
}

simpul* findSimpul(char kota[], graph G, int *finded) {
    *finded = 0;
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    while ((bantu != NULL) && (*finded == 0))
    {
        if (strcmp(bantu->kontainer, kota) == 0) {
            hasil = bantu;
            *finded = 1;
        }
        else {
            bantu = bantu->next;
        }
    }

    return hasil;
}

void delJalur(char ctujuan[], simpul *awal)
{
    jalur *hapus = awal->arc;
    if (hapus != NULL)
    {
        jalur *prev = NULL;
        int ketemu = 0;
        while ((hapus != NULL) && (ketemu == 0))
        {
            if (strcmp(hapus->tujuan->kontainer,ctujuan) == 0)
            {
                ketemu = 1;
            }
            else
            {
                prev = hapus;
                hapus = hapus->nextJalur;
            }
        }
        if (ketemu == 1)
        {
            if (prev == NULL)
            {
                awal->arc = hapus->nextJalur;
                hapus->nextJalur = NULL;
                hapus->tujuan = NULL; //!
            }
            else
            {
                if (hapus->nextJalur == NULL)
                {
                    prev->nextJalur = NULL;
                    prev->tujuan = NULL; //!
                }
                else
                {
                    prev->nextJalur = hapus->nextJalur;
                    hapus->nextJalur = NULL;
                    hapus->tujuan = NULL; //!
                }
            }
            free(hapus);
        }
    }
}

void delAllJalur(simpul *awal)
{
    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;
    while (bantu != NULL)
    {
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
            if(strcmp(hapus->kontainer, c) == 0){
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
    if(bantu != NULL)
    {
        while(bantu != NULL)
        {

            printf("Node %s - ", bantu->kontainer);
            jalur *bantu_jalur = bantu->arc;
            printf ("%s\n", bantu->next->kontainer);

            while(bantu_jalur != NULL) {
                printf("- Jalur %s ke %s\n", bantu->kontainer, bantu_jalur->tujuan->kontainer);
                bantu_jalur = bantu_jalur->nextJalur;
            }
            bantu = bantu->next;
        }
    }
}

void carijalur(simpul *root, char awal[200], int *dapet, char cari[200], int *bobot) {
    // *i = 0;
    if(root != NULL) {
        if(strcmp(root->kontainer, cari) == 0) {
            printf("->%s\n", root->kontainer);
        }
        else {
            jalur *bantu_jalur = root->arc;
            while (bantu_jalur != NULL) {
                if(strcmp(bantu_jalur->tujuan->kontainer, awal) != 0) {
                    printf("->%s", root->kontainer);
                    *dapet = *dapet + bantu_jalur->kontainerJalur;
                    carijalur(bantu_jalur->tujuan, awal, dapet, cari, bobot);
                }
                *dapet = *dapet - bantu_jalur->kontainerJalur;
                bantu_jalur = bantu_jalur->nextJalur;
            }  
        }
    }
}
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP2 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    list llist; //deklar bungkusan list
    createList(&llist); //Pembuatan list
    dataKontainer dataInput; //deklar bungkusan inputan
    int mark = 0; //mark ketika inputan menunjukkan stop
    while (mark != 1) { //ketika nilai bool belum berubah menjadi true
        scanf("%s", dataInput.Desc); //input deskripsi
        if (strcmp(dataInput.Desc, "--stop--") == 0) { //compare
            mark = 1;
        }
        if (mark == 0) { //ketika bool false
            scanf("%d", &dataInput.Date);
            addFirst(dataInput, &llist); //lakukan addfirst
        }
    }
    // Outputan kode
    printf("==== Inventory Dapur ====\n");
    sortAscDate(&llist);
    printRev(&llist);
    printKD(&llist);
    printEl(&llist);
    printf("=========================\n");

    return 0;

}
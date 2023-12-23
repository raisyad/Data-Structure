// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LTS22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

#include"header.h"

int main(void) {
    list L;
    game input;
    char nama[100], level[100], gameFrom[100];
    createList(&L);
    scanf("%s %s %s", &nama, &level, &gameFrom);
    addFirst(nama, level, gameFrom, &L);
    scanf("%s %s %s", &nama, &level, &gameFrom);
    addFirst(nama, level, gameFrom, &L);
    scanf("%s %s %s", &nama, &level, &gameFrom);
    addAfter(L.first, nama, level, gameFrom, &L);
    printElement(L);
    printf("--------------------\n");

    delLast(&L);
    scanf("%s %s %s", &nama, &level, &gameFrom);
    addAfter(L.data[L.first].next, nama, level, gameFrom, &L);
    scanf("%s %s %s", &nama, &level, &gameFrom);
    addLast(nama, level, gameFrom, &L);
    printElement(L);
    printf("--------------------\n");

    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);
    printElement(L);
    printf("--------------------\n");

    delLast(&L);
    printElement(L);
    printf("--------------------\n");
}
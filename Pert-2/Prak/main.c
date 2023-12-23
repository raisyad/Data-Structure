// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LTD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    list L;
    createList(&L);
    char name, JK, bookFrom;
    tokoh tokohData;
    scanf ("%s %s %s", &tokohData.name, &tokohData.JK, &tokohData.bookFrom);
    addFirst(tokohData.name, tokohData.JK, tokohData.bookFrom, &L);
    scanf ("%s %s %s", &tokohData.name, &tokohData.JK, &tokohData.bookFrom);
    addLast(tokohData.name, tokohData.JK, tokohData.bookFrom, &L);
    scanf ("%s %s %s", &tokohData.name, &tokohData.JK, &tokohData.bookFrom);
    addAfter(L.first->next, tokohData.name, tokohData.JK, tokohData.bookFrom, &L);
    printf("--------------------\n");
    printElement(L);
    delAfter(L.first, &L);
    delFirst(&L);
    delLast(&L);
    printf("--------------------\n");
    printElement(L);
    scanf ("%s %s %s", &tokohData.name, &tokohData.JK, &tokohData.bookFrom);
    addFirst(tokohData.name, tokohData.JK, tokohData.bookFrom, &L);
    scanf ("%s %s %s", &tokohData.name, &tokohData.JK, &tokohData.bookFrom);
    addFirst(tokohData.name, tokohData.JK, tokohData.bookFrom, &L);
    delLast(&L);
    printf("--------------------\n");
    printElement(L);
    delAll(&L);
    printf("--------------------\n");
    printElement(L);
    scanf ("%s %s %s", &tokohData.name, &tokohData.JK, &tokohData.bookFrom);
    addFirst(tokohData.name, tokohData.JK, tokohData.bookFrom, &L);
    printf("--------------------\n");
    printElement(L);
    printf("--------------------\n");



    // addFirst("1", "Orang_1", "A", &L);
    // addAfter(L.first, "2", "Orang_2", "A", &L);
    // addLast("3", "Orang_3", "A", &L);

    // printElement(L);

    // printf("=====================\n");

    // delLast(&L);
    // delAfter(L.first, &L);
    // delFirst(&L);
    // printElement(L);

    // printf("=====================\n");

}
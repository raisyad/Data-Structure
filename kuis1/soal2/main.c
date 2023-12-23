// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Kuis 1 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    list L;
    createList(&L);
    char name, JK, bookFrom;
    tokoh tokohData;
    
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", &tokohData.bookFrom, &tokohData.JK, &tokohData.name);
        addLast(tokohData.bookFrom, tokohData.JK, tokohData.name,&L);
    }



    printElement(L);
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
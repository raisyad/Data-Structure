// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    graph G;
    createEmpty(&G);
    isiKontainer data;
    char del;
    scanf (" %c", &del);
    //
    data.node = '1';
    addSimpul(data, &G);
    data.node = '2';
    addSimpul(data, &G);
    data.node = '3';
    addSimpul(data, &G);
    data.node = '4';
    addSimpul(data, &G);
    data.node = '5';
    addSimpul(data, &G);
    data.node = '6';
    addSimpul(data, &G);
    data.node = '7';
    addSimpul(data, &G);
    data.node = '8';
    addSimpul(data, &G);


    
    //
    data.node = '3';
    simpul *begin = findSimpul(data, G);
    data.node = '8';
    simpul *end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    //
    data.node = '3';
    begin = findSimpul(data, G);
    data.node = '1';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    data.node = '3';
    begin = findSimpul(data, G);
    data.node = '7';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    data.node = '4';
    begin = findSimpul(data, G);
    data.node = '2';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    data.node = '5';
    begin = findSimpul(data, G);
    data.node = '6';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    data.node = '6';
    begin = findSimpul(data, G);
    data.node = '3';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    data.node = '7';
    begin = findSimpul(data, G);
    data.node = '4';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    data.node = '8';
    begin = findSimpul(data, G);
    data.node = '1';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    data.node = '8';
    begin = findSimpul(data, G);
    data.node = '6';
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }

    printGraph(G);
    printf("==============\n");
    data.node = del;
    delSimpul(data, &G);
    printGraph(G);
}
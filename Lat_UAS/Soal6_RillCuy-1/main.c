// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    graph G;
    createEmpty(&G);
    char pointA[MAX], pointB[MAX], SimAwal, SimTuj, temp[MAX];
    int n, bobot, ketemu = 0;
    scanf ("%d", &n);

    do {
        scanf(" %c", &SimAwal);
        // jika simpul belum ada
        if (SimAwal != '0') {
            scanf(" %c", &SimTuj);
            findSimpul(SimAwal, G, &ketemu);
            if (ketemu == 0) {
                addSimpul(SimAwal, &G);
            }
            findSimpul(SimTuj, G, &ketemu);
            if (ketemu == 0) {
                addSimpul(SimTuj, &G);
            }

            simpul *LocAwal = findSimpul(SimAwal, G, &ketemu);
            simpul *LocTujuan = findSimpul(SimTuj, G, &ketemu);
            if ((LocAwal != NULL) && (LocTujuan != NULL)) {
                addJalur(LocAwal, LocTujuan);
            }
        }

    } while (SimAwal != '0');
    simpul *init = G.first;
    while (init != NULL) {
        init->visited = 0;
        init = init->next;
    }

    int mark = 0, index = 0;
    char path[MAX];
    TrackingMap(G.first, &mark, path, &index);
    if (mark == 1){
        printf (">>>Ada Bang\n");
        for (int i = 0; i < index; i++) {
            printf("%c", path[i]);
            if (i != index - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }else {
        printf (">>>Ga Ada Bang");
    }
}
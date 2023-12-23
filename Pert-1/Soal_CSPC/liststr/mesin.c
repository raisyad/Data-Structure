#include"header.h"

void createList(list *L, int n) {
    (*L).first = -1;
    int i;
    
    for (i = 0; i < n; i++) (*L).data[i].next = -2;
}

int countElement(list L) {
    int hasil = 0;
    if (L.first != -1) {
        int hitung;

        hitung = L.first;

        while(hitung != -1) {
            hasil += 1;

            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

int emptyElement(list L, int n) {
    int hasil = -1;

    if (countElement(L) < n) {
        int ketemu = 0;
        int i = 0;

        while ((ketemu == 0) && (i < n)) {
            if (L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            }else {
                i += 1;
            }
        }
    }
    return hasil;
}

void addFirst(char* name, list *L, int n) {
    if (countElement(*L) < n) {
        int baru = emptyElement(*L,n);
        strcpy((*L).data[baru].container.name, name);
        if ((*L).first == -1) (*L).data[baru].next = -1;
        else (*L).data[baru].next = (*L).first;

        (*L).first = baru;
    }else printf ("sudah tidak dapat ditambah\n");
}

void printElement(list L) {
    if (L.first != -1) {
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1) {
            printf ("%s\n", L.data[tunjuk].container.name);

            tunjuk = L.data[tunjuk].next;
            i += 1;
        }
    }else printf ("list kosong\n");
}
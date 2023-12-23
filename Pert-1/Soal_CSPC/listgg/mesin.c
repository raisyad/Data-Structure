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

void addFirst(int nilai, list *L, int n) {
    if (countElement(*L) < n) {
        int baru = emptyElement(*L,n);
        (*L).data[baru].container.nilai = nilai;
        if ((*L).first == -1) (*L).data[baru].next = -1;
        else (*L).data[baru].next = (*L).first;

        (*L).first = baru;
    }
}

void printElement(list L, int n) {
    if (L.first != -1) {
        int tunjuk = L.first, null;
        // iterator
        int p = 0, j = 0;
        int minuteFHour = 0, secFHour = 0, secTot = 0;
        int secFMinute = 0, tempGenap[n], tempGanjil[n];
        while (tunjuk != -1) {
            if (L.data[tunjuk].container.nilai % 2 == 0) {
                tempGenap[p] = L.data[tunjuk].container.nilai;
                p++;
            }
            if (L.data[tunjuk].container.nilai % 2 == 1) {
                tempGanjil[j] = L.data[tunjuk].container.nilai;
                j++;
            }

            tunjuk = L.data[tunjuk].next;
        }

        printf("1\n");
        for (int i = j-1; i >= 0; i--) {
            printf("-%d\n", tempGanjil[i]);
        }

        printf("2\n");
        for (int i = p-1; i >= 0; i--) {
            printf("-%d\n", tempGenap[i]);
        }
    }
}
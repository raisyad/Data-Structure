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

void addFirst(int jam, int menit, int detik, list *L, int n) {
    if (countElement(*L) < n) {
        int baru = emptyElement(*L,n);
        (*L).data[baru].container.jam = jam;
        (*L).data[baru].container.menit = menit;
        (*L).data[baru].container.detik = detik;
        if ((*L).first == -1) (*L).data[baru].next = -1;
        else (*L).data[baru].next = (*L).first;

        (*L).first = baru;
    }
}

void printElement(list L) {
    if (L.first != -1) {
        int tunjuk = L.first, null;
        int minuteFHour = 0, secFHour = 0, secTot = 0;
        int secFMinute = 0;
        while (tunjuk != -1) {
            minuteFHour = 0, secFHour = 0, secFMinute = 0, secTot = 0;

            minuteFHour = L.data[tunjuk].container.jam * 60;
            secFHour = minuteFHour * 60;
            secTot += secFHour;

            secFMinute = L.data[tunjuk].container.menit * 60;
            secTot += secFMinute;
            secTot += L.data[tunjuk].container.detik;
            L.data[tunjuk].container.markSec = secTot;
            // printf ("%d : %d\n", L.data[tunjuk].container.markSec, i);
            

            tunjuk = L.data[tunjuk].next;
        }

        tunjuk = L.first;
        int tempValue, tempMark;
        while(tunjuk != -1) {
            null = L.data[tunjuk].next;
            while(null != -1) {
                if (L.data[tunjuk].container.markSec > L.data[null].container.markSec) {
                    // Jam
                    tempValue = L.data[null].container.jam;
                    L.data[null].container.jam = L.data[tunjuk].container.jam;
                    L.data[tunjuk].container.jam = tempValue;

                    // Menit
                    tempValue = L.data[null].container.menit;
                    L.data[null].container.menit = L.data[tunjuk].container.menit;
                    L.data[tunjuk].container.menit = tempValue;

                    // Detik
                    tempValue = L.data[null].container.detik;
                    L.data[null].container.detik = L.data[tunjuk].container.detik;
                    L.data[tunjuk].container.detik = tempValue;

                    // Mark
                    tempMark = L.data[null].container.markSec;
                    L.data[null].container.markSec = L.data[tunjuk].container.markSec;
                    L.data[tunjuk].container.markSec = tempMark;
                }
                null = L.data[null].next;
            }
            tunjuk = L.data[tunjuk].next;
        }

        tunjuk = L.first;
        while (tunjuk != -1) {
            // Jam
            if (L.data[tunjuk].container.jam < 10) {
                printf ("0%d:", L.data[tunjuk].container.jam);
            }else printf ("%d:", L.data[tunjuk].container.jam);
            
            // Menit
            if (L.data[tunjuk].container.menit< 10) {
                printf ("0%d:", L.data[tunjuk].container.menit);
            }else printf ("%d:", L.data[tunjuk].container.menit);

            // Detik
            if (L.data[tunjuk].container.detik < 10) {
                printf ("0%d\n", L.data[tunjuk].container.detik);
            }else printf ("%d\n", L.data[tunjuk].container.detik);

            tunjuk = L.data[tunjuk].next;
        }

    }
}
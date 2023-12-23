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

void addFirst(double nilai, list *L, int n) {
    if (countElement(*L) < n) {
        int baru = emptyElement(*L,n);
        (*L).data[baru].container.nilai = nilai;
        if ((*L).first == -1) (*L).data[baru].next = -1;
        else (*L).data[baru].next = (*L).first;

        (*L).first = baru;
    }
}

void printElement(list L) {
    if (L.first != -1) {
        int tunjuk = L.first, null;
        int depan, valueInt;
        double comma1, comma2;

        while (tunjuk != -1) {
            depan = 0; valueInt = 0; comma1 = 0; comma2 = 0;
            depan = L.data[tunjuk].container.nilai;
            comma1 = (L.data[tunjuk].container.nilai - depan);
            comma2 = comma1 * 100;
            valueInt = comma2;
            L.data[tunjuk].container.mark = valueInt;
            tunjuk = L.data[tunjuk].next;
        }
        int tempMark = 0;
        double tempValue = 0;
        tunjuk = L.first;
        while (tunjuk != -1) {
            tempMark = 0;
            null = L.data[tunjuk].next;
            while(null != -1) {
                if (L.data[tunjuk].container.mark > L.data[null].container.mark) {
                    tempValue = L.data[null].container.nilai;
                    L.data[null].container.nilai = L.data[tunjuk].container.nilai;
                    L.data[tunjuk].container.nilai = tempValue;

                    tempMark = L.data[null].container.mark;
                    L.data[null].container.mark = L.data[tunjuk].container.mark;
                    L.data[tunjuk].container.mark = tempMark;
                }
                null = L.data[null].next;
            }
            tunjuk = L.data[tunjuk].next;
        }

        tunjuk = L.first;
        while (tunjuk != -1) {
            printf("%.2f\n", L.data[tunjuk].container.nilai);
            tunjuk = L.data[tunjuk].next;
        }
        
        
    }
}
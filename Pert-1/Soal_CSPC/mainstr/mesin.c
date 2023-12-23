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
    }
}

void printElement(list L, int n) {
  int iterasi = 0, templeng = 0, totallength = 0;
    if (L.first != -1) {
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1) {
          for (int z = 0; z < strlen(L.data[tunjuk].container.name); z++){
            if(L.data[tunjuk].container.name[z] < 97){
              L.data[tunjuk].container.name[z] += 32;
            }
          }

          tunjuk = L.data[tunjuk].next;
          i += 1;
        }

        tunjuk = L.first;
        i = 1;

        while (tunjuk != -1) {
          templeng = 0;
          iterasi = 0;
          for (int z = 0; z < strlen(L.data[tunjuk].container.name); z++){
            if(L.data[tunjuk].container.name[z] == 'a'){
              iterasi++;
            }
          }
          templeng = iterasi;
          L.data[tunjuk].container.iterator = templeng;
          if (L.data[tunjuk].container.iterator >= totallength) {
            totallength = L.data[tunjuk].container.iterator;
          }
            tunjuk = L.data[tunjuk].next;
            i += 1;
        }
        
        tunjuk = L.first;
        int null = -1;
        char temp[101];
        int tempint;
        while (tunjuk != -1) {
          tempint = 0;
          null = L.data[tunjuk].next;

          while (null != -1) {
            if(L.data[tunjuk].container.iterator > L.data[null].container.iterator) {
              strcpy(temp, L.data[null].container.name);
              strcpy(L.data[null].container.name, L.data[tunjuk].container.name);
              strcpy(L.data[tunjuk].container.name, temp);
              tempint = L.data[null].container.iterator;
              L.data[null].container.iterator = L.data[tunjuk].container.iterator;
              L.data[tunjuk].container.iterator = tempint;
            }
            null = L.data[null].next;
          }
          tunjuk = L.data[tunjuk].next;
        }

        tunjuk = L.first;
        i = 1;
        while (tunjuk != -1) {
          printf ("%s\n", L.data[tunjuk].container.name);
          tunjuk = L.data[tunjuk].next;
          i += 1;
        }
        
    }
}
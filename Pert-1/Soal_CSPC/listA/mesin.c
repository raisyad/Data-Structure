#include "header.h"

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

void addAfter(int prev, char* name, list *L, int n) {
    if (countElement(*L) < n) {
        int baru = emptyElement(*L,n);
        strcpy((*L).data[baru].container.name, name);

        if ((*L).data[prev].next == -1) (*L).data[baru].next = -1;
        else (*L).data[baru].next = (*L).data[prev].next;

        (*L).data[prev].next = baru;
    }
}

void addLast(char* name, list *L, int n) {
    if ((*L).first == -1) addFirst(name, L, n);
    else {
        if (countElement(*L) < n) {
            int prev = (*L).first;
            while ((*L).data[prev].next != -1) prev = (*L).data[prev].next;
            addAfter(prev, name, L, n);
        }
    }
}

void delAfter(int prev, list *L) {
    int hapus = (*L).data[prev].next;
    if (hapus != -1) {
        if ((*L).data[hapus].next == -1) (*L).data[prev].next = -1;
        else (*L).data[prev].next = (*L).data[hapus].next;

        (*L).data[hapus].next = -2;
    }
}

void printElement(list L, int n) {
  int iterasi = 0, templeng = 0, totallength = 0, temp[n];
    if (L.first != -1) {
        int tunjuk = L.first;

        while (tunjuk != -1) {
          for (int z = 0; z < strlen(L.data[tunjuk].container.name); z++){
            if(L.data[tunjuk].container.name[z] < 97){
              L.data[tunjuk].container.name[z] += 32;
            }
          }
          tunjuk = L.data[tunjuk].next;
        }

        tunjuk = L.first;

        while (tunjuk != -1) {
          templeng = 0;
          iterasi = 0;
          for (int z = 0; z < strlen(L.data[tunjuk].container.name); z++){
            if(L.data[tunjuk].container.name[z] == 'a'){
              iterasi++;
            }
          }
          L.data[tunjuk].container.iterator = iterasi;
          tunjuk = L.data[tunjuk].next;
        }

        tunjuk = L.first;
        int prev = L.first;
        int temps = L.first;
        int null = L.first;
        int print = L.first;
        int nexts;
        char tempp[101];
        int i = 0;

        // while (tunjuk != -1) {
        //   printf("%s : prev && %s : tunjuk\n", L.data[prev].container.name, L.data[tunjuk].container.name);

        //   if (tunjuk != prev) {
        //     prev = L.data[prev].next;
        //   }
        //   tunjuk = L.data[tunjuk].next;
        // }

        while (tunjuk != -1) {
          if(tunjuk == L.first) null = L.first;
          else null = tunjuk;
          temps = L.first;
          while (null != -1) {
            if(tunjuk == null) {
              if (temps == tunjuk) {
                printf("%d\n", L.data[null].container.iterator);
                printf("-%s\n", L.data[null].container.name);
              }
              else {
                while (temps != tunjuk) {
                  if(L.data[temps].container.iterator != L.data[tunjuk].container.iterator) {
                    printf("%d\n", L.data[null].container.iterator);
                    printf("-%s\n", L.data[null].container.name);
                  }
                  else if (L.data[temps].container.iterator == L.data[tunjuk].container.iterator) {
                    tunjuk = null;
                  }
                  temps = L.data[temps].next;
                }
              }
            }else {
              if(L.data[tunjuk].container.iterator == L.data[null].container.iterator) {
                printf("-%s\n", L.data[null].container.name);
                tunjuk = prev;
                null = prev;
                // strcpy(temp[i], L.data[null].container.name);
                nexts = L.data[null].next;
                null = L.data[nexts].next;
                // printf("-%s\n", L.data[null].container.name);
                // delAfter(prev, &L);
              }
            }
            // i++;
            if(null != -1)
              null = L.data[null].next;
          }
          if (tunjuk != prev) {
            prev = L.data[prev].next;
          }
          tunjuk = L.data[tunjuk].next;
          // null = L.data[tunjuk].next;
        }




        // while(tunjuk != -1 && i != n) {
        //   null = L.data[tunjuk].next;
        //   while(null != -1) {
        //     if (L.data[tunjuk].container.iterator == L.data[null].container.iterator) {
        //       if (i == 0) {
        //         printf("%d\n", L.data[print].container.iterator);
        //         printf("-%s\n", L.data[print].container.name);
        //         print = L.data[print].next;
        //         i++;
        //         printf("-%s\n", L.data[print].container.name);
        //         print = L.data[print].next;
        //         i++;
        //       }else {
        //         printf("-%s - %d\n", L.data[print].container.name, i);
        //         i++;
        //         print = L.data[print].next;
        //       }
        //     }else if (L.data[tunjuk].container.iterator != L.data[null].container.iterator) {
        //       if (i == 0) {
        //         printf("%d\n", L.data[print].container.iterator);
        //         printf("-%s\n", L.data[print].container.name);
        //         i++;
        //         print = L.data[print].next;
        //       }else {
        //         printf("-%s\n", L.data[print].container.name);
        //         i++;
        //         print = L.data[print].next;
        //       }
        //     }
        //     null = L.data[null].next;
        //     // printf("%d\n", i);
        //   }
        //   tunjuk = L.data[tunjuk].next;
        // }



        // while (tunjuk != -1) {
        //   if (tunjuk == L.first) {
        //     printf("%d\n", L.data[tunjuk].container.iterator);
        //     printf("-%s\n", L.data[tunjuk].container.name);
        //   }else {
        //     if (L.data[null].container.iterator == L.data[tunjuk].container.iterator) {
        //       printf("-%s\n", L.data[tunjuk].container.name);
        //       null = L.data[null].next;
        //     }else if (L.data[null].container.iterator != L.data[tunjuk].container.iterator) {
        //       printf("%d\n", L.data[tunjuk].container.iterator);
        //       printf("-%s\n", L.data[tunjuk].container.name);
        //       null = L.data[null].next;
        //     }
        //   }

        //   tunjuk = L.data[tunjuk].next;
        // }
        
        
    }
}
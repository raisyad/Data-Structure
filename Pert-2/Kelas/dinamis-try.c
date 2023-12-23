#include<stdio.h>
#include<malloc.h>

typedef struct {
    int nilai;
}valueOf;

typedef struct elmt* alamatelmt;

typedef struct elmt {
    valueOf container;
    alamatelmt next;
}element;

typedef struct {
    element* first;
}list;

void createList(list *L){
    (*L).first = NULL;
}

int countElement(list L) {
    int hasil = 0;
    if (L.first != NULL) {
        element* tunjuk;
        tunjuk = L.first;

        while (tunjuk != NULL) {
            hasil += 1;

            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(int nilai, list *L) {
    element* baru;
    baru = (element*) malloc (sizeof(element));
    baru->container.nilai = nilai;

    if ((*L).first == NULL) baru->next = NULL;
    else baru->next = (*L).first;

    (*L).first = baru;
    baru = NULL;
}

void printElement(list L) {
    if (L.first != NULL) {
        element* tunjuk = L.first;
        int i = 1;

        while (tunjuk != NULL){
            printf ("%d\n", tunjuk->container.nilai);

            tunjuk = tunjuk->next;
            i += 1;
        }
    }else printf ("list kosong\n");
}

int main (void){
    list L;
    int n,value;
    scanf ("%d", &n);
    createList(&L);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &value);
        addFirst(value, &L);
    }
    printElement(L);
}
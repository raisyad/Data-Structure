#include<stdio.h>
#include<malloc.h>

typedef struct {
    double nilai;
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

void addFirst(double nilai, list *L) {
    element* baru;
    baru = (element*) malloc(sizeof(element));
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
            printf ("%.2f\n", tunjuk->container.nilai);

            tunjuk = tunjuk->next;
            i += 1;
        }
    }else printf ("list kosong\n");
}

int main (void){
    list L;
    int n;
    double value;
    scanf ("%d", &n);
    createList(&L);
    for (int i = 0; i < n; i++) {
        scanf ("%lf", &value);
        addFirst(value, &L);
    }
    // addFirst(2.11, &L);
    // addFirst(3.11, &L);
    printElement(L);
}
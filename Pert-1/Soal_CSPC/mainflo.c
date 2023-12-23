#include<stdio.h>
#include<malloc.h>

typedef struct {
    double nilai;
    int valueComma;
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
        long int depan, valueInt;
        double comma1, comma2;
        while (tunjuk != NULL){
          depan = 0; valueInt = 0; comma2 = 0; comma1 = 0;
          depan = tunjuk->container.nilai;
          comma1 = (tunjuk->container.nilai - depan);
          comma2 = comma1 * 100;
          valueInt = comma2;

          tunjuk->container.valueComma = valueInt;

          // printf ("%.d\n", valueInt);

            tunjuk = tunjuk->next;
            i += 1;
        }
        tunjuk = L.first;

        // element *tunjuks = L.first;
        element *null = NULL;
        int temp;
        while (tunjuk != NULL) {
          null = tunjuk->next;
          // printf("%d\n", null->container.valueComma);

          while (null != NULL) {
            if(tunjuk->container.valueComma > null->container.valueComma) {
              temp = tunjuk->container.nilai;
              tunjuk->container.nilai = null->container.nilai;
              null->container.nilai = temp;
              // strcpy(temp, tunjuk->container.name);
              // strcpy(L.data[tunjuk].container.name, L.data[null].container.name);
              // strcpy(L.data[null].container.name, temp);
            }
            null = null->next;
          }
          tunjuk = tunjuk->next;
        }
        
        tunjuk = L.first;
        i = 1;
        while (tunjuk != NULL) {
          printf("%.2f\n", tunjuk->container.nilai);

          tunjuk = tunjuk->next;
          i += 1;
        }
        

    }
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
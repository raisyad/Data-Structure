#include"header.h"

int main(void) {
    list L;
    int n;
    scanf ("%d", &n);
    int value;
    createList(&L,n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &value);
        addFirst(value, &L, n);
    }
    printElement(L,n);
}
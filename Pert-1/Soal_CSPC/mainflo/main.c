#include"header.h"

int main(void) {
    list L;
    int n;
    scanf ("%d", &n);
    double value;
    createList(&L,n);
    for (int i = 0; i < n; i++) {
        scanf ("%lf", &value);
        addFirst(value, &L, n);
    }
    printElement(L);
}
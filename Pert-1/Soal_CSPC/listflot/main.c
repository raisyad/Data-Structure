#include"header.h"

int main(void) {
    list L;
    int n;
    scanf ("%d", &n);
    double value[n];
    createList(&L,n);
    for (int i = 0; i < n; i++) {
        scanf ("%lf", &value[i]);
        addFirst(value[i], &L, n);
    }
    printElement(L);
}
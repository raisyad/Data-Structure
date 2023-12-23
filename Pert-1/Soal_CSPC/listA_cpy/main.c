#include"header.h"

int main(void) {
    list L;
    int n;
    scanf ("%d", &n);
    char value[101];
    createList(&L,n);
    for (int i = 0; i < n; i++) {
        scanf ("%s", &value[i]);
        addFirst(&value[i], &L, n);
    }
    printElement(L);
}
#include"header.h"

int main(void) {
    list L;
    int n;
    scanf ("%d", &n);
    int jam, menit, detik;
    createList(&L,n);
    for (int i = 0; i < n; i++) {
        scanf ("%d %d %d", &jam, &menit, &detik);
        addFirst(jam, menit, detik, &L, n);
    }
    printElement(L);
}
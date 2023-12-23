#include"header.h"

int main(void) {
    list L;
    int n;
    scanf ("%d", &n);
    if(n > 100) return 0;
    char* value;
    createList(&L,n);
    for (int i = 0; i < n; i++) {
      scanf ("%s", &value[i]);
      addFirst(&value[i], &L, n);
    }
    printElement(L,n);
}
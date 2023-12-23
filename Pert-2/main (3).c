#include "header.h"

int main()
{
    list llist;
    createList(&llist);
    printEl(llist);
    printf("-------------------------\n");
    isiKontainer data;
    scanf("%s %s %s", data.nim, data.nama, data.nilai);
    addFirst(data, &llist);

    scanf("%s %s %s", data.nim, data.nama, data.nilai);
    addAfter(llist.first, data, &llist);

    scanf("%s %s %s", data.nim, data.nama, data.nilai);
    addLast(data, &llist);

    printEl(llist);
    printf("-------------------------\n");
    char masukan[100];
    scanf("%s", masukan);
    scanf("%s %s %s", data.nim, data.nama, data.nilai);
    elemen *prev = llist.first;
    int find = 0;
    while (prev->next != NULL && find == 0)
    {
        if (strcmp(prev->kontainer.nim, masukan) == 0)
        {
            // printf("find\n");
            addAfter(prev, data, &llist);
            find = 1;
        }
        prev = prev->next;
    }
    printEl(llist);

    return 0;
}
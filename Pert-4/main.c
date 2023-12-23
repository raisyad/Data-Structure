#include "header.h"

int main()
{
    list llist;
    createList(&llist);
    isiKontainer data;

    printEl(llist);
    printf("-------------------------\n");
    scanf("%s %s %s", data.nim, data.nama, data.nilai);
    // addLast(data, &llist);
    addFirst(data, &llist);
    // scanf("%s %s %s", data.nim, data.nama, data.nilai);
    // // addAfter(llist.first, data, &llist);
    // addFirst(data, &llist);
    // // addLast(data, &llist);
    // scanf("%s %s %s", data.nim, data.nama, data.nilai);
    // addFirst(data, &llist);
    // // addLast(data, &llist);
    // scanf("%s %s %s", data.nim, data.nama, data.nilai);
    // addFirst(data, &llist);
    // // addLast(data, &llist);
    // // addFirst(data, &llist);
    // scanf("%s %s %s", data.nim, data.nama, data.nilai);
    // // addLast(data, &llist);
    // // addAfter(llist.first, data, &llist);
    // scanf("%s %s %s", data.nim, data.nama, data.nilai);
    // addFirst(data, &llist);
    // addLast(data, &llist);
    printf("-------------------------\n");
    printEl(llist);
    switchEl(&llist);
    printf("-------------------------\n");
    // delLast(&llist);
    // delAfter(llist.first, &llist);
    // delFirst(&llist);
    printEl(llist);

    return 0;
}
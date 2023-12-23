// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    list llist;
    createList(&llist);
    dataKontainer dataInput;
    int mark = 0;
    while (mark != 1) {
        scanf("%s", dataInput.Desc);
        if (strcmp(dataInput.Desc, "--stop--") == 0) {
            mark = 1;
        }
        if (mark == 0) {
            scanf("%d", &dataInput.Date);
            addFirst(dataInput, &llist);
        }
    }
    printf("==== Inventory Dapur ====\n");
    printEl(dataInput,llist);
    // elemen *prev = llist.first;
    // while (prev->next != NULL)
    // {
    //     if (prev->kontainer.Date < 9)
    //     {
    //         // printf("find\n");
    //         delAfter(prev,&llist);
    //     }
    //     prev = prev->next;
    // }
    // printEl(dataInput,&llist);
    // delAfter(llist.first,&llist);
    printf("=========================\n");








    // scanf("%s %s %s", dataInput.nim, dataInput.nama, dataInput.nilai);
    // addLast(dataInput, &llist);
    // scanf("%s %s %s", dataInput.nim, dataInput.nama, dataInput.nilai);
    // addFirst(dataInput, &llist);
    // scanf("%s %s %s", dataInput.nim, dataInput.nama, dataInput.nilai);
    // addBefore(llist.first->next, dataInput, &llist);

    // printf("Data Golongan Darah\n");
    // printf("===================\n");
    // printEl(llist);

    // scanf("%s %s %s", dataInput.nim, dataInput.nama, dataInput.nilai);
    // addAfter(llist.first->next, dataInput, &llist);
    // delAfter(llist.first,&llist);
    // scanf("%s %s %s", dataInput.nim, dataInput.nama, dataInput.nilai);
    // addAfter(llist.first, dataInput, &llist);
    // scanf("%s %s %s", dataInput.nim, dataInput.nama, dataInput.nilai);
    // addBefore(llist.tail, dataInput, &llist);
    // delFirst(&llist);
    // printf("===================\n");
    // printEl(llist);

    // delLast(&llist);
    // delAfter(llist.first,&llist);
    // scanf("%s %s %s", dataInput.nim, dataInput.nama, dataInput.nilai);
    // addLast(dataInput, &llist);
    // printf("===================\n");
    // printRev(llist);

    // delAll(&llist);
    // printf("===================\n");
    // printEl(llist);

}
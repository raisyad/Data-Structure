#include "header.h"

int main(void) {
    stack s;               // deklarasi stack
    createStack(&s);       // membuat stack kosong
    isiKontainer data_mhs; // membuat tampungan data masukan
    printStack(s);
    printf("======================\n");
    strcpy(data_mhs.label_nim, "13507701");
    strcpy(data_mhs.label_nama, "Nana");
    data_mhs.nilai = 64.75;
    push(data_mhs, &s);
    //
    strcpy(data_mhs.label_nim, "13507702");
    strcpy(data_mhs.label_nama, "Rudi");
    data_mhs.nilai = 75.11;
    push(data_mhs, &s);
    //
    strcpy(data_mhs.label_nim, "13507703");
    strcpy(data_mhs.label_nama, "Dea");
    data_mhs.nilai = 84.63;
    push(data_mhs, &s);
    //
    printStack(s);
    printf("===================\n");
    pop(&s);
    pop(&s);
    printStack(s);
    printf("===================\n");
    pop(&s);
    printStack(s);
}
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM6 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    stack s,s1;             // deklarasi stack
    createStack(&s);       // membuat stack kosong
    createStack(&s1);       // membuat stack kosong
    isiKontainer data_mhs; // membuat tampungan data masukan
    printf ("S1:\n");
    printStack(s);
    printf("S2:\n");
    printStack(s1);
    printf("==================\n");

    scanf("%s %s", data_mhs.Name, data_mhs.Price);
    push(data_mhs, &s);
    scanf("%s %s", data_mhs.Name, data_mhs.Price);
    push(data_mhs, &s1);
    scanf("%s %s", data_mhs.Name, data_mhs.Price);
    push(data_mhs, &s1);

    printf ("S1:\n");
    printStack(s);
    printf("S2:\n");
    printStack(s1);
    printf("==================\n");

    pop(&s);
    popto(&s1,&s);

    scanf("%s %s", data_mhs.Name, data_mhs.Price);
    push(data_mhs, &s);
    scanf("%s %s", data_mhs.Name, data_mhs.Price);
    push(data_mhs, &s1);
    scanf("%s %s", data_mhs.Name, data_mhs.Price);
    push(data_mhs, &s);
    pop(&s1);
    popto(&s,&s1);

    printf ("S1:\n");
    printStack(s);
    printf("S2:\n");
    printStack(s1);
    printf("==================\n");
}
#include "header.h"

void createStack(stack *S) {// prosedur untuk membuat stack kosong
    (*S).top = -1; // inisialisasi pointer top dengan -1/NULL
    (*S).deep = 100;
}

int isEmpty(stack S) {// prosedur untuk cek apakah stack kosong
    int hasil = 0;
    if (S.top == -1) // jika pointer top menunjuk -1/NULL
        hasil = 1; // tanda stack tsb kosong
    return hasil;
}

int isFull(stack S) {// prosedur untuk cek apakah stack penuh
    int hasil = 0;
    if (S.top == MAX - 1) // jika pointer top menunjuk pada 9
        hasil = 1; // tanda stack tsb penuh
    return hasil;
}

void push(isiKontainer kontainer, stack *S) {// prosedur untuk menambahkan elemen ke dalam stack
    if (isFull(*S) == 1) // stack penuh jadi tidak bisa ditambahkan lagi
        printf("stack penuh\n");
    else {// jika stack belum penuh
        if (isEmpty(*S) == 1) {// jika stack kosong
            (*S).top = 0;
            (*S).data[0] = kontainer;
        }
        else {// jika stack tidak kosong
            (*S).top = (*S).top + 1;
            (*S).data[(*S).top] = kontainer;
        }
    }
}

void pop(stack *S) {// prosedur untuk mengambil elemen dari stack
    if ((*S).top == 0) // jika stack berisi 1 elemen
        (*S).top = -1;
    else
        if ((*S).top != -1) // jika stack berisi > 1 elemen
            (*S).top = (*S).top - 1;
}

void tanda(stack *S, char pilih[]) {
    if((*S).top != -1) {
        int tunjuk = (*S).top;
        do {
            if(strcmp((*S).data[tunjuk].label_nama, pilih) == 0){
                (*S).data[tunjuk].tanda = 1;
                if((*S).deep > tunjuk)
                    (*S).deep = tunjuk;
            }
            tunjuk = tunjuk - 1;

        } while (tunjuk >= 0);
    }
}

void ambil(stack *S, stack *S2) {
    if((*S).top != -1) {
        if((*S).deep != 100) {
            int tunjuk = (*S).top;
            do {
                if((*S).data[tunjuk].tanda == 0)
                    push((*S).data[tunjuk], S2);
                pop(S);
                tunjuk = tunjuk - 1;
            }while(tunjuk + 1 > (*S).deep);
        }
    }
}

// void poptopush(stack *S, stack *S2, char pilih[])
// {
//     if ((*S).top != -1) // jika stack tidak kosong
//     {
//         // int apa = 0;
//         int tanda = (*S).top;
//         int cek = 0;
//         do
//         {
//             if(strcmp((*S).data[tanda].label_nama, pilih) == 0)
//             {
//                 cek = 1;
//             }
//             tanda = tanda - 1;
//             // apa++; 
//         } while (strcmp((*S).data[tanda+1].label_nama, pilih) != 0 && tanda >= 0);
            
//         if (cek == 1)
//         {
//             tanda = (*S).top; 
//             // int tunjuk = (*S).top;
//             do
//             {
//                 if(strcmp((*S).data[tanda].label_nama, pilih) != 0)
//                 {
//                     push((*S).data[tanda],S2); 
//                 }
//                 tanda = tanda - 1;
//                 pop(S);
//             }while(strcmp((*S).data[tanda].label_nama, pilih) != 0 && tanda >= 0);
//         }
//     }
//     // if((*S2).top != -1)
//     // {
//     //     int tanda = (*S2).top;
//     //     do
//     //     {
//     //         if(strcmp((*S).data[tanda].label_nama, pilih) == 0)
//     //         {
//     //             pop(S2);
//     //         }
//     //         tanda = tanda - 1;
//     //     } while (strcmp((*S).data[tanda+1].label_nama, pilih) != 0 && tanda >= 0);
//     // }
// }

void printStack(stack S) {// prosedur untuk menampilkan isi stack
    if (S.top != -1) // jika stack tidak kosong
        for (int i = S.top; i >= 0; i--) // menampilkan dari elemen paling baru masuk
            printf("%s %s\n", S.data[i].label_nama, S.data[i].label_nim);
    else
        printf("stack kosong\n");
}


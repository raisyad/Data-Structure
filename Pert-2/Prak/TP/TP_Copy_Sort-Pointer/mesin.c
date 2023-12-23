// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Praktikum TP1 (KBT22) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// membuat list
void createList(list *L) { (*L).first = NULL; } //insialisasi bahwa belum ada data yang diisikan // pembuatan list

void addFirst(char Judul[201], char Production[201], char ratingFilm[201], list *L) {
    elemen *baru; //membuat pointer bungkusan baru
    baru = (elemen *)malloc(sizeof(elemen)); //lalu baru diinisialisasi

    // dibawah ini merupakan proses pengisian data
    strcpy(baru->kontainer.Judul, Judul);
    strcpy(baru->kontainer.Production, Production);
    strcpy(baru->kontainer.ratingFilm, ratingFilm);

    // jika list kosong
    if ((*L).first == NULL) baru->next = NULL;
    // jika bukan list kosong (ada isinya)
    else baru->next = (*L).first;

    (*L).first = baru;
    baru = NULL;
}

void SortingDatas(list *L, char SortedData[201], char methods[201], filmGeber kontainer) {
    if ((*L).first != NULL) { //Jika list tidak kosong
        elemen *tunjuk, *null, *temps, *prev, *current, *prevEl, *tempsV; //inisialisasi
        tunjuk = (elemen *)malloc(sizeof(elemen)); null = (elemen *)malloc(sizeof(elemen));
        prevEl = (elemen *)malloc(sizeof(elemen));
        prev = (elemen *)malloc(sizeof(elemen));
        current = (elemen *)malloc(sizeof(elemen));
        // tunjuk = (*L).first;
        // prev = (*L).first;
        int mark = 0, loop, res;

        if (strcmp(SortedData, "judul") == 0) { //jika data pengurutan memilih judul
            if (strcmp(methods, "asc") == 0) { //dan menggunakan metode ascending, maka lakukan proses dibawah ini
            // Membandingkan data asal dengan data nextnya atau data sebelahnya

                // prev = (*L).first;

                // tunjuk = (*L).first;
                // prev = NULL;
                // while (tunjuk->next != NULL) {
                //     null = tunjuk->next;
                //     // printf("%s\n", null->kontainer.Judul);
                //     while (null != NULL) {
                //         // PrintOutElement(*L);
                //         // printf("============\n");
                //         if(strcmp(tunjuk->kontainer.Judul, null->kontainer.Judul) > 0) {
                //             // printf("%s - %s\n", tunjuk->kontainer.Judul, null->kontainer.Judul);
                //             // printf("--------------\n");
                //             prevEl = tunjuk;
                //             while (prevEl->next != null) {
                //                 // printf("%s - %s - %s - %s\n", prevEl->kontainer.Judul, null->kontainer.Judul, prev->kontainer.Judul, tunjuk->kontainer.Judul);
                //                 // if (prevEl == null) {
                //                 //     res = 1;
                //                 // }
                //                 prevEl = prevEl->next;
                //             }
                //             if(prev == NULL) {
                //                 if (prevEl == tunjuk) {
                //                     (*L).first = null;
                //                     tunjuk->next = null->next;
                //                     null->next = tunjuk;
                //                 }else {
                //                     (*L).first = tunjuk->next;
                //                     tunjuk->next = null->next;
                //                     null->next = tunjuk;
                //                     prevEl->next = null->next;
                //                     null->next = (*L).first;
                //                     (*L).first = null;
                //                 }
                //             }else {
                //                 if (prevEl == tunjuk) {
                //                     prev->next = null;
                //                     tunjuk->next = null->next;
                //                     null->next = tunjuk;
                //                 }else {
                //                     prev->next = tunjuk->next;
                //                     tunjuk->next = null->next;
                //                     null->next = tunjuk;
                //                     prevEl->next = null->next;
                //                     null->next = prev->next;
                //                     prev->next = null;
                //                 }
                //             }
                //             temps = tunjuk;
                //             tunjuk = null;
                //             null = temps;
                //         }
                //         null = null->next;
                //     }
                //     prev = tunjuk;
                //     tunjuk = tunjuk->next;
                // }

                // AA--------------
                tunjuk = (*L).first;
                prev = NULL;
                while (tunjuk != NULL) {
                    null = tunjuk->next;
                    // printf("%s\n", null->kontainer.Judul);
                    while (null != NULL) {
                        if(strcmp(tunjuk->kontainer.Judul, null->kontainer.Judul) > 0) {
                            res = 0;
                            prevEl = tunjuk;
                            while (prevEl->next != null) {
                                // printf("%s - %s - %s - %s\n", prevEl->kontainer.Judul, null->kontainer.Judul, prev->kontainer.Judul, tunjuk->kontainer.Judul);
                                prevEl = prevEl->next;
                            }
                            if(prev == NULL) {
                                if (prevEl == tunjuk) {
                                    (*L).first = null;
                                    tunjuk->next = null->next;
                                    null->next = tunjuk;
                                }else {
                                    (*L).first = tunjuk->next;
                                    tunjuk->next = null->next;
                                    null->next = tunjuk;
                                    prevEl->next = null->next;
                                    null->next = (*L).first;
                                    (*L).first = null;
                                }
                                // temps = tunjuk->next;
                                // tunjuk->next = null->next;
                                // null->next = temps;
                                // prevEl->next = tunjuk;
                            }else {
                                if (prevEl == tunjuk) {
                                    prev->next = null;
                                    tunjuk->next = null->next;
                                    null->next = tunjuk;
                                }else {
                                    prev->next = tunjuk->next;
                                    tunjuk->next = null->next;
                                    null->next = tunjuk;
                                    prevEl->next = null->next;
                                    null->next = prev->next;
                                    prev->next = null;
                                }
                                // temps = tunjuk->next;
                                // tunjuk->next = null->next;
                                // null->next = temps;
                                // prevEl->next = tunjuk;
                                // prev->next = null;
                            }
                            tempsV = tunjuk;
                            tunjuk = null;
                            null = tempsV;
                        }
                        null = null->next;
                    }
                    prev = tunjuk;
                    // printf("%s\n", prev->kontainer.Judul);
                    tunjuk = tunjuk->next;
                }
                // --------------------

                // PrintOutElement(*L);

                // while (tunjuk != NULL) {
                //     // if (null->next == NULL && tunjuk->next == null) {
                //     //     tunjuk = NULL;
                //     // }
                //     while (null != NULL) {
                //         printf("hai\n");
                //         // int res = 1;
                //         // prevEl = tunjuk;
                //         // while (prevEl->next != NULL && res != 0) {
                //         //     if (prevEl->next == null) {
                //         //         printf("%s - %s\n", prevEl->next->kontainer.Judul, null->kontainer.Judul);
                //         //         prevEl = prevEl->next;
                //         //         res = 0;
                //         //     }
                //         //     prevEl = prevEl->next;
                //         // }
                //         // printf("------------------\n");
                //         // PrintOutElement(*L);
                //         temps = tunjuk;
                //         if (strcmp(tunjuk->kontainer.Judul, null->kontainer.Judul) > 0) {
                //             loop = 0;
                //             if (tunjuk == (*L).first) {
                //                 prevEl = tunjuk;
                //                 int res = 1;
                //                 while (prevEl != null) {
                //                     // printf("%s- %s\n", prevEl->kontainer.Judul, null->kontainer.Judul);
                //                     if (prevEl == null) {
                //                         res = 1;
                //                     }
                //                     prevEl = prevEl->next;
                //                 }
                //                 temps = tunjuk->next;
                //                 tunjuk->next = null->next;
                //                 null->next = temps;
                //                 prevEl->next = tunjuk;
                //             }else {
                //                 prevEl = tunjuk;
                //                 int res = 1;
                //                 while (prevEl != null) {
                //                     // printf("%s- %s\n", prevEl->kontainer.Judul, null->kontainer.Judul);
                //                     if (prevEl == null) {
                //                         res = 1;
                //                     }
                //                     prevEl = prevEl->next;
                //                 }
                //                 temps = tunjuk->next;
                //                 prev->next = null;
                //                 null->next = tunjuk->next;
                //                 null->next = temps;
                //                 prevEl->next = tunjuk;

                //             }
                //         }
                //         null = null->next;
                //     }
                //     // printf ("%d\n", tunjuk);
                //     prev = tunjuk;
                //     tunjuk = tunjuk->next;
                // }
            }else if (strcmp(methods, "desc") == 0) { //atau menggunakan metode descending, maka lakukan proses dibawah ini
            // Membandingkan data asal dengan data nextnya atau data sebelahnya
                while (tunjuk != NULL) { // jika data belum null
                    null = tunjuk->next; //iterasi
                    while (null != NULL) { // jika data belum null
                        if (strcmp(tunjuk->kontainer.Judul, null->kontainer.Judul) < 0) {
                            temps = tunjuk;
                            tunjuk->kontainer = null->kontainer;
                            null->kontainer = temps->kontainer;
                        }
                        // Iterasi
                        null = null->next;
                    }
                    // Iterasi
                    tunjuk = tunjuk->next;
                }
            }
        }else if (strcmp(SortedData, "rating") == 0) { //jika data pengurutan memilih rating
            if (strcmp(methods, "asc") == 0) { //dan menggunakan metode ascending, maka lakukan proses dibawah ini
            // Membandingkan data asal dengan data nextnya atau data sebelahnya
                while (tunjuk != NULL) { // jika data belum null
                    null = tunjuk->next; //iterasi
                    while (null != NULL) { // jika data belum null
                        if (strcmp(tunjuk->kontainer.ratingFilm, null->kontainer.ratingFilm) > 0) {
                            temps->kontainer = tunjuk->kontainer;
                            tunjuk->kontainer = null->kontainer;
                            null->kontainer = temps->kontainer;
                        }
                        // Iterasi
                        null = null->next;
                    }
                    // Iterasi
                    tunjuk = tunjuk->next;
                }
            }else if (strcmp(methods, "desc") == 0) { //atau menggunakan metode descending, maka lakukan proses dibawah ini
                // Membandingkan data asal dengan data nextnya atau data sebelahnya
                while (tunjuk != NULL) { // jika data belum null
                    null = tunjuk->next; //iterasi
                    while (null != NULL) { // jika data belum null
                        if (strcmp(tunjuk->kontainer.ratingFilm, null->kontainer.ratingFilm) < 0) {
                            temps->kontainer = tunjuk->kontainer;
                            tunjuk->kontainer = null->kontainer;
                            null->kontainer = temps->kontainer;
                        }
                        // Iterasi
                        null = null->next;
                    }
                    // Iterasi
                    tunjuk = tunjuk->next;
                }
            }
        }
    }
}

void PrintOutElement (list L) {
    elemen *tunjuk = L.first; // inisialisasi pointer bungkusan dengan data awal
    while (tunjuk != NULL) { // jika data belum null
    // Maka tampilkan output dibawah ini
        printf("%s - %s\n", tunjuk->kontainer.Judul, tunjuk->kontainer.Production);

        // Iterasi
        tunjuk = tunjuk->next;
    }
}
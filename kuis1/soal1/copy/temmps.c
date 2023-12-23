// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createList1(list *L) {
    (*L).first1 = -1;
    (*L).tail1 = -1;
    int i;
    
    for (i = 0; i < 100; i++) {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    } // <-- Proses menginisialisasi isi dari array berdasarkan List
}

void createList2(list *L) {
    (*L).first2 = -1;
    (*L).tail2 = -1;
    int i;
    
    for (i = 0; i < 100; i++) {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    } // <-- Proses menginisialisasi isi dari array berdasarkan List
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first1 != -1)
    {
        /* list tidak kosong */
        int hitung;
        /* inisialisasi */
        hitung = L.first1;
        while (hitung != -1)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

int emptyElement(list L)
{
    int hasil = -1;

    if (countElement(L) < 10)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 10))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst1(char kode1[], char kode2[], list *L)
{

    if (countElement(*L) < 100)
    {
        // Bikin list baru
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kode1, kode1);
        strcpy((*L).data[baru].kontainer.kode2, kode2);

        // Cari data first yang memiliki NULL
        if ((*L).first1 == -1) {
            /*jika list kosong, pasangkan list baru dengan NULL*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail1 = baru;
        }
        else {
            /*jika list tidak kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first1;
            (*L).data[(*L).first1].prev = baru;
        }

        // Rubah first dengan baru
        (*L).first1 = baru;
    }
    else
    {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter1(int before, char kode1[], char kode2[], list *L)
{
    if (before != -1)
    {
        if (countElement(*L) < 100)
        {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.kode1, kode1);
            strcpy((*L).data[baru].kontainer.kode2, kode2);

            if ((*L).data[before].next != -1)
            {
                (*L).data[baru].prev = before;
                (*L).data[baru].next = (*L).data[before].next;
                (*L).data[before].next = baru;
                (*L).data[(*L).data[baru].next].prev = baru;
            }
            else
            {
                (*L).data[baru].prev = before;
                (*L).data[before].next = baru;
                (*L).data[baru].next = -1;
                (*L).tail1 = baru;
            }
        }
    }
}

void addLast1(char kode1[], char kode2[], list *L1)
{
    if ((*L1).first1 == -1) {
        /*proses jika list masih kosong*/
        addFirst1(kode1, kode2, L1);
    }
    else
    {
        /*proses jika list telah berisi elemen*/
        addAfter1((*L1).tail1, kode1, kode2, L1);
    }
}

void addFirst2(char kode1[], char kode2[], list *L)
{

    if (countElement(*L) < 100)
    {
        // Bikin list baru
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kode1, kode1);
        strcpy((*L).data[baru].kontainer.kode2, kode2);

        // Cari data first yang memiliki NULL
        if ((*L).first2 == -1)
        {
            /*jika list kosong, pasangkan list baru dengan NULL*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail2 = baru;
        }
        else
        {
            /*jika list tidak kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first2;
            (*L).data[(*L).first2].prev = baru;
        }

        // Rubah first dengan baru
        (*L).first2 = baru;
    }
}

void addAfter2(int before, char kode1[], char kode2[], list *L)
{
    if (before != -1)
    {
        if (countElement(*L) < 100)
        {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.kode1, kode1);
            strcpy((*L).data[baru].kontainer.kode2, kode2);

            if ((*L).data[before].next != -1)
            {
                (*L).data[baru].prev = before;
                (*L).data[baru].next = (*L).data[before].next;
                (*L).data[before].next = baru;
                (*L).data[(*L).data[baru].next].prev = baru;
            }
            else
            {
                (*L).data[baru].prev = before;
                (*L).data[before].next = baru;
                (*L).data[baru].next = -1;
                (*L).tail2 = baru;
            }
        }
    }
}

void addLast2(char kode1[], char kode2[], list *L2)
{
    if ((*L2).first2 == -1)
    {
        /*proses jika list masih kosong*/
        addFirst1(kode1, kode2, L2);
    }
    else
    {
        /*proses jika list telah berisi elemen*/
        addAfter1((*L2).tail2, kode1, kode2, L2);
    }
}

// ==========================

// void addFirst2(dataKontainer kontainer, list *L) {
//     elemen *newPtr;
//     newPtr = (elemen *)malloc(sizeof(elemen));

//     newPtr->kontainer = kontainer;

//     if ((*L).first2 == NULL) {
//         newPtr->next = NULL;
//         newPtr->prev = NULL;
//         (*L).tail2 = newPtr;
//     }
//     else {
//         newPtr->next = (*L).first2;
//         newPtr->prev = NULL;
//         (*L).first2->prev = newPtr;
//     }

//     (*L).first2 = newPtr;
//     newPtr = NULL;
// }

// void addAfter2(elemen *before, dataKontainer kontainer, list *L) {
//     if (before != NULL) {
//         elemen *newPtr;
//         newPtr = (elemen *)malloc(sizeof(elemen));

//         newPtr->kontainer = kontainer;

//         if (before->next == NULL) {
//             newPtr->next = NULL;
//             (*L).tail2 = newPtr;
//         }
//         else {
//             newPtr->next = before->next;
//             newPtr->next->prev = newPtr;
//         }
//         newPtr->prev = before;
//         before->next = newPtr;
//         newPtr = NULL;
//     }
// }

// void addLast2(dataKontainer kontainer, list *L) {
//     if ((*L).first2 == NULL)
//         addFirst2(kontainer, L);
//     else
//         addAfter2((*L).tail2, kontainer, L);
// }

// ===================

void printEl1(list L) {
    if (L.first1 != -1) {
        int ptr = L.first1;
        while (ptr != -1) {
            printf("%s %s\n", L.data[ptr].kontainer.kode1, L.data[ptr].kontainer.kode2);
            ptr = L.data[ptr].next;
        }
    }
    else
        printf("List Kosong\n");
}

void printEl2(list L) {
    if (L.first2 != -1) {
        int ptr = L.first2;
        while (ptr != -1) {
            printf("%s %s\n", L.data[ptr].kontainer.kode1, L.data[ptr].kontainer.kode2);
            ptr = L.data[ptr].next;
        }
    }
    else
        printf("List Kosong\n");
}


void sortEl(list *L1, list *L2, int p) {
    // elemen *current1, *current2, *temp1, *temp2, *temp3;
    // elemen *cBef1, *cBef2;
    // current1 = (elemen *)malloc(sizeof(elemen));
    // current2 = (elemen *)malloc(sizeof(elemen));
    // cBef1 = (elemen *)malloc(sizeof(elemen));
    // cBef2 = (elemen *)malloc(sizeof(elemen));
    // current1 = (*L1).first1;
    // current2 = (*L2).first2;
    // cBef1 = (*L1).tail1;
    // cBef2 = (*L2).tail2;
    elemen temp, temp2;
    int depan1, depan2, belakang1, belakang2;
    depan1 = (*L1).first1;
    belakang1 = (*L1).tail1;
    depan2 = (*L2).first2;
    belakang2 = (*L2).tail2;

    for (int i = 0; i < p; i++) {
        temp.kontainer = (*L1).data[depan1].kontainer;
        (*L1).data[depan1].kontainer = (*L2).data[depan2].kontainer;
        (*L2).data[depan2].kontainer = temp.kontainer;

        temp2.kontainer = (*L1).data[belakang1].kontainer;
        (*L1).data[belakang1].kontainer = (*L2).data[belakang2].kontainer;
        (*L2).data[belakang2].kontainer = temp.kontainer;

        // (*L).data[depan].kontainer = (*L).data[belakang].kontainer;
        // (*L).data[belakang].kontainer = temp.kontainer;
        depan1 = (*L1).data[depan1].next;
        depan2 = (*L2).data[depan2].next;
        belakang1 = (*L1).data[belakang1].prev;
        belakang2 = (*L2).data[belakang2].prev;
    }
    // for (int i = 0; i < p; i++) {
    //     while ((current1 != NULL && current2 != NULL) && (cBef1 != NULL && cBef2 != NULL)) {
    //         if ((current1 == (*L1).first1 && current2 == (*L2).first2)) {
    //             // temp1 = current2->next;
    //             // temp3 = current2->next->prev;
    //             // current2->next = current2->next;
    //             // current1->next->prev = current2;

    //             // current2->next = temp1;
    //             // current2 = temp3;

    //             temp1 = current1->next;
    //             temp3 = current1->next->prev;
    //             current1->next = current2->next;
    //             current2->next->prev = current1;

    //             current2->next = temp1;

    //             current2 = temp3;

    //             temp2 = current1;
    //             current1 = current2;
    //             current2 = temp2;
    //             // printf("hai\n");
    //         }else {

    //         }
    //         if (cBef1 == (*L1).tail1 && cBef2 == (*L2).tail2) {
    //             temp1 = cBef1->prev;
    //             temp3 = cBef1->prev->next;
    //             // printf("--%s--\n", cBef1->prev->next->kontainer.kode1);
    //             // printf("--%s--\n", cBef2->prev->next->kontainer.kode1);
    //             cBef1->next = cBef2->next;
    //             cBef2->prev->next = cBef1;
    //             cBef1->prev->next = cBef2;
    //             cBef2->prev = temp1;


    //             temp2 = cBef1;
    //             cBef1 = cBef2;
    //             cBef2 = temp2;
    //         }
    //         current1 = current1->next;
    //         current2 = current2->next;
    //         cBef1 = cBef1->prev;
    //         cBef2 = cBef2->prev;
    //     }
    // }
    // while (cBef1 != NULL && cBef2 != NULL) {
    //     if (cBef1 == (*L1).tail1 && cBef2 == (*L2).tail2) {
    //             // temp1 = current2->next;
    //             // temp3 = current2->next->prev;
    //             // current2->next = current2->next;
    //             // current1->next->prev = current2;

    //             // current2->next = temp1;
    //             // current2 = temp3;

    //             temp1 = cBef1->next;
    //             temp3 = cBef1->prev->next;
    //             cBef1->next = cBef2->next;
    //             cBef2->prev->next = cBef1;

    //             cBef2->next = temp1;

    //             cBef2 = temp3;

    //             temp2 = cBef1;
    //             cBef1 = cBef2;
    //             cBef2 = temp2;
    //             printf("hai\n");
    //         }
    //         cBef1 = cBef1->prev;
    //         cBef2 = cBef2->prev;
    // }
    
    printEl2((*L2));
    printEl1((*L1));
}

// void switchEl(list *L) {
//     elemen *front = (*L).first;
//     elemen *back = (*L).tail;
//     dataKontainer temp;
//     for (int i = 0; i <= (countEl(*L) / 2); i++) {
//         temp = front->kontainer;
//         front->kontainer = back->kontainer;
//         back->kontainer = temp;

//         front = front->next;
//         back = back->prev;
//     }
// }
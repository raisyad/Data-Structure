// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createList1(list *L) {
    (*L).first1 = NULL;
    (*L).tail1 = NULL;
}

void createList2(list *L) {
    (*L).first2 = NULL;
    (*L).tail2 = NULL;
}

int countEl(list L) {
    int sum = 0;
    if (L.first != NULL) {
        elemen *ptr;
        ptr = L.first;
        while (ptr != NULL) {
            sum++;
            ptr = ptr->next;
        }
    }
    return sum;
}

void addFirst1(dataKontainer kontainer, list *L) {
    elemen *newPtr;
    newPtr = (elemen *)malloc(sizeof(elemen));

    newPtr->kontainer = kontainer;

    if ((*L).first1 == NULL) {
        newPtr->next = NULL;
        newPtr->prev = NULL;
        (*L).tail1 = newPtr;
    }
    else {
        newPtr->next = (*L).first1;
        newPtr->prev = NULL;
        (*L).first1->prev = newPtr;
    }

    (*L).first1 = newPtr;
    newPtr = NULL;
}

void addAfter1(elemen *before, dataKontainer kontainer, list *L) {
    if (before != NULL) {
        elemen *newPtr;
        newPtr = (elemen *)malloc(sizeof(elemen));

        newPtr->kontainer = kontainer;

        if (before->next == NULL) {
            newPtr->next = NULL;
            (*L).tail1 = newPtr;
        }
        else {
            newPtr->next = before->next;
            newPtr->next->prev = newPtr;
        }
        newPtr->prev = before;
        before->next = newPtr;
        newPtr = NULL;
    }
}

// ==============================================

void addLast1(dataKontainer kontainer, list *L) {
    if ((*L).first2 == NULL)
        addFirst2(kontainer, L);
    else
        addAfter2((*L).tail1, kontainer, L);
}

void addFirst2(dataKontainer kontainer, list *L) {
    elemen *newPtr;
    newPtr = (elemen *)malloc(sizeof(elemen));

    newPtr->kontainer = kontainer;

    if ((*L).first2 == NULL) {
        newPtr->next = NULL;
        newPtr->prev = NULL;
        (*L).tail2 = newPtr;
    }
    else {
        newPtr->next = (*L).first2;
        newPtr->prev = NULL;
        (*L).first2->prev = newPtr;
    }

    (*L).first2 = newPtr;
    newPtr = NULL;
}

void addAfter2(elemen *before, dataKontainer kontainer, list *L) {
    if (before != NULL) {
        elemen *newPtr;
        newPtr = (elemen *)malloc(sizeof(elemen));

        newPtr->kontainer = kontainer;

        if (before->next == NULL) {
            newPtr->next = NULL;
            (*L).tail2 = newPtr;
        }
        else {
            newPtr->next = before->next;
            newPtr->next->prev = newPtr;
        }
        newPtr->prev = before;
        before->next = newPtr;
        newPtr = NULL;
    }
}

void addLast2(dataKontainer kontainer, list *L) {
    if ((*L).first2 == NULL)
        addFirst2(kontainer, L);
    else
        addAfter2((*L).tail2, kontainer, L);
}

void printEl1(list L) {
    if (L.first1 != NULL) {
        elemen *ptr = L.first1;
        while (ptr != NULL) {
            printf("%s %s\n", ptr->kontainer.kode1, ptr->kontainer.kode2);
            ptr = ptr->next;
        }
    }
    else
        printf("List Kosong\n");
}

void printEl2(list L) {
    if (L.first2 != NULL) {
        elemen *ptr = L.first2;
        while (ptr != NULL) {
            printf("%s %s\n", ptr->kontainer.kode1, ptr->kontainer.kode2);
            ptr = ptr->next;
        }
    }
    else
        printf("List Kosong\n");
}

void sortEl(list *L) {
    
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
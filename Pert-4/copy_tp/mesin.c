// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGD22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createList(list *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
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

void addFirst(dataKontainer kontainer, list *L) {
    elemen *newPtr;
    newPtr = (elemen *)malloc(sizeof(elemen));

    newPtr->kontainer = kontainer;

    if ((*L).first == NULL) {
        newPtr->next = NULL;
        newPtr->prev = NULL;
        (*L).tail = newPtr;
    }
    else {
        newPtr->next = (*L).first;
        newPtr->prev = NULL;
        (*L).first->prev = newPtr;
    }

    (*L).first = newPtr;
    newPtr = NULL;
}

void addAfter(elemen *before, dataKontainer kontainer, list *L) {
    if (before != NULL) {
        elemen *newPtr;
        newPtr = (elemen *)malloc(sizeof(elemen));

        newPtr->kontainer = kontainer;

        if (before->next == NULL) {
            newPtr->next = NULL;
            (*L).tail = newPtr;
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

void addBefore (elemen *before, dataKontainer kontainer, list *L) {
    if (before == (*L).first) 
        addFirst(kontainer,L);
    else
        addAfter(before->prev,kontainer,L); 
}

void addLast(dataKontainer kontainer, list *L) {
    if ((*L).first == NULL)
        addFirst(kontainer, L);
    else
        addAfter((*L).tail, kontainer, L);
}

void delFirst(list *L) {
    if ((*L).first != NULL) {
        elemen *delPtr = (*L).first;
        if (countEl(*L) == 1) {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            delPtr->next = NULL;
        }
        free(delPtr);
    }
}

void delAfter(elemen *before, list *L) {
    if (before != NULL) {
        elemen *delPtr = before->next;
        if (delPtr != NULL) {
            if (delPtr->next == NULL){
                (*L).tail = before;
                before->next = NULL;
            }
            else {
                before->next = delPtr->next;
                delPtr->next->prev = before;
                delPtr->next = NULL;
            }
            delPtr->prev = NULL;
            free(delPtr);
        }
    }
}

void delLast(list *L) {
    if ((*L).first != NULL) {
        if (countEl(*L) == 1)
            delFirst(L);
        else
            delAfter((*L).tail->prev, L);
    }
}

void printEl(dataKontainer kontainer, list L) {
    if (L.first != NULL) {
        sortDescDate(kontainer, &L);
        elemen *ptr = L.first;

        printf("List semua bahan:\n");
        while (ptr != NULL) {
            if (ptr->kontainer.Date <= 9) {
                printf("0%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }else {
                printf("%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }
            ptr = ptr->next;
        }
        
        ptr = L.first;
        int mark = 0;
        printf("List bahan kadaluarsa:\n");
        while (ptr != NULL) {
            if (ptr->kontainer.Date == 8) {
                // if (ptr == L.first) {
                //     delFirst(&L);
                // }else if (ptr == L.tail) {
                //     delLast(&L);
                // }else {
                // }
                printf("0%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);   
                delAfter(ptr,&L);
                // if(ptr->next == NULL) {
                //     // delLast(L);
                // }else {
                //     printf("%d\n", i);
                //     delAfter(ptr,L);
                // }
                // delAfter(ptr,L);
            }else {
                if (mark == 0 && ptr->kontainer.Date != 9) {
                    printf("-\n");
                    mark = 1;
                }
            }
            printf("0%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            // printf ("%d\n", i);
            ptr = ptr->next;
        }
        sortAscDesc(kontainer, &L);
        mark = 0;
        ptr = L.first;
        printf("List bahan sisa:\n");
        while (ptr != NULL) {
            if (ptr->kontainer.Date == 9) {
                printf("0%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }else if (ptr->kontainer.Date > 9) {
                printf("%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }else {
                if (mark == 0 && ptr->kontainer.Date >= 9) {
                    printf("-\n");
                    mark = 1;
                }
            }

            // printf("%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            // delAfter(ptr,L);
            ptr = ptr->next;
        }

        // ptr = (*L).first;
        // while (ptr != NULL) {
        //     if (ptr->kontainer.Date == 9) {
        //         printf("%0d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
        //     }else {
        //         printf("%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
        //     }
        //     // delAfter(ptr,L);
        //     ptr = ptr->next;
        // }

    }
}

void printRev(list L) {
    if (L.first != NULL) {
        elemen *ptr = L.tail;
        while (ptr != NULL) {
            printf("%s %s\n", ptr->kontainer.Desc, ptr->kontainer.Date);
            ptr = ptr->prev;
        }
    }
    else
        printf("List Kosong\n");
}

void delAll(list *L) {
    if (countEl(*L) != 0)
        for (int i = countEl(*L); i >= 1; i--)
            delLast(L);
}

void switchEl(list *L) {
    elemen *front = (*L).first;
    elemen *back = (*L).tail;
    dataKontainer temp;
    for (int i = 0; i <= (countEl(*L) / 2); i++) {
        temp = front->kontainer;
        front->kontainer = back->kontainer;
        back->kontainer = temp;

        front = front->next;
        back = back->prev;
    }
}

void sortDescDate(dataKontainer kontainer, list *L) {
    elemen *current, *front, *tempPtr, *tempEl1, *tempEl2, *tempNP, *tempPN;
    current = (elemen *)malloc(sizeof(elemen));
    front = (elemen *)malloc(sizeof(elemen));
    tempPtr = (elemen *)malloc(sizeof(elemen));
    tempEl1 = (elemen *)malloc(sizeof(elemen));
    tempEl2 = (elemen *)malloc(sizeof(elemen));
    tempNP = (elemen *)malloc(sizeof(elemen));
    tempPN = (elemen *)malloc(sizeof(elemen));

    current = (*L).first;
    
    while (current->next != NULL) {
        front = current->next;
        // printf("%s-\n", current->kontainer.Date);
        // printf("current : %s front : %s\n", current->kontainer.Date, front->kontainer.Date);
        while (front != NULL) {
            // printf("current2 : %s front2 : %s\n", current->kontainer.Date, front->kontainer.Date);
            // printf("frontnext : %s\n", check->next->kontainer.Date);
            if (current->kontainer.Date < front->kontainer.Date){
                if (current->next == front) {
                    // printf("1\n");
                    if (current->prev == NULL){
                        (*L).first = front;
                    }
                    tempEl1 = current->next;
                    current->next = front->next;
                    if(current->next != NULL) {
                        // printf("iif--%s--\n", current->prev->kontainer.Date);
                        current->next->prev = current;
                    }
                    if (current->prev != NULL) {
                        current->prev->next = front;
                    }
                    // printf("3\n");
                    // front->next = tempEl1;

                    front->next = current;
                    tempEl2 = current->prev;
                    current->prev = front;
                    front->prev = tempEl2;
                    // printf("4\n");
                    // printf("/--%s - %s--@@\n", current->kontainer.Date, front->kontainer.Date);
                    tempPtr = current;
                    current = front;
                    front = tempPtr;

                }else {
                    // printf("2\n");
                    if (current->prev == NULL){
                        (*L).first = front;
                    }

                    current->next->prev = front;
                    front->prev->next = current;
                    if (front->next != NULL) {
                        front->next->prev = current;
                    }
                    if (current->prev != NULL) {
                        current->prev->next = front;
                    }

                    tempEl1 = current->next;
                    current->next = front->next;
                    front->next = tempEl1;

                    tempEl2 = front->prev;
                    front->prev = current->prev;
                    current->prev = tempEl2;

                    // printf("/--%s - %s--@@\n", current->kontainer.Date, front->kontainer.Date);
                    tempPtr = current;
                    current = front;
                    front = tempPtr;
                }

                // if (current->next == front){
                // }
            }
            // if ((*L).first != NULL) {
            //     elemen *ptr = (*L).first;
            //     while (ptr != NULL) {
            //         printf("%s %d\n", ptr->kontainer.Desc, ptr->kontainer.Date);
            //         ptr = ptr->next;
            //     }
            // }

            // printf("--%s - %s--\n", current->kontainer.Date, front->kontainer.Date);
            // if(current->prev != NULL && front->next != NULL) {
            //     printf("-- current prev : %s -- current next : %s -- front prev : %s -- front next : %s\n", current->prev->kontainer.Date ,current->next->kontainer.Date, front->prev->kontainer.Date, front->next->kontainer.Date);
            // }else if (current->prev != NULL && front->next == NULL) {
            //     printf("-- current prev : %s -- current next : %s -- front prev : %s\n", current->prev->kontainer.Date ,current->next->kontainer.Date, front->prev->kontainer.Date);
            // }else if (current->prev == NULL && front->next != NULL) {
            //     printf("-- current next : %s -- front prev : %s -- front next : %s\n", current->next->kontainer.Date, front->prev->kontainer.Date, front->next->kontainer.Date);
            // }else {
            //     printf("-- current next : %s -- front prev : %s\n",current->next->kontainer.Date, front->prev->kontainer.Date);
            // }
            front = front->next;
        }
        
        current = current->next;
    }
}

void sortAscDesc(dataKontainer kontainer, list *L) {
    elemen *current, *front, *tempPtr, *tempEl1, *tempEl2, *tempNP, *tempPN;
    current = (elemen *)malloc(sizeof(elemen)); front = (elemen *)malloc(sizeof(elemen));
    tempPtr = (elemen *)malloc(sizeof(elemen));
    tempEl1 = (elemen *)malloc(sizeof(elemen)); tempEl2 = (elemen *)malloc(sizeof(elemen));
    tempNP = (elemen *)malloc(sizeof(elemen)); tempPN = (elemen *)malloc(sizeof(elemen));

    current = (*L).first;
    while (current->next != NULL) {
        front = current->next;
        while (front != NULL) {
            if (strcmp(current->kontainer.Desc, front->kontainer.Desc) > 0){
                if (current->next == front) {
                    if (current->prev == NULL){
                        (*L).first = front;
                    }
                    tempEl1 = current->next;
                    current->next = front->next;
                    if(current->next != NULL) {
                        current->next->prev = current;
                    }
                    if (current->prev != NULL) {
                        current->prev->next = front;
                    }
                    front->next = current;
                    tempEl2 = current->prev;
                    current->prev = front;
                    front->prev = tempEl2;

                    tempPtr = current;
                    current = front;
                    front = tempPtr;

                }else {
                    if (current->prev == NULL){
                        (*L).first = front;
                    }

                    current->next->prev = front;
                    front->prev->next = current;
                    if (front->next != NULL) {
                        front->next->prev = current;
                    }
                    if (current->prev != NULL) {
                        current->prev->next = front;
                    }

                    tempEl1 = current->next;
                    current->next = front->next;
                    front->next = tempEl1;

                    tempEl2 = front->prev;
                    front->prev = current->prev;
                    current->prev = tempEl2;

                    
                    tempPtr = current;
                    current = front;
                    front = tempPtr;
                }
            }
            front = front->next;
        }
        
        current = current->next;
    }
}
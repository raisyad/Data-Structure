// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Kuis 1 Soal 2 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// membuat list
void createList(list *L) { (*L).first = NULL; }

// menghitung banyaknya element
int countElement(list L) {
    int hasil = 0;
    if (L.first != NULL) {
        elemen *tunjuk;
        tunjuk = L.first;

        while (tunjuk != NULL) {
            hasil = hasil + 1;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(Pengusaha kontainer, list *L) {
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.Type, kontainer.Type);
    strcpy(baru->kontainer.Merk, kontainer.Merk);
    strcpy(baru->kontainer.Name, kontainer.Name);

    // jika list kosong
    if ((*L).first == NULL)
        baru->next = NULL;

    // jika bukan list kosong (ada isinya)
    else
        baru->next = (*L).first;

    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *prev, Pengusaha kontainer, list *L) {
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.Type, kontainer.Type);
    strcpy(baru->kontainer.Merk, kontainer.Merk);
    strcpy(baru->kontainer.Name, kontainer.Name);

    // jika ditambah pada elemen terakhir
    if (prev->next == NULL)
        baru->next = NULL;

    // jika ditambah pada elemen tengah atau yang ditentukan
    else
        baru->next = prev->next;
    
    prev->next = baru;
    baru = NULL;
}

void addLast(Pengusaha kontainer, list *L) {
    // jika list kosong
    if ((*L).first == NULL)
        addFirst(kontainer, L);
    // jika list tidak kosong
    else {
        elemen *prev = (*L).first;
        while (prev->next != NULL)
            prev = prev->next;
        
        addAfter(prev, kontainer, L);
    }
}

void printElement(list L) {
    if (L.first != NULL)
    {
        elemen *tunjuk = L.first;
        while (tunjuk != NULL)
        {
            printf("%s %s %s\n", tunjuk->kontainer.Type, tunjuk->kontainer.Merk, tunjuk->kontainer.Name);
            tunjuk = tunjuk->next;
        }
    }
}

void CateList(Pengusaha kontainer, list *L, list *action_1, list *sepatu_2, list *sepeda_3) {
    elemen *tunjuk = (*L).first, *prev;
    elemen *action, *sepatu, *sepeda;
    action = (elemen *)malloc(sizeof(elemen));
    sepatu = (elemen *)malloc(sizeof(elemen));
    sepeda = (elemen *)malloc(sizeof(elemen));

    action = NULL;
    sepatu = NULL;
    sepeda = NULL;

    while (tunjuk != NULL) {
        if (strcmp(tunjuk->kontainer.Type, "action_figure") == 0){
            if (action == NULL) {
                (*action_1).first = NULL;
                prev = tunjuk;
                tunjuk = tunjuk->next;
                prev->next = NULL;
                action = prev;
                (*action_1).first = action;
                prev = NULL;
            }else {
                prev = tunjuk;
                tunjuk = tunjuk->next;
                prev->next = (*action_1).first;
                (*action_1).first = prev;
                prev = NULL;
            }
        }else if (strcmp(tunjuk->kontainer.Type, "sepatu") == 0) {
            if(sepatu == NULL) {
                (*sepatu_2).first = NULL;
                prev = tunjuk;
                tunjuk = tunjuk->next;
                prev->next = NULL;
                sepatu = prev;
                (*sepatu_2).first = sepatu;
                prev = NULL;
            }else {
                prev = tunjuk;
                tunjuk = tunjuk->next;
                prev->next = (*sepatu_2).first;
                (*sepatu_2).first = prev;
                prev = NULL;
            }
        }else if (strcmp(tunjuk->kontainer.Type, "sepeda") == 0) {
            if(sepeda == NULL) {
                (*sepeda_3).first = NULL;
                prev = tunjuk;
                tunjuk = tunjuk->next;
                prev->next = NULL;
                sepeda = prev;
                (*sepeda_3).first = sepeda;
                prev = NULL;
            }else {
                prev = tunjuk;
                tunjuk = tunjuk->next;
                prev->next = (*sepeda_3).first;
                (*sepeda_3).first = prev;
                prev = NULL;
            }
        }
    }
    if((*L).first != NULL) {
        (*L).first = NULL;
    }

    printElement((*action_1));
    printElement((*sepatu_2));
    printElement((*sepeda_3));

}
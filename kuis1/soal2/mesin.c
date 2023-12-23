// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Kuis 1 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// membuat list
void createList(list *L)
{
    (*L).first = NULL;
}

// menghitung banyaknya element
int countElement(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        elemen *tunjuk;
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            hasil = hasil + 1;
            tunjuk = tunjuk->next;
        }
    }

    return hasil;
}

void addFirst(char name[], char JK[], char bookFrom[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.JK, JK);
    strcpy(baru->kontainer.bookFrom, bookFrom);

    // jika list kosong
    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    // jika bukan list kosong (ada isinya)
    else
    {
        baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *prev, char name[], char JK[], char bookFrom[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.JK, JK);
    strcpy(baru->kontainer.bookFrom, bookFrom);

    // jika ditambah pada elemen terakhir
    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    // jika ditambah pada elemen tengah atau yang ditentukan
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addLast(char name[], char JK[], char bookFrom[], list *L)
{
    // jika list kosong
    if ((*L).first == NULL)
    {
        addFirst(name, JK, bookFrom, L);
    }
    // jika list tidak kosong
    else
    {
        elemen *prev = (*L).first;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        addAfter(prev, name, JK, bookFrom, L);
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        elemen *tunjuk = L.first;
        while (tunjuk != NULL)
        {
            printf("%s - ", tunjuk->kontainer.name);
            printf("%s - ", tunjuk->kontainer.JK);
            printf("%s\n", tunjuk->kontainer.bookFrom);
            tunjuk = tunjuk->next;
        }
    }
}
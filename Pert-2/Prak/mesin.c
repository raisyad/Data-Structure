// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LTD22C2) dalam mata kuliah Struktur Data
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

void delFirst(list *L)
{
    if ((*L).first != NULL) // JIKA BUKAN LIST KOSONG
    {
        elemen *hapus = (*L).first;
        // jika hanya ada satu elemen
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }
        // jika lebih dari satu elemen
        else
        {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
    else
    {
        printf("kosong");
    }
}

void delAfter(elemen *prev, list *L)
{
    elemen *hapus = prev->next;
    if (hapus != NULL)
    {
        // menghapus elemen terakhir
        if (hapus->next == NULL)
        {
            prev->next = NULL;
        }
        // menghapus elemen tengah atau yang ditentukan (bukan akhir)
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        // jika hanya ada satu elemen
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        // jika ada lebih dari satu elemen
        else
        {
            elemen *last = (*L).first;
            elemen *prev;

            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
        for (int i = 0; i < countElement(*L); i++)
            delLast(L); // menghapus dari elemen terakhir
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
    else
    {
        printf("List Kosong.\n");
    }
}
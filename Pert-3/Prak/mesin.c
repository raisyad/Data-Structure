// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGS22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

void createList(list *L)
{
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        // Inisialisasi isi array elemen.
        (*L).data[i].next = -2;
        (*L).data[i].prev = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        /* list tidak kosong */
        int hitung;
        /* inisialisasi */
        hitung = L.first;
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

void addFirst(char name[], char date[], char sum[], list *L)
{

    if (countElement(*L) < 10)
    {
        // Bikin list baru
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.name, name);
        strcpy((*L).data[baru].kontainer.date, date);
        strcpy((*L).data[baru].kontainer.sum, sum);

        // Cari data first yang memiliki NULL
        if ((*L).first == -1)
        {
            /*jika list kosong, pasangkan list baru dengan NULL*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else
        {
            /*jika list tidak kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }

        // Rubah first dengan baru
        (*L).first = baru;
    }
    else
    {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char name[], char date[], char sum[], list *L)
{
    if (before != -1)
    {
        if (countElement(*L) < 10)
        {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.name, name);
            strcpy((*L).data[baru].kontainer.date, date);
            strcpy((*L).data[baru].kontainer.sum, sum);

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
                (*L).tail = baru;
            }
        }
        else
        {
            /*proses jika array penuh*/
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

void addLast(char name[], char date[], char sum[], list *L)
{
    if ((*L).first == -1)
    {
        /*proses jika list masih kosong*/
        addFirst(name, date, sum, L);
    }
    else
    {
        /*proses jika list telah berisi elemen*/
        addAfter((*L).tail, name, date, sum, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = -1;
            (*L).tail = -1;
        }
        else
        {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        /*elemen awal sebelumnya dikosongkan*/
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

void delAfter(int before, list *L)
{
    int hapus = (*L).data[before].next;

    if (before != -1)
    {
        if (hapus != -1)
        {
            if ((*L).data[hapus].next == -1)
            {
                (*L).tail = before;
                (*L).data[before].next = -1;
            }
            else
            {
                (*L).data[before].next = (*L).data[hapus].next;
                (*L).data[(*L).data[hapus].next].prev = before;
            }
            /*pengosongan elemen*/
            (*L).data[hapus].prev = -2;
            (*L).data[hapus].next = -2;
        }
    }
}

void delLast(list *L)
{

    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            /*proses jika list hanya berisi satu elemen*/
            delFirst(L);
        }
        else
        {
            /*elemen sebelum elemen terakhir menjadi elemen terakhir*/
            delAfter((*L).data[(*L).tail].prev, L);
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

void printElement(list L)
{
    if (L.first != -1)
    {
        /*inisialisasi*/
        int bantu = L.first;
        int i = 1;
        while (bantu != -1)
        {
            /*proses*/

            printf("%s ", L.data[bantu].kontainer.date);
            printf("%s ", L.data[bantu].kontainer.name);

            /*iterasi*/
            bantu = L.data[bantu].next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika listkosong*/
        printf("List Kosong.\n");
    }
}


void printReverse(list L)
{
    if (L.tail != -1)
    {
        /*inisialisasi*/
        int bantu = L.tail;
        int i = 1;
        while (bantu != -1)
        {
            /*proses*/

            printf("%s ", L.data[bantu].kontainer.date);
            printf("%s ", L.data[bantu].kontainer.name);
            printf("%s\n", L.data[bantu].kontainer.sum);
            // printf("next : %d\n", L.data[bantu].next);

            /*iterasi*/
            bantu = L.data[bantu].prev;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika listkosong*/
        printf("List Kosong.\n");
    }
}
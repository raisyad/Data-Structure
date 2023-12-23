#include "header.h"

// prosedur untuk membuat dynamic list
void createList(list *L)
{
    (*L).first = NULL;
}

// fungsi untuk menghitung elemen dalam list
int countEl(list L)
{
    // inisialisasi untuk tampungan jumlah elemen di list
    int sum = 0;
    if (L.first != NULL)
    {
        elemen *ptr;   // deklarasi pointer
        ptr = L.first; // pointer menunjuk elemen di pointer first
        while (ptr != NULL)
        {
            sum++;
            ptr = ptr->next; // pointer mengarahkan pada elemen selanjutnya melalui pointer next
        }
    }
    return sum; // mengembalikan nilai
}

// prosedur untuk melakukan penambahan data di depan
void addFirst(isiKontainer kontainer, list *L)
{
    elemen *newPtr; // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen));
    // copy data
    strcpy(newPtr->kontainer.nim, kontainer.nim);
    strcpy(newPtr->kontainer.nama, kontainer.nama);
    strcpy(newPtr->kontainer.nilai, kontainer.nilai);

    if ((*L).first == NULL) // kondisi ketika list kosong
        newPtr->next = NULL;
    else // kondisi ketika ada elemen dalam list
        newPtr->next = (*L).first;

    (*L).first = newPtr; // pointer first menunjuk pada elemen baru
    newPtr = NULL;       // pointer baru di NULL kan
}

// prosedur untuk melakukan penambahan data setelah elemen tertentu
void addAfter(elemen *prev, isiKontainer kontainer, list *L)
{
    elemen *newPtr; // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen));
    // copy data
    strcpy(newPtr->kontainer.nim, kontainer.nim);
    strcpy(newPtr->kontainer.nama, kontainer.nama);
    strcpy(newPtr->kontainer.nilai, kontainer.nilai);

    if (prev->next == NULL) // kondisi ketika menambahkan elemen baru sebagai elemen terakhir
        newPtr->next = NULL;
    else // kondisi ketika menambahkan elemen baru sebagai elemen pada index tertentu
        newPtr->next = prev->next;

    prev->next = newPtr; // pointer prev.next menunjuk pada elemen baru
    newPtr = NULL;       // pointer baru di NULL kan
}

// prosedur untuk menambahkan data sebagai elemen terakhir
void addLast(isiKontainer kontainer, list *L)
{
    if ((*L).first == NULL) // kondisi jika list kosong
        addFirst(kontainer, L);
    else // jika ada elemen dalam list
    {
        elemen *prev = (*L).first;    // pointer prev menunjuk pada elemen yang ditunjuk oleh pointer first
        while (prev->next != NULL)    // mencari elemen terakhir
            prev = prev->next;        // iterasi
        addAfter(prev, kontainer, L); // menjalankan prosedur addAfter kondisi 1
    }
}

// prosedur untuk menghapus data pada elemen pertama
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *delPtr = (*L).first; // pointer hapus menunjuk pada elemen yang ditunjuk oleh pointer first
        // jika elemen dalam list hanya 1
        if (countEl(*L) == 1)
            (*L).first = NULL; // pointer first di NULL kan
        else                   // jika elemen dalam list > 1
        {
            (*L).first = (*L).first->next; // pointer first menunjuk pada elemen yang ditunjuk oleh pointer first.next
            delPtr->next = NULL;           // pointer hapus.next di NULL kan
        }
        free(delPtr); // free memory
    }
}

// prosedur untuk menghapus data setelah elemen tertentu
void delAfter(elemen *prev, list *L)
{
    elemen *delPtr = prev->next; // menginisialisasi pointer hapus pada elemen yang ditunjuk pointer prev.next
    if (delPtr != NULL)
    {
        // kondisi jika yang dihapus merupakan elemen terakhir
        if (delPtr->next == NULL)
            prev->next = NULL; // pointer prev.next di NULL kan
        else                   // kondisi jika elemen yang dihapus ada di tengah
        {
            prev->next = delPtr->next; // pointer prev.next menunjuk pada elemen yang ditunjuk oleh pointer hapus.next
            delPtr->next = NULL;       // pointer hapus.next di NULL kan
        }
        free(delPtr); // free memory
    }
}

// prosedur untuk menghapus data yang ada di elemen terakhir
void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        // jika elemen hanya ada 1
        if (countEl(*L) == 1)
            delFirst(L); // menjalankan prosedur delFirst kondisi 1
        else
        {
            elemen *delPtr = (*L).first; // inisialisasi pointer hapus pada elemen yang ditunjuk oleh pointer first
            elemen *prev;                // deklarasi pointer prev
            while (delPtr->next != NULL) // mencari elemen terakhir
            {
                prev = delPtr;         // pointer prev akan menempati elemen yang ditunjuk oleh pointer hapus
                delPtr = delPtr->next; // pointer hapus menunjuk pada elemen yang ditunjuk oleh pointer hapus.next
            }
            delAfter(prev, L);
        }
    }
}

void printEl(list L)
{
    if (L.first != NULL)
    {
        elemen *ptr = L.first;
        int i = 1;
        while (ptr != NULL)
        {
            printf("%s %s %s\n", ptr->kontainer.nim, ptr->kontainer.nama, ptr->kontainer.nilai);
            ptr = ptr->next;
            i++;
        }
    }
    else
        printf("List Kosong.\n");
}

void delAll(list *L)
{
    if (countEl(*L) != 0)
        for (int i = 0; i < countEl(*L); i++)
            delLast(L); // menghapus dari elemen terakhir
}
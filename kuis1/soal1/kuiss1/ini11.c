// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Mesin (LGS22C2) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include<stdio.h>
#include<string.h>

typedef struct {
  char kodegen[101];
  char kodeortu[101];
}Animals;

typedef struct {
  Animals kontainer;
  int next;
  int prev;
}elemen;

typedef struct {
  int first;
  int tail;
  elemen data[10];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char kodegen[], char kodeortu[], list *L);
void addAfter (int before, char kodegen[], char kodeortu[], list *L);
void addLast(char kodegen[], char kodeortu[], list *L);
void printElement(list L);
void tukar(list *L1, list *L2, int p);


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

    if (countElement(L) < 100)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 100))
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

void addFirst(char kodegen[], char kodeortu[], list *L)
{

    if (countElement(*L) < 100)
    {
        // Bikin list baru
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.kodegen, kodegen);
        strcpy((*L).data[baru].kontainer.kodeortu, kodeortu);

        // Cari data first yang memiliki NULL
        if ((*L).first == -1)
        {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else
        {
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }

        // Rubah first dengan baru
        (*L).first = baru;
    }
}

void addAfter(int before, char kodegen[], char kodeortu[], list *L)
{
    if (before != -1)
    {
        if (countElement(*L) < 100)
        {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.kodegen, kodegen);
            strcpy((*L).data[baru].kontainer.kodeortu, kodeortu);

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
    }
}

void addLast(char kodegen[], char kodeortu[], list *L)
{
    if ((*L).first == -1)
    {
        addFirst(kodegen, kodeortu, L);
    }
    else
    {
        addAfter((*L).tail, kodegen, kodeortu, L);
    }
}


void printElement(list L)
{
    if (L.first != -1)
    {
        int bantu = L.first;
        int i = 1;
        while (bantu != -1)
        {

            printf("%s ", L.data[bantu].kontainer.kodegen);
            printf("%s\n", L.data[bantu].kontainer.kodeortu);

            bantu = L.data[bantu].next;
            i = i + 1;
        }
    }
}

void tukar(list *L1, list *L2, int p)
{
    int ptr1 = (*L1).first;
    int ptr2 = (*L2).first;
    int ptr3 = (*L1).tail;
    int ptr4 = (*L2).tail;
    Animals temp;
    Animals temp2;

    for (int i = 0; i < p; i++) {

        temp = (*L1).data[ptr1].kontainer;
        (*L1).data[ptr1].kontainer = (*L2).data[ptr2].kontainer;
        (*L2).data[ptr2].kontainer = temp;

        temp2 = (*L1).data[ptr3].kontainer;
        (*L1).data[ptr3].kontainer = (*L2).data[ptr4].kontainer;
        (*L2).data[ptr4].kontainer = temp2;

        ptr1 = (*L1).data[ptr1].next;
        ptr2 = (*L2).data[ptr2].next;

        ptr3 = (*L1).data[ptr3].prev;
        ptr4 = (*L2).data[ptr4].prev;
    }
    printElement((*L1));
    printElement((*L2));
}


int main(void) {
  list L1;
  list L2;
  Animals InputOfData;;
  int n,p;
  createList(&L1);
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%s %s", &InputOfData.kodegen, &InputOfData.kodeortu);
    addLast(InputOfData.kodegen, InputOfData.kodeortu, &L1);
  }
  createList(&L2);
  for (int i = 0; i < n; i++) {
    scanf ("%s %s", &InputOfData.kodegen, &InputOfData.kodeortu);
    addLast(InputOfData.kodegen, InputOfData.kodeortu, &L2);
  }
  scanf ("%d", &p);
  tukar(&L1,&L2,p);
  // printElement(L1);
}
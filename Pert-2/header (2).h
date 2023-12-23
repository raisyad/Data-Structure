#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[100], nama[100], nilai[2];
} isiKontainer;

typedef struct elmt *elAdd;

typedef struct elmt
{
    isiKontainer kontainer;
    elAdd next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countEl(list L);
void addFirst(isiKontainer kontainer, list *L);
void addAfter(elemen *prev, isiKontainer kontainer, list *L);
void addLast(isiKontainer kontainer, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printEl(list L);
void delAll(list *L);
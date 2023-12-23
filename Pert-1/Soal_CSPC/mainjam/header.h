#include<stdio.h>
#include<string.h>

typedef struct {
    int jam;
    int menit;
    int detik;
    int markSec;
}valueOf;

typedef struct {
    valueOf container;
    int next;
}element;

typedef struct {
    int first;
    element data[100];
}list;

void createList(list *L, int n);
int countElement(list L);
int emptyElement(list L, int n);
void addFirst(int jam, int menit, int detik, list *L, int n);
void printElement(list L);
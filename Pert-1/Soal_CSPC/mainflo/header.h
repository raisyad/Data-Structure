#include<stdio.h>

typedef struct {
    double nilai;
    int mark;
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
void addFirst(double nilai, list *L, int n);
void printElement(list L);
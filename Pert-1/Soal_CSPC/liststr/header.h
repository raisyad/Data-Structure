#include<stdio.h>
#include<string.h>

typedef struct {
    char name[101];
}valueOf;

typedef struct {
    valueOf container;
    int next;
}element;

typedef struct {
    int first;
    element data[101];
}list;

void createList(list *L, int n);
int countElement(list L);
int emptyElement(list L, int n);
void addFirst(char* name, list *L, int n);
void printElement(list L);
#include<stdio.h>
#include<string.h>

typedef struct {
    char* name;
}valueOf;

typedef struct {
    valueOf container;
    int next;
}element;

typedef struct {
    int first;
    element* data;
}list;

void createList(list *L, int n);
int countElement(list L);
int emptyElement(list L, int n);
void addFirst(char* name, list *L, int n);
void printElement(list L);
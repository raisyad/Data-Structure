#include<stdio.h>
#include<string.h>

typedef struct {
    char name[101];
    int iterator;
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
void addAfter(int prev, char* name, list *L, int n);
void addLast(char* name, list *L, int n);
void delAfter(int prev, list *L);
void printElement(list L, int n);
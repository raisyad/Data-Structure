#include "header.h"

int main(void) {
    graph G;
    createEmpty(&G);

    char awal;
    char akhir;

    int direct = 0;
    int undirect = 0;
    int jalan = 0;

    simpul *begin = NULL;
    simpul *end = NULL;
    simpul *cek = NULL;
    simpul *awalLoc = NULL;
    simpul *tujuan = NULL;

    int n, i;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf(" %c %c", &awal, &akhir);

        cek = findSimpul(awal, G);
        if(cek == NULL)
        {
            addSimpul(awal, &G);
        }

        cek = findSimpul(akhir, G);
        if(cek == NULL)
        {
            addSimpul(akhir, &G);
        }

        begin = findSimpul(awal, G);
        end = findSimpul(akhir, G);
        addJalur(begin, end);
    }
    scanf(" %c %c", &awal, &akhir);
    awalLoc = findSimpul(awal, G);
    tujuan = findSimpul(akhir, G);
    // printGraph(G);
    

    findJalur(awalLoc, tujuan, &direct, &undirect, &jalan);
    printf("Directed:\n");
    printf("%d\n\n", direct);
    printf("Undirected:\n");
    printf("%d\n", undirect);

}
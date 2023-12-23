// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM7 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main()
{
    queue Q;
    createQueue(&Q);
    isiKontainer data;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %s %d", data.nama, &data.prioritas, data.daerah, &data.nominal);
        pushPriority(data, &Q);
    }
    int m;
    scanf("%d", &m);
    printf("Bantuan Tersalurkan:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%s %d %s %d\n", Q.data[Q.first].nama, Q.data[Q.first].prioritas, Q.data[Q.first].daerah, Q.data[Q.first].nominal);
        pop(&Q);
    }
    printf("\nAntrian berisi:\n");
    printQueue(Q);
    return 0;
}

/*

input--

3
13507701 Nana 64.75
13507702 Rudi 75.11
13507703 Dea 84.63

*/
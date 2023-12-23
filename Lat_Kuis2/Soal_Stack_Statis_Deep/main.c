#include "header.h"

int main()
{
    int n;
    scanf("%d", &n);
    stack rillcuy[n];               // deklarasi stack asal
    stack pindahcuy[n];             //deklarasi stack tampungan
    isiKontainer data1;            // membuat tampungan data masukan
    
    for(int i = 0; i < n; i++)
    {
        createStack(&rillcuy[i]);       // membuat stack kosong
        createStack(&pindahcuy[i]);       // membuat stack kosong
    }

    int apa;
    for(int z = 0; z < n; z++)
    {
        scanf("%d", &apa);
        do
        {
            scanf("%s", &data1.label_nama);
            if(strcmp(data1.label_nama, "0") != 0)
            {
                scanf("%s", &data1.label_nim);
                data1.tanda = 0;
                push(data1, &rillcuy[z]);
            }
        } while (strcmp(data1.label_nama, "0") != 0); 
    }

    int alhamdulillah;
    char pilih[100];
    scanf("%d", &alhamdulillah);
    for(int i = 0; i < alhamdulillah; i++)
    {
        scanf("%s", &pilih);
        for(int p = 0; p < n; p++)
        {
            tanda(&rillcuy[p], pilih);
        }
    }

    for(int p = 0; p < n; p++)
    {
        ambil(&rillcuy[p], &pindahcuy[p]);
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("stack %d\n", i+1);
        printStack(rillcuy[i]);
        printf("\n");
    }

    for(int i = n-1; i >= 0; i--)
    {
        printf("batas stack %d\n", i+1);
        printStack(pindahcuy[i]);
        printf("\n");
    }
    
    return 0;
}
#include "header.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addSimpul(char c, graph *G)
{

    simpul *baru;
    baru = (simpul *) malloc (sizeof(simpul));

    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;
    baru->visit = 0;

    if((*G).first == NULL)
    {
        /*jika graf kosong*/
        (*G).first = baru;
    }
    else
    {
        
        /*menambahkan simpul baru pada akhir
        graph*/
        simpul *last = (*G).first;
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan)
{

    jalur *baru;
    baru = (jalur *) malloc (sizeof (jalur));

    baru->next_jalur = NULL;
    baru->tujuan = tujuan;

    if(awal->arc == NULL)
    {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else
    {
        /*menambahkan jalur baru pada akhir list
        jalur*/
        jalur *last = awal->arc;
        while(last->next_jalur != NULL)
        {
            last = last->next_jalur;
        }
        last->next_jalur = baru;
    }
}

simpul* findSimpul(char c, graph G)
{

    simpul *hasil = NULL;
    simpul *bantu = G.first;
    int ketemu = 0;

    while((bantu != NULL) && (ketemu == 0))
    {

        if(bantu->kontainer == c)
        {
            hasil = bantu;
            ketemu = 1;
        }
        else
        {
            bantu = bantu->next;
        }
    }
    return hasil;
}

void printGraph(graph G)
{

    simpul *bantu = G.first;
    if(bantu != NULL)
    {
        while(bantu != NULL)
        {

            printf("Node %c\n", bantu->kontainer);
            jalur *bantu_jalur = bantu->arc;

            while(bantu_jalur != NULL)
            {
                printf("- Jalur %c ke %c\n", bantu->kontainer, bantu_jalur->tujuan->kontainer);
                bantu_jalur = bantu_jalur->next_jalur;
            }
            bantu = bantu->next;
        }
    }
    else
    {
        printf("graf kosong\n");
    }
}

void findJalur(simpul *awal, simpul *tujuan, int *direct, int *undirect, int *jalan)
{
    awal->visit = 1;

    if(awal->kontainer == tujuan->kontainer)
    {
        if(*jalan == 1)
        {
            *direct = *direct + 1;
        }
        else
        {
            *undirect = *undirect + 1;
        }
    }
    else
    {
        jalur *bantu = awal->arc;
        while(bantu != NULL)
        {
            *jalan = *jalan + 1;
            if(bantu->tujuan->visit != 1)
            {
                findJalur(bantu->tujuan, tujuan, direct, undirect, jalan);
            }
            *jalan = *jalan - 1;
            bantu = bantu->next_jalur;
        }
    }
    awal->visit = 0;
}

// void findJalur(simpul *awal, simpul *tujuan, int *idx, int *sumBobot, char temp[])
// {
//     int flag = 0;
//     temp[*idx] = awal->kontainer;
//     *idx = *idx + 1;

//     if(awal->kontainer == tujuan->kontainer)
//     {
//         for(int i = 0; i < *idx; i++)
//         {
//             printf("%c ", temp[i]);
//         }
//         printf("%d", *sumBobot);
//         printf("\n");
//     }
//     else
//     {
//         jalur *bantu = awal->arc;
//         if(bantu != NULL)
//         {
//            while(flag != 1)
//             {
//                 *sumBobot = *sumBobot + bantu->kontainer_jalur;
//                 findJalur(bantu->tujuan, tujuan, idx, sumBobot, temp);
//                 *sumBobot = *sumBobot - bantu->kontainer_jalur;
//                 if(bantu->next_jalur != NULL)
//                 {
//                     bantu = bantu->next_jalur;
//                 }
//                 else
//                 {
//                     flag = 1;
//                 }
//             } 
//         }
//     }

//     *idx = *idx - 1;
// }
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP3 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    stack s, rock, pop;    // deklarasi stack
    createStack(&s);       // membuat stack kosong
    createStack(&rock);    // membuat stack kosong
    createStack(&pop);     // membuat stack kosong
    isiKontainer music;    // membuat tampungan data masukan

    int n;                 // Deklarasi n
    scanf ("%d", &n);      // input banyak inputan n
    while(n--) {           // Input data sebanyak n
        scanf ("%s %s %s", &music.YearMusicRilis, &music.TitleMusic, &music.NameBand);
        push(music, &s);   // mempush/memasukkan data kedalam stack
    }
    Classification(&s, &rock, &pop); //Mengklasifikasikan data rock atau pop
    // Print data Rock dan Pop
    printf ("Playlist Musik Rock:\n");
    printf ("===================\n");
    printStackRock(rock);
    printf ("\nPlaylist Musik Pop:\n");
    printf ("===================\n");
    printStackPop(pop);
}
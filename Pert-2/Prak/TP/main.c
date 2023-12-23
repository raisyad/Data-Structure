// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Praktikum TP1 (KBT22) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    list L; //membuat bungkusan list
    createList(&L); //membuat list data
    char Judul, Production, ratingFilm, SortedData[201], methods[201]; //pembuatan type data dengan namanya
    int marked = 0; //berfungsi untuk menandai jika inputan judul merupakan '-' atau tidak
    filmGeber Film; //membuat bungkusan film
    while(marked != 1){ //perulangan forever ketika penanda belum berubah menjadi 1
        scanf(" %s", Film.Judul); //inputan data judul
        if (strcmp(Film.Judul, "-") == 0) marked = 1; //jika inputan judul tadi merupakan '-' maka penanda berubah menjadi true
        if (marked != 1) { //ketika penanda masih false
        // lakukan inputan selanjutnya yaitu produksiFilm dan ratingnya serta lakukan addfirst
            scanf ("%s %s", &Film.Production, &Film.ratingFilm);
            addFirst(Film.Judul, Film.Production, Film.ratingFilm, &L);
        }
    }
    // inputan pengurutanData yang dituju dan metodenya
    scanf("%s", &SortedData);
    scanf("%s", &methods);
    SortingDatas(&L,SortedData,methods,Film); //memanggil prosedur sorting
    PrintOutElement(L); //memanggil prosedur print
}
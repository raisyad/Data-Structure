// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Kuis 1 Soal 2 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    list Lutama;
    list acf;
    list sepatu;
    list sepeda;
    createList(&Lutama);
    createList(&acf);
    createList(&sepatu);
    createList(&sepeda);
    Pengusaha kontainer;
    int n;
    
    // List Utama
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%s %s %s", &kontainer.Type, &kontainer.Merk, &kontainer.Name);
        addLast(kontainer, &Lutama);    
    }
    CateList(kontainer,&Lutama,&acf,&sepatu,&sepeda);
}
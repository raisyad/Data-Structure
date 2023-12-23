// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal kuis2 stgro22 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    stack firstIns, CompareStack;      // deklarasi Stack Awal inputan/asal dan Stack untuk mengcompare
    createStack(&firstIns);            // Membuat stack kosong untuk stack first atau awal
    createStack(&CompareStack);        // Membuat stack kosong untuk stack yang akan dicompare nantinya
    isiKontainer input;            // membuat tampungan data masukan

    int n, CountFiltered;   // Deklar variable n inputan dan jumlah yang akan di filter
    scanf("%d", &n); //inputan n
    stack filtered[n]; //Deklar stack final, atau stack yang akan diisi oleh data yang telah difilter nanti
    for (int i = 0; i < n; i++){ //Inputan untuk stack awal atau asal
        scanf ("%s %s %s %d", &input.NamePemilik, &input.EkspedisiPaket, &input.DomainPaket, &input.beratPaket);
        push(input, &firstIns);
    }
    scanf("%d", &CountFiltered); //inputan banyaknya data yang akan difilter
    for (int i = 0; i < CountFiltered; i++){ //inputan untuk stack yang akan dicompare
        scanf ("%s", &input.CompareEkspedisi);
        push(input, &CompareStack);
        createStack(&filtered[i]); //Membuat stack kosong untuk stack filter 
    }

    // Jika stack awal tidak kosong
    if ((firstIns).top != -1)
        // Perulangan sebanyak stack yang ada di stack awal
        for (int z = (firstIns).top; z >= 0; z--) 
            // Perulangan sebanyak stack yang ada di stack compare
            for (int i = CompareStack.top; i >= 0; i--)
                // Membandingkan ketika ada data ekspedisi yang sama, maka
                if (strcmp(CompareStack.data[i].CompareEkspedisi, (firstIns).data[z].EkspedisiPaket) == 0) 
                    popPush(&firstIns, &filtered[i]); //Lakukan pemindahan elemen

    // Perulangan untuk menampilkan output
    for (int i = 0; i < CountFiltered; i++) {
        printf("stack %s:\n", CompareStack.data[i].CompareEkspedisi);
        StackFinal(filtered[i]);
        if (i != CountFiltered-1)
            printf("\n");
    }
}
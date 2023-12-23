// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TM dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    isiKontainer data, data2;
    char awal[300], tujuan[300], kotaAsal[300], JalurTo[300];
    int n, m, k, bobot, get = 0, finded = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        graph G;
        createEmpty(&G);
        get = 0;
        scanf ("%d", &m);
        for (int z = 0; z < m; z++) {
            scanf ("%s", &kotaAsal);
            findSimpul(kotaAsal, G, &finded);
            if (finded == 0) {
                addSimpul(kotaAsal, &G);
            }
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf ("%s", &JalurTo);
                findSimpul(JalurTo, G, &finded);
                if (finded == 0) {
                    addSimpul(JalurTo, &G);
                }
                scanf ("%d", &bobot);
                simpul *begin = findSimpul(kotaAsal, G, &finded);
                // finded = 0;
                simpul *end = findSimpul(JalurTo, G, &finded);
                if ((begin != NULL) && (end != NULL)) {
                    addJalur(begin, end, bobot);
                }
            }
        }
        scanf ("%s %s", awal, tujuan);
        carijalur(G.first, awal, &get, tujuan, &bobot);
    }
}
#include "bismillah.h"


int main(){
  list L;
  createListbaris(&L);
  int n; // -> n banyak nya data yang ingin diinputkan
  scanf("%d", &n);
  databaris Resto,  restoA, restoB;
  datakolom masukanMenu;
  eBaris* asoy;
  char menuSwitch1[100];
  char menuSwitch2[100];

   char startSwitch[20]; // penanda start dan switch

    for(int i = 0; i < n; i++) {
        scanf("%s", startSwitch); // penanda start
        if(strcmp(startSwitch, "start") == 0) {
            // jika penanda berisi start
            scanf("%s", Resto.nama); // masukan data restoran (baris)
            addLastbaris(Resto, &L); // memasukan data sebagai elemen terakhir
            // jika masukan pertama maka alamatnya menunjuk ke baris pertama
            // jika bukan masukan pertama maka digeser ke kanan
            // eBaris* baris = i == 0 ? L.first : baris->next; // alamat baris saat ini meki-meki semkdown
            if(i == 0)
            {
              asoy=L.first;
            }
            else
            {
              asoy= asoy->next;
            }
            do {
                scanf("%s", masukanMenu.menu); // masukan nama menu
                if(strcmp(masukanMenu.menu, "end") != 0) {
                    // jika nama menu tidak berisi "end"
                    scanf("%d", &masukanMenu.harga); // masukan harga menu
                    addLastkolom(masukanMenu, asoy); // memasukan data menu sebagai elemen kolom terakhir
                }
                // diulang selama nama menu bukan "end"
            }while(strcmp(masukanMenu.menu, "end") != 0);
        }
    }
    
    scanf("%s", startSwitch); // penanda switch

    // kondisi kalo nuker beneran nuker trus ditaro di akhir
    do {
        scanf("%s", restoA.nama); // masukan data resto asal (resto A atau resto Kiri)
        if(strcmp(restoA.nama, "end") != 0) {
            // jika resto asal tidak berisi "end"
            scanf("%s %s %s",menuSwitch1, restoB.nama, menuSwitch2); // masukan menu yang ingin ditukar dan resto tujuan
            tukarLast(restoA.nama, restoB.nama, menuSwitch1, &L); // tukar menu dari resto asal ke tujuan
            tukarLast(restoB.nama, restoA.nama, menuSwitch2, &L); // tukar menu dari resto asal ke tujuan
        }
        // diulang selama resto asal bukan "end"
    } while(strcmp(restoA.nama, "end") != 0);
    // kondisi kalo cuman mindahin doang noted : tidak ada menuswitch2

    // do {
    //     scanf("%s", restoA.nama); // masukan data resto asal (resto A atau resto Kiri)
    //     if(strcmp(restoA.nama, "end") != 0) {
    //         // jika resto asal tidak berisi "end"
    //         scanf(" %s %s",menuSwitch1, restoB.nama); // masukan menu yang ingin ditukar dan resto tujuan
    //         tukarLast(restoA.nama, restoB.nama, menuSwitch1, &L); // tukar menu dari resto asal ke tujuan
    //     }
    //     // diulang selama resto asal bukan "end"
    // } while(strcmp(restoA.nama, "end") != 0);
    
    sorting(&L);
    // sortingkolomall(&L);
    printElement(L);
}

/*
2
start
cradiax_kitchen
bakso 15000 
pentol 10000
end
start 
aceng_kitchen
nasigoreng 10000
puding 20000
end
asoy 
cradiax_kitchen 
bakso aceng_kitchen
aceng_kitchen
nasigoreng cradiax_kitchen
end
*/
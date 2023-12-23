// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP5 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

int main(void) {
    graph G; // Inisialisasi
    createEmpty(&G); // Create Graph Kosong
    char pointA[MAX], pointB[MAX], SimAwal[MAX], SimTuj[MAX], temp[MAX]; // Declare  Var char
    int n, bobot, ketemu = 0; // Declar Var Int
    scanf ("%d", &n); // Inputan N

    for (int i = 0; i < n; i++) {
        scanf ("%s %s %d", &SimAwal, &SimTuj, &bobot); // Input Lokasi Awal, destinasi dan bobotnya
        findSimpul(SimAwal, G, &ketemu); // Cari SimpulAwal, kalo belum ada, maka add simpul
        if (ketemu == 0) {
            addSimpul(SimAwal, &G);
        }
        findSimpul(SimTuj, G, &ketemu); // Cari SimpulTujuan, kalo belum ada, maka add simpul
        if (ketemu == 0) {
            addSimpul(SimTuj, &G);
        }

        // Cari Loc Awal dan Tujuan tadi, jika sudah ada, Tambahkan Jalur
        simpul *LocAwal = findSimpul(SimAwal, G, &ketemu);
        simpul *LocTujuan = findSimpul(SimTuj, G, &ketemu);
        if ((LocAwal != NULL) && (LocTujuan != NULL)) {
            addJalur(LocAwal, LocTujuan, bobot);
        }

        if (i == n - 1){ // Jika perulangan merupakan perulangan terakhir, input LokasiAwal dan Tujuan yang akan diexplore
            scanf ("%s %s", &pointA, &pointB);
            simpul *start = findSimpul(pointA, G, &ketemu); // Explore dari titik Lokasi Awal
            TrackingMap(start, pointA, pointB, temp, 0, 0); // Proses Explore
        }
    }
}
// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal Tes Praktikum TP1 (KBT22) dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// membuat list
void createList(list *L) { (*L).first = NULL; } //insialisasi bahwa belum ada data yang diisikan // pembuatan list

void addFirst(char Judul[201], char Production[201], char ratingFilm[201], list *L) {
    elemen *baru; //membuat pointer bungkusan baru
    baru = (elemen *)malloc(sizeof(elemen)); //lalu baru diinisialisasi

    // dibawah ini merupakan proses pengisian data
    strcpy(baru->kontainer.Judul, Judul);
    strcpy(baru->kontainer.Production, Production);
    strcpy(baru->kontainer.ratingFilm, ratingFilm);

    // jika list kosong
    if ((*L).first == NULL) baru->next = NULL;
    // jika bukan list kosong (ada isinya)
    else baru->next = (*L).first;

    (*L).first = baru;
    baru = NULL;
}

void SortingDatas(list *L, char SortedData[201], char methods[201], filmGeber kontainer) {
    if ((*L).first != NULL) { //Jika list tidak kosong
        elemen *tunjuk, *null, *temps, *prev, *current, *prevEl, *tempsV; //inisialisasi
        tunjuk = (elemen *)malloc(sizeof(elemen)); null = (elemen *)malloc(sizeof(elemen));
        prevEl = (elemen *)malloc(sizeof(elemen));
        prev = (elemen *)malloc(sizeof(elemen));
        current = (elemen *)malloc(sizeof(elemen));
        // tunjuk = (*L).first;
        // prev = (*L).first;
        int mark = 0, loop, res;

        if (strcmp(SortedData, "judul") == 0) { //jika data pengurutan memilih judul
            if (strcmp(methods, "asc") == 0) { //dan menggunakan metode ascending, maka lakukan proses dibawah ini
            // Membandingkan data asal dengan data nextnya
                tunjuk = (*L).first; //inisialisasi tunjuk dengan L.first
                prev = NULL; //insialisasi prev dengan NULL
                // Kemudian disini terdapat 2 while pembanding, untuk pointer saat ini (tunjuk) dengan pointer yang membandingkannya (null)
                // Kedua while akan mengulang ketika nilai/value mereka bukan NULL
                while (tunjuk != NULL) {
                    null = tunjuk->next; // set/inisialisasi dengan next dari tunjuk
                    while (null != NULL) {
                        // Proses mengcompare pointer saat ini dengan pointer next
                        if(strcmp(tunjuk->kontainer.Judul, null->kontainer.Judul) > 0) {
                            //prevEl disini diibaratkan seperti prev sebelum current (tunjuk)
                            // ketika next dari prevEl nya itu merupakan pointer dari si nullnya, maka tidak diiterasi
                            // namun ketika next dari si prevElny itu bukan merupakan pointer dari si null, maka iterasi (analoginya mereka selalu bersebelahan)
                            prevEl = tunjuk; //inisialisasi bahwa prevEl selalu bersama dengan situnjuk
                            // perulangan untuk memindahkan prevEl selalu dibelakang dan bersebelahan dengan si null
                            while (prevEl->next != null) {
                                prevEl = prevEl->next;
                            }
                            // ---------

                            // jika si prev masih NULL yang berarti tunjuk (currentnya masih belum maju), maka...
                            if(prev == NULL) {
                                // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    (*L).first = null;          // pointer null ke L.first
                                    tunjuk->next = null->next;  // Kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // Lalu terakhir pointer tunjuk ke null->next
                                    // jika prevEl tidak sama dengan value tunjuk, maka...
                                }else {
                                    (*L).first = tunjuk->next;  // tunjuk->next ke L.first
                                    tunjuk->next = null->next;  // kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // kemudian pointer tunjuk isikan kedalam pointer null->next
                                    prevEl->next = null->next;  // lalu pointer null->next ke pointer prevEl->next
                                    null->next = (*L).first;    // pointer first isikan kedalam pointer null->next
                                    (*L).first = null;          // terakhir pointer null isikan/kaitkan kedalam pointer first
                                }
                            }else { // jika si prev tidak NULL, maka...
                            // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    prev->next = null;          // pointer null ke prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                }else {
                                    prev->next = tunjuk->next;  // pointer tunjuk->next ke pointer prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer L.first
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                    prevEl->next = null->next;  // pointer null->next ke pointer prevEl->next
                                    null->next = prev->next;    // pointer prev->next ke pointer null->next
                                    prev->next = null;          // pointer null ke pointer prev->next
                                }
                            }
                            // agar ketika ada data yang ditukar, tunjuk dan null terreset kembali
                            tempsV = tunjuk;    // pointer tunjuk arahkan ke bungkusan tempsv
                            tunjuk = null;      // kemudian isikan pointer tunjuk dengan value pointer null
                            null = tempsV;      // terakhir baru pindahkan kembali isi dari bungkusan tempsv kedalam pointer null
                        }
                        null = null->next; //iterasi
                    }
                    prev = tunjuk; //inisialisasi
                    tunjuk = tunjuk->next; //iterasi
                }
            }else if (strcmp(methods, "desc") == 0) { //atau menggunakan metode descending, maka lakukan proses dibawah ini
            // Membandingkan data asal dengan data nextnya
                tunjuk = (*L).first; //inisialisasi tunjuk dengan L.first
                prev = NULL; //insialisasi prev dengan NULL
                // Kemudian disini terdapat 2 while pembanding, untuk pointer saat ini (tunjuk) dengan pointer yang membandingkannya (null)
                // Kedua while akan mengulang ketika nilai/value mereka bukan NULL
                while (tunjuk != NULL) {
                    null = tunjuk->next; // set/inisialisasi dengan next dari tunjuk
                    while (null != NULL) {
                        // Proses mengcompare pointer saat ini dengan pointer next
                        if(strcmp(tunjuk->kontainer.Judul, null->kontainer.Judul) < 0) {
                            //prevEl disini diibaratkan seperti prev sebelum current (tunjuk)
                            // ketika next dari prevEl nya itu merupakan pointer dari si nullnya, maka tidak diiterasi
                            // namun ketika next dari si prevElny itu bukan merupakan pointer dari si null, maka iterasi (analoginya mereka selalu bersebelahan)
                            prevEl = tunjuk; //inisialisasi bahwa prevEl selalu bersama dengan situnjuk
                            // perulangan untuk memindahkan prevEl selalu dibelakang dan bersebelahan dengan si null
                            while (prevEl->next != null) {
                                prevEl = prevEl->next;
                            }
                            // ---------

                            // jika si prev masih NULL yang berarti tunjuk (currentnya masih belum maju), maka...
                            if(prev == NULL) {
                                // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    (*L).first = null;          // pointer null ke L.first
                                    tunjuk->next = null->next;  // Kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // Lalu terakhir pointer tunjuk ke null->next
                                    // jika prevEl tidak sama dengan value tunjuk, maka...
                                }else {
                                    (*L).first = tunjuk->next;  // tunjuk->next ke L.first
                                    tunjuk->next = null->next;  // kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // kemudian pointer tunjuk isikan kedalam pointer null->next
                                    prevEl->next = null->next;  // lalu pointer null->next ke pointer prevEl->next
                                    null->next = (*L).first;    // pointer first isikan kedalam pointer null->next
                                    (*L).first = null;          // terakhir pointer null isikan/kaitkan kedalam pointer first
                                }
                            }else { // jika si prev tidak NULL, maka...
                            // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    prev->next = null;          // pointer null ke prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                }else {
                                    prev->next = tunjuk->next;  // pointer tunjuk->next ke pointer prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer L.first
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                    prevEl->next = null->next;  // pointer null->next ke pointer prevEl->next
                                    null->next = prev->next;    // pointer prev->next ke pointer null->next
                                    prev->next = null;          // pointer null ke pointer prev->next
                                }
                            }
                            // agar ketika ada data yang ditukar, tunjuk dan null terreset kembali
                            tempsV = tunjuk;    // pointer tunjuk arahkan ke bungkusan tempsv
                            tunjuk = null;      // kemudian isikan pointer tunjuk dengan value pointer null
                            null = tempsV;      // terakhir baru pindahkan kembali isi dari bungkusan tempsv kedalam pointer null
                        }
                        null = null->next; //iterasi
                    }
                    prev = tunjuk; //inisialisasi
                    tunjuk = tunjuk->next; //iterasi
                }
            }
        }else if (strcmp(SortedData, "rating") == 0) { //jika data pengurutan memilih rating
            if (strcmp(methods, "asc") == 0) { //dan menggunakan metode ascending, maka lakukan proses dibawah ini
            // Membandingkan data asal dengan data nextnya
                tunjuk = (*L).first; //inisialisasi tunjuk dengan L.first
                prev = NULL; //insialisasi prev dengan NULL
                // Kemudian disini terdapat 2 while pembanding, untuk pointer saat ini (tunjuk) dengan pointer yang membandingkannya (null)
                // Kedua while akan mengulang ketika nilai/value mereka bukan NULL
                while (tunjuk != NULL) {
                    null = tunjuk->next; // set/inisialisasi dengan next dari tunjuk
                    while (null != NULL) {
                        // Proses mengcompare pointer saat ini dengan pointer next
                        if(strcmp(tunjuk->kontainer.ratingFilm, null->kontainer.ratingFilm) > 0) {
                            //prevEl disini diibaratkan seperti prev sebelum current (tunjuk)
                            // ketika next dari prevEl nya itu merupakan pointer dari si nullnya, maka tidak diiterasi
                            // namun ketika next dari si prevElny itu bukan merupakan pointer dari si null, maka iterasi (analoginya mereka selalu bersebelahan)
                            prevEl = tunjuk; //inisialisasi bahwa prevEl selalu bersama dengan situnjuk
                            // perulangan untuk memindahkan prevEl selalu dibelakang dan bersebelahan dengan si null
                            while (prevEl->next != null) {
                                prevEl = prevEl->next;
                            }
                            // ---------

                            // jika si prev masih NULL yang berarti tunjuk (currentnya masih belum maju), maka...
                            if(prev == NULL) {
                                // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    (*L).first = null;          // pointer null ke L.first
                                    tunjuk->next = null->next;  // Kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // Lalu terakhir pointer tunjuk ke null->next
                                    // jika prevEl tidak sama dengan value tunjuk, maka...
                                }else {
                                    (*L).first = tunjuk->next;  // tunjuk->next ke L.first
                                    tunjuk->next = null->next;  // kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // kemudian pointer tunjuk isikan kedalam pointer null->next
                                    prevEl->next = null->next;  // lalu pointer null->next ke pointer prevEl->next
                                    null->next = (*L).first;    // pointer first isikan kedalam pointer null->next
                                    (*L).first = null;          // terakhir pointer null isikan/kaitkan kedalam pointer first
                                }
                            }else { // jika si prev tidak NULL, maka...
                            // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    prev->next = null;          // pointer null ke prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                }else {
                                    prev->next = tunjuk->next;  // pointer tunjuk->next ke pointer prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer L.first
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                    prevEl->next = null->next;  // pointer null->next ke pointer prevEl->next
                                    null->next = prev->next;    // pointer prev->next ke pointer null->next
                                    prev->next = null;          // pointer null ke pointer prev->next
                                }
                            }
                            // agar ketika ada data yang ditukar, tunjuk dan null terreset kembali
                            tempsV = tunjuk;    // pointer tunjuk arahkan ke bungkusan tempsv
                            tunjuk = null;      // kemudian isikan pointer tunjuk dengan value pointer null
                            null = tempsV;      // terakhir baru pindahkan kembali isi dari bungkusan tempsv kedalam pointer null
                        }
                        null = null->next; //iterasi
                    }
                    prev = tunjuk; //inisialisasi
                    tunjuk = tunjuk->next; //iterasi
                }
            }else if (strcmp(methods, "desc") == 0) { //atau menggunakan metode descending, maka lakukan proses dibawah ini
                // Membandingkan data asal dengan data nextnya
                tunjuk = (*L).first; //inisialisasi tunjuk dengan L.first
                prev = NULL; //insialisasi prev dengan NULL
                // Kemudian disini terdapat 2 while pembanding, untuk pointer saat ini (tunjuk) dengan pointer yang membandingkannya (null)
                // Kedua while akan mengulang ketika nilai/value mereka bukan NULL
                while (tunjuk != NULL) {
                    null = tunjuk->next; // set/inisialisasi dengan next dari tunjuk
                    while (null != NULL) {
                        // Proses mengcompare pointer saat ini dengan pointer next
                        if(strcmp(tunjuk->kontainer.ratingFilm, null->kontainer.ratingFilm) < 0) {
                            //prevEl disini diibaratkan seperti prev sebelum current (tunjuk)
                            // ketika next dari prevEl nya itu merupakan pointer dari si nullnya, maka tidak diiterasi
                            // namun ketika next dari si prevElny itu bukan merupakan pointer dari si null, maka iterasi (analoginya mereka selalu bersebelahan)
                            prevEl = tunjuk; //inisialisasi bahwa prevEl selalu bersama dengan situnjuk
                            // perulangan untuk memindahkan prevEl selalu dibelakang dan bersebelahan dengan si null
                            while (prevEl->next != null) {
                                prevEl = prevEl->next;
                            }
                            // ---------

                            // jika si prev masih NULL yang berarti tunjuk (currentnya masih belum maju), maka...
                            if(prev == NULL) {
                                // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    (*L).first = null;          // pointer null ke L.first
                                    tunjuk->next = null->next;  // Kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // Lalu terakhir pointer tunjuk ke null->next
                                    // jika prevEl tidak sama dengan value tunjuk, maka...
                                }else {
                                    (*L).first = tunjuk->next;  // tunjuk->next ke L.first
                                    tunjuk->next = null->next;  // kemudian pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // kemudian pointer tunjuk isikan kedalam pointer null->next
                                    prevEl->next = null->next;  // lalu pointer null->next ke pointer prevEl->next
                                    null->next = (*L).first;    // pointer first isikan kedalam pointer null->next
                                    (*L).first = null;          // terakhir pointer null isikan/kaitkan kedalam pointer first
                                }
                            }else { // jika si prev tidak NULL, maka...
                            // bandingkan kembali, apakah value prevEl sama dengan value tunjuknya ?, jika iya maka...
                                if (prevEl == tunjuk) {
                                    prev->next = null;          // pointer null ke prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer tunjuk->next
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                }else {
                                    prev->next = tunjuk->next;  // pointer tunjuk->next ke pointer prev->next
                                    tunjuk->next = null->next;  // pointer null->next ke pointer L.first
                                    null->next = tunjuk;        // pointer tunjuk ke pointer null->next
                                    prevEl->next = null->next;  // pointer null->next ke pointer prevEl->next
                                    null->next = prev->next;    // pointer prev->next ke pointer null->next
                                    prev->next = null;          // pointer null ke pointer prev->next
                                }
                            }
                            // agar ketika ada data yang ditukar, tunjuk dan null terreset kembali
                            tempsV = tunjuk;    // pointer tunjuk arahkan ke bungkusan tempsv
                            tunjuk = null;      // kemudian isikan pointer tunjuk dengan value pointer null
                            null = tempsV;      // terakhir baru pindahkan kembali isi dari bungkusan tempsv kedalam pointer null
                        }
                        null = null->next; //iterasi
                    }
                    prev = tunjuk; //inisialisasi
                    tunjuk = tunjuk->next; //iterasi
                }
            }
        }
    }
}

void PrintOutElement (list L) {
    elemen *tunjuk = L.first; // inisialisasi pointer bungkusan dengan data awal
    while (tunjuk != NULL) { // jika data belum null
    // Maka tampilkan output dibawah ini
        printf("%s - %s\n", tunjuk->kontainer.Judul, tunjuk->kontainer.Production);

        // Iterasi
        tunjuk = tunjuk->next;
    }
}
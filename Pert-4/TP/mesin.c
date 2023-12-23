// Saya Raisyad Jullfikar NIM 2106238
// mengerjakan soal TP2 dalam mata kuliah Struktur Data
// untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
#include "header.h"

// Pembuatan List
void createList(list *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
}

// Penghitungan elemen
int countEl(list L) {
    int sum = 0;
    if (L.first != NULL) {
        elemen *ptr;
        ptr = L.first;
        while (ptr != NULL) {
            sum++;
            ptr = ptr->next;
        }
    }
    return sum;
}

// Menambah list secara first
void addFirst(dataKontainer kontainer, list *L) {
    elemen *newPtr;
    newPtr = (elemen *)malloc(sizeof(elemen));

    newPtr->kontainer = kontainer;

    if ((*L).first == NULL) {
        newPtr->next = NULL;
        newPtr->prev = NULL;
        (*L).tail = newPtr;
    }
    else {
        newPtr->next = (*L).first;
        newPtr->prev = NULL;
        (*L).first->prev = newPtr;
    }

    (*L).first = newPtr;
    newPtr = NULL;
}

// Menambah list secara after
void addAfter(elemen *before, dataKontainer kontainer, list *L) {
    if (before != NULL) {
        elemen *newPtr;
        newPtr = (elemen *)malloc(sizeof(elemen));

        newPtr->kontainer = kontainer;

        if (before->next == NULL) {
            newPtr->next = NULL;
            (*L).tail = newPtr;
        }
        else {
            newPtr->next = before->next;
            newPtr->next->prev = newPtr;
        }
        newPtr->prev = before;
        before->next = newPtr;
        newPtr = NULL;
    }
}

// Menghapus elemen ke-pertama
void delFirst(list *L) {
    if ((*L).first != NULL) {
        elemen *delPtr = (*L).first;
        if (countEl(*L) == 1) {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            delPtr->next = NULL;
        }
        free(delPtr);
    }
}

// Menghapus elemen ke-after
void delAfter(elemen *before, list *L) {
    if (before != NULL) {
        elemen *delPtr = before->next;
        if (delPtr != NULL) {
            if (delPtr->next == NULL){
                (*L).tail = before;
                before->next = NULL;
            }
            else {
                before->next = delPtr->next;
                delPtr->next->prev = before;
                delPtr->next = NULL;
            }
            delPtr->prev = NULL;
            free(delPtr);
        }
    }
}

// Menghapus elemen ke-terakhir
void delLast(list *L) {
    if ((*L).first != NULL) {
        if (countEl(*L) == 1)
            delFirst(L);
        else
            delAfter((*L).tail->prev, L);
    }
}

// Output Kadaluwarsa
void printKD(list *L) {
    elemen *ptr;
    elemen *mark;
    int markEl = 0;

    ptr = (*L).tail;
    printf("\nList bahan kadaluarsa:\n");
    while (ptr != NULL) {
        if (ptr->kontainer.Date < 9) { //Syarat output keluar ketika < 9 (tgl keluarnya soal)
            markEl = 1;
            printf("0%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc); 
            mark = ptr->prev;
            if (ptr == (*L).tail) { //jika pointer sekarang berada di akhir, maka lakukan dellast
                ptr = ptr->prev;
                delLast(L);
            }else if (ptr == (*L).first) {  //jika pointer sekarang berada di awal, maka lakukan delfirst
                ptr = ptr->next;
                delFirst(L);
            }else { //jika pointer sekarang berada di tengah tengah, maka lakukan delafter
                mark = ptr;
                ptr = ptr->next;
                delAfter(mark->prev,L);
            }
        }else {
            ptr = ptr->prev;
        }
    }
    if (markEl == 0) {
        printf("-\n");
    }
}

// Print bahan sisa
void printEl(list *L) {
    printf("\nList bahan sisa:\n");
    if ((*L).first != NULL) {
        // Sebelum diprint, list disorting berdasarkan deskripsi terlebih dahulu
        sortAscDesc(L);
        elemen *ptr = (*L).first;
        int markEl = 0;

        while (ptr != NULL) {
            if (ptr->kontainer.Date <= 9) { //syarat jika angka kurang dari = 9
                markEl = 1;
                printf("0%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }else { //jika bukan kurang dari = 9
                printf("%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }
            ptr = ptr->next;
        }
    }else {
        printf("-\n");
    }
}

// Print semua bahan secara dari belakang
void printRev(list *L) {
    printf("List semua bahan:\n");
    if ((*L).first != NULL) {
        elemen *ptr = (*L).tail;
        while (ptr != NULL) {
            if (ptr->kontainer.Date <= 9) {
                printf("0%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }else {
                printf("%d %s\n", ptr->kontainer.Date, ptr->kontainer.Desc);
            }
            ptr = ptr->prev;
        }
    }
}

// Proses sorting ascending berdasarkan tanggal
void sortAscDate(list *L) {
    elemen *current, *front, *tempPtr, *tempEl1, *tempEl2, *tempNP, *tempPN;
    current = (elemen *)malloc(sizeof(elemen)); front = (elemen *)malloc(sizeof(elemen));
    tempPtr = (elemen *)malloc(sizeof(elemen));
    tempEl1 = (elemen *)malloc(sizeof(elemen)); tempEl2 = (elemen *)malloc(sizeof(elemen));
    tempNP = (elemen *)malloc(sizeof(elemen)); tempPN = (elemen *)malloc(sizeof(elemen));

    current = (*L).first; //Inisialisasi
    
    // Ketika pointer dari currentnext bukan null... (while utama)
    while (current->next != NULL) {
        front = current->next; //inisialisasi
        while (front != NULL) { // While Kedua(pencarian)
            if (current->kontainer.Date > front->kontainer.Date){ //membandingkan
                if (current->next == front) { //jika kotak list bersebelahan
                    if (current->prev == NULL){ //kondisi ketika current dari prev merupakan null (kotak pertama)
                        (*L).first = front;
                    }
                    if (front->next == NULL) { //kondisi ketika front dari next merupakan null (kotak terakhir)
                        (*L).tail = current;
                    }
                    tempEl1 = current->next;            //Pemindahan current->next ke tempel1
                    current->next = front->next;        //front next ke current next
                    if(current->next != NULL) {         //kondisi ketika current next tidak merupakan null
                        current->next->prev = current;
                    }
                    if (current->prev != NULL) {        //kondisi ketika current prev tidak merupkan null
                        current->prev->next = front;
                    }

                    front->next = current;              //pemindahan current ke front next
                    tempEl2 = current->prev;            //current prev ke tempel2
                    current->prev = front;              //front ke current prev
                    front->prev = tempEl2;              //tempel2 ke front prev

                    // Proses reset kembali pointer jika keduanya sudah melakukan penukaran
                    tempPtr = current;
                    current = front;
                    front = tempPtr;

                }else { //jika list tidak bersebelahan
                    if (current->prev == NULL){ //kondisi ketika current dari prev merupakan null (kotak pertama)
                        (*L).first = front;
                    }
                    if (front->next == NULL) { //kondisi ketika front dari next merupakan null (kotak terakhir)
                        (*L).tail = current;
                    }

                    current->next->prev = front;        //Pemindahan front ke current next prevnya
                    front->prev->next = current;        //current ke front prev nextnya
                    if (front->next != NULL) {          //kondisi ketika front berada tidak di akhir
                        front->next->prev = current;
                    }
                    if (current->prev != NULL) {        //kondisi ketika current berada tidak diawal
                        current->prev->next = front;
                    }

                    tempEl1 = current->next;            //pemindahan current next ke tempel1
                    current->next = front->next;        //front next ke current next
                    front->next = tempEl1;              //tempel1 ke front next

                    tempEl2 = front->prev;              //pemindahan front prev ke tempel2
                    front->prev = current->prev;        //front prev ke current prev
                    current->prev = tempEl2;            //tempel2 ke current prev

                    // Proses reset kembali pointer jika keduanya sudah melakukan penukaran
                    tempPtr = current;
                    current = front;
                    front = tempPtr;
                }
            }
            // Iterasi
            front = front->next;
        }
        // Iterasi
        current = current->next;
    }
}

void sortAscDesc(list *L) {
    elemen *current, *front, *tempPtr, *tempEl1, *tempEl2, *tempNP, *tempPN;
    current = (elemen *)malloc(sizeof(elemen)); front = (elemen *)malloc(sizeof(elemen));
    tempPtr = (elemen *)malloc(sizeof(elemen));
    tempEl1 = (elemen *)malloc(sizeof(elemen)); tempEl2 = (elemen *)malloc(sizeof(elemen));
    tempNP = (elemen *)malloc(sizeof(elemen)); tempPN = (elemen *)malloc(sizeof(elemen));

    current = (*L).first;
    while (current->next != NULL) {
        front = current->next;
        while (front != NULL) {
            if (strcmp(current->kontainer.Desc, front->kontainer.Desc) > 0){
                if (current->next == front) {
                    if (current->prev == NULL){ //kondisi ketika current dari prev merupakan null (kotak pertama)
                        (*L).first = front;
                    }
                    if (front->next == NULL) { //kondisi ketika front dari next merupakan null (kotak terakhir)
                        (*L).tail = current;
                    }
                    tempEl1 = current->next;            //Pemindahan current->next ke tempel1
                    current->next = front->next;        //front next ke current next
                    if(current->next != NULL) {         //kondisi ketika current next tidak merupakan null
                        current->next->prev = current;
                    }
                    if (current->prev != NULL) {        //kondisi ketika current prev tidak merupkan null
                        current->prev->next = front;
                    }

                    front->next = current;              //pemindahan current ke front next
                    tempEl2 = current->prev;            //current prev ke tempel2
                    current->prev = front;              //front ke current prev
                    front->prev = tempEl2;              //tempel2 ke front prev

                    // Proses reset kembali pointer jika keduanya sudah melakukan penukaran
                    tempPtr = current;
                    current = front;
                    front = tempPtr;

                }else { //jika list tidak bersebelahan
                    if (current->prev == NULL){ //kondisi ketika current dari prev merupakan null (kotak pertama)
                        (*L).first = front;
                    }
                    if (front->next == NULL) { //kondisi ketika front dari next merupakan null (kotak terakhir)
                        (*L).tail = current;
                    }

                    current->next->prev = front;        //Pemindahan front ke current next prevnya
                    front->prev->next = current;        //current ke front prev nextnya
                    if (front->next != NULL) {          //kondisi ketika front berada tidak di akhir
                        front->next->prev = current;
                    }
                    if (current->prev != NULL) {        //kondisi ketika current berada tidak diawal
                        current->prev->next = front;
                    }

                    tempEl1 = current->next;            //pemindahan current next ke tempel1
                    current->next = front->next;        //front next ke current next
                    front->next = tempEl1;              //tempel1 ke front next

                    tempEl2 = front->prev;              //pemindahan front prev ke tempel2
                    front->prev = current->prev;        //front prev ke current prev
                    current->prev = tempEl2;            //tempel2 ke current prev

                    // Proses reset kembali pointer jika keduanya sudah melakukan penukaran
                    tempPtr = current;
                    current = front;
                    front = tempPtr;
                }
            }
            // Iterasi
            front = front->next;
        }
        // Iterasi
        current = current->next;
    }
}
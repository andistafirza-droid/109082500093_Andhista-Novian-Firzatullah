# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">Andhista Novian Firzatullah - 109082500092</p>

## Dasar Teori

Singly Linked List merupakan model ADT Linked List yang hanya memiliki satu arah pointer. Setiap elemen (node) terdiri dari dua bagian: info (data yang disimpan) dan next (pointer yang menunjuk ke elemen berikutnya). Linked list bersifat dinamis karena dapat tumbuh dan mengerut sesuai kebutuhan, berbeda dengan array yang bersifat statis [1]. Istilah penting dalam Singly Linked List: first/head: pointer yang menunjuk alamat elemen pertama list next: pointer pada elemen yang berfungsi sebagai successor Nil/NULL: nilai kosong, tidak mengacu ke mana pun Node/simpul: tempat penyimpanan data pada memori Operasi dasar ADT Linked List meliputi: CreateList, alokasi, dealokasi, insertFirst, insertLast, insertAfter, deleteFirst, deleteLast, deleteAfter, printInfo, dan nbList [1]. Pada Modul 5 ditambahkan operasi searching, update, serta operasi terhadap list seperti menghitung total info elemen. Implementasi ADT di C++ dilakukan dengan memisahkan file .h (header untuk prototipe dan tipe data), .cpp (realisasi primitif), dan main.cpp (driver program) [2].

## Guided 

### 1.Program ADT Singly Linked List Data Buah dengan Operasi Update dan Searching
Program ini merupakan implementasi ADT Singly Linked List untuk data buah. Setiap node menyimpan nama, jumlah, dan harga bertipe dataBuah. Deklarasi tipe dan prototipe fungsi diletakkan pada listBuah.h, realisasi fungsi pada listBuah.cpp, dan driver program pada main.cpp. Selain operasi dasar insert dan delete, program ini juga menambahkan operasi update (updateFirst, updateLast, updateAfter) serta searching (FindNodeByData, FindNodeByAddress, dan FindNodeByRange).
```C++
// File: listBuah.h
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; 

typedef struct node *address; 

struct node{ 
    dataBuah isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List,address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif

// File: listBuah.cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama 
                 << ", Jumlah : " << nodeBantu->isidata.jumlah 
                 << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama 
                     << ", Jumlah : " << nodeBantu->isidata.jumlah 
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama 
                     << ", Jumlah : " << nodeBantu->isidata.jumlah 
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama 
                     << ", Jumlah : " << nodeBantu->isidata.jumlah 
                     << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

// File: main.cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    createList(List);

    address apel   = alokasi("Apel", 10, 5000);
    address jeruk  = alokasi("Jeruk", 20, 3000);
    address mangga = alokasi("Mangga", 15, 7000);
    address anggur = alokasi("Anggur", 5, 12000);

    insertFirst(List, apel);
    insertLast(List, jeruk);
    insertAfter(List, mangga, apel);
    insertLast(List, anggur);

    cout << "--- ISI LIST AWAL ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    cout << "--- SEARCHING ---" << endl;
    FindNodeByData(List, "Mangga");
    FindNodeByAddress(List, mangga);
    FindNodeByRange(List, 4000, 8000);

    // Update dapat diaktifkan sesuai kebutuhan praktikum
    // updateFirst(List);
    // updateLast(List);
    // updateAfter(List, apel);

    cout << "--- DELETE ---" << endl;
    delFirst(List);
    delLast(List);

    address nodeHapus;
    delAfter(List, nodeHapus, mangga);

    cout << "--- ISI LIST SETELAH DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);

    cout << "--- ISI LIST SETELAH DELETE LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;

    return 0;
}
```
Program ini mendemonstrasikan ADT Singly Linked List pada data buah yang mencakup operasi insert, searching (berdasarkan nama, alamat, dan rentang harga), update, serta delete beserta dealokasi memori untuk mengelola node secara dinamis.
## Unguided 

### 1. Program ADT Singly Linked List - Insert First

```C++

File: Singlylist.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

File: Singlylist.cpp
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;

    P->info = x;
    P->next = Nil;

    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info;

        if (P->next != Nil) {
            cout << " ";
        }

        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

File: main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi Singly Linked List: ";
    printInfo(L);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/andistafirza-droid/109082500093_Andhista-Novian-Firzatullah/blob/main/Modul-5/Hasil%20Output/Output-Modul5-1.png)

Program ini diawali dengan membuat sebuah list kosong menggunakan prosedur `CreateList`, yang berfungsi untuk menginisialisasi pointer `First` agar tidak menunjuk ke node mana pun. Setelah itu, program mengalokasikan lima node dengan nilai secara berurutan, yaitu 2, 0, 8, 12, dan 9. Setiap node kemudian dimasukkan ke dalam list menggunakan prosedur `insertFirst`, yang menempatkan node baru di posisi paling awal dan menghubungkannya dengan node yang sebelumnya sudah ada. Oleh karena itu, setiap kali sebuah node baru ditambahkan, posisi node tersebut akan berada di depan node sebelumnya. Hal ini menyebabkan urutan elemen di dalam list menjadi terbalik dari urutan penyisipannya, sehingga nilai 9 yang dimasukkan terakhir menjadi elemen pertama, diikuti oleh 12, 8, 0, dan 2 sebagai elemen terakhir. Selanjutnya, fungsi `printInfo` digunakan untuk menampilkan seluruh isi list dengan menelusuri setiap node mulai dari `First` hingga mencapai `Nil`. Berdasarkan proses tersebut, program menghasilkan output `9 12 8 0 2`. Hasil ini menunjukkan bahwa prosedur `insertFirst` berhasil menyisipkan node di awal list dan menghubungkan setiap node melalui pointer `next`, sesuai dengan ilustrasi Singly Linked List pada soal.

### 2.Pencarian Elemen dengan Info 8

```C++
File: Singlylist.h

#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);

#endif

File: Singlylist.cpp

#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;

    P->info = x;
    P->next = Nil;

    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info;

        if (P->next != Nil) {
            cout << " ";
        }

        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;

    while (P != Nil) {
        if (P->info == x) {
            return P;
        }

        P = P->next;
    }

    return Nil;
}
File: main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address hasil;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi Singly Linked List: ";
    printInfo(L);

    hasil = findElm(L, 8);

    if (hasil != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/andistafirza-droid/109082500093_Andhista-Novian-Firzatullah/blob/main/Modul-5/Hasil%20Output/Output-Modul5-2.png)

Fungsi `findElm` digunakan untuk mencari elemen tertentu di dalam Singly Linked List dengan menelusuri setiap node mulai dari elemen pertama hingga mencapai `Nil`. Pada setiap node, program membandingkan nilai `info` dengan nilai yang ingin dicari. Jika nilai yang dicari sama dengan nilai `info` pada node tersebut, fungsi akan mengembalikan alamat node yang sesuai. Namun, jika nilai tersebut tidak ditemukan setelah seluruh node diperiksa, fungsi akan mengembalikan `Nil`. Dalam program ini, pencarian dilakukan terhadap nilai 8 pada list yang berisi elemen 9, 12, 8, 0, dan 2. Proses pencarian dimulai dari nilai 9, kemudian dilanjutkan ke 12, hingga akhirnya menemukan nilai 8 pada node ketiga. Setelah nilai tersebut ditemukan, program menampilkan pesan `8 ditemukan dalam list`. Dengan demikian, fungsi `findElm` berhasil melakukan pencarian elemen sesuai dengan hasil yang diharapkan.

### 3. Menghitung Total Info Seluruh Elemen

```C++
File: Singlylist.h

#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int sumInfo(List L);

#endif

File: Singlylist.cpp

#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new Elmlist;

    P->info = x;
    P->next = Nil;

    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info;

        if (P->next != Nil) {
            cout << " ";
        }

        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;

    while (P != Nil) {
        if (P->info == x) {
            return P;
        }

        P = P->next;
    }

    return Nil;
}

int sumInfo(List L) {
    int total = 0;
    address P = L.First;

    while (P != Nil) {
        total += P->info;
        P = P->next;
    }

    return total;
}
File: main.cpp
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address hasil;
    int total;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi Singly Linked List: ";
    printInfo(L);

    hasil = findElm(L, 8);

    if (hasil != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    total = sumInfo(L);

    cout << "Total info dari kelima elemen adalah "
         << total << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/andistafirza-droid/109082500093_Andhista-Novian-Firzatullah/blob/main/Modul-5/Hasil%20Output/Output-Modul5-3.png)

Fungsi `sumInfo` digunakan untuk menghitung jumlah seluruh nilai yang tersimpan dalam node Singly Linked List. Proses perhitungan dimulai dengan menginisialisasi variabel `total` dengan nilai 0 dan menggunakan variabel bantu `P` untuk menunjuk ke node pertama melalui `First`. Selanjutnya, program menelusuri setiap node hingga mencapai `Nil`. Pada setiap node yang dikunjungi, nilai `info` akan ditambahkan ke variabel `total`, kemudian pointer `P` berpindah ke node berikutnya menggunakan `P = P->next`. Proses ini terus dilakukan sampai seluruh elemen dalam list selesai diperiksa. Dalam program ini, nilai yang terdapat pada list adalah 9, 12, 8, 0, dan 2. Setelah semua nilai dijumlahkan, diperoleh hasil 9 + 12 + 8 + 0 + 2 = 31. Hasil penjumlahan tersebut kemudian dikembalikan oleh fungsi `sumInfo` dan ditampilkan oleh program melalui pesan `Total info dari kelima elemen adalah 31`. Dengan demikian, fungsi `sumInfo` berhasil menghitung total nilai dari seluruh node yang terdapat dalam list sesuai dengan output yang diharapkan pada soal.


## Kesimpulan
Berdasarkan praktikum Modul 5, dapat disimpulkan bahwa Singly Linked List merupakan struktur data dinamis yang terdiri dari beberapa node yang saling terhubung melalui pointer `next`. Dalam implementasinya menggunakan C++, program disusun dengan konsep Abstract Data Type (ADT) melalui pemisahan file `Singlylist.h` sebagai tempat deklarasi tipe data dan prototipe fungsi, `Singlylist.cpp` sebagai tempat implementasi fungsi-fungsi yang telah dideklarasikan, serta `main.cpp` sebagai program utama untuk menjalankan dan menguji operasi yang dibuat. Melalui praktikum ini, dipelajari berbagai operasi pada Singly Linked List, mulai dari penyisipan elemen menggunakan `insertFirst`, yang menempatkan node baru di awal list sehingga urutan data menjadi terbalik dari urutan input, hingga proses pencarian menggunakan fungsi seperti `findElm`, `FindNodeByData`, `FindNodeByAddress`, dan `FindNodeByRange` untuk menemukan node berdasarkan nilai atau kriteria tertentu. Selain itu, operasi update digunakan untuk mengubah informasi pada node, baik di posisi pertama, posisi terakhir, maupun setelah node tertentu. Praktikum ini juga menunjukkan pentingnya pengelolaan memori dalam struktur data dinamis. Setiap node yang dihapus perlu didealokasi agar memori yang digunakan dapat dibebaskan dengan benar, sedangkan fungsi `deleteList` digunakan untuk menghapus seluruh node hingga list kembali kosong. Dengan memahami berbagai operasi tersebut, praktikan dapat mengetahui cara membuat, mengelola, mencari, memperbarui, dan menghapus elemen dalam Singly Linked List secara terstruktur menggunakan bahasa C++.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Modul 2 Struktur Data: Pengenalan Bahasa C++ (Bagian Kedua). Fakultas Informatika, Telkom University.

# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Andhista Novian Firzatullah - 109082500092</p>

## Dasar Teori

Singly Linked List merupakan model ADT Linked List yang hanya memiliki satu arah pointer. Setiap elemen (node) terdiri dari dua bagian: info (data yang disimpan) dan next (pointer yang menunjuk ke elemen berikutnya). Linked list bersifat dinamis karena dapat tumbuh dan mengerut sesuai kebutuhan, berbeda dengan array yang bersifat statis [1]. Istilah penting dalam Singly Linked List: first/head: pointer yang menunjuk alamat elemen pertama list next: pointer pada elemen yang berfungsi sebagai successor Nil/NULL: nilai kosong, tidak mengacu ke mana pun Node/simpul: tempat penyimpanan data pada memori Operasi dasar ADT Linked List meliputi: CreateList, alokasi, dealokasi, insertFirst, insertLast, insertAfter, deleteFirst, deleteLast, deleteAfter, printInfo, dan nbList [1]. Implementasi ADT di C++ dilakukan dengan memisahkan file .h (header untuk prototipe dan tipe data), .cpp (realisasi primitif), dan main.cpp (driver program) [2].

## Guided 

### 1.Program ADT Singly Linked List dengan Data Mahasiswa
Program ini merupakan implementasi ADT Singly Linked List yang memisahkan deklarasi tipe dan primitif ke dalam file list.h, realisasi primitif ke dalam file list.cpp, dan program utama di main.cpp. Struktur data terdiri dari mahasiswa (nama, nim, umur), node dengan field isidata bertipe dataMahasiswa dan next bertipe address, serta linkedList dengan field first.

```C++
File: list.h
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedList {
    address first;
};

bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif

File: list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList list) {
    if(list.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &list) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    list.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedList &list, address nodeBaru, address prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (prev != Nil) {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &list){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(list) == false) {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &list){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(list) == false){
        nodeHapus = list.first;
        if(nodeHapus->next == Nil){
            list.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &list, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(list) == true){
        cout << "list kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList list) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList list) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &list){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

File: main.cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satro", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini mendemonstrasikan konsep ADT Singly Linked List dengan pemisahan file header, implementasi, dan driver. Data yang digunakan adalah data mahasiswa dengan field nama, nim, dan umur. Proses insert dilakukan dengan insertFirst (Dhimas di awal), insertLast (Arvin di akhir), insertAfter (Rizal setelah Dhimas, Satro setelah Rizal), dan insertLast (Joshua di akhir) sehingga menghasilkan urutan Dhimas → Rizal → Satro → Arvin → Joshua dengan jumlah node 5. Proses delete dilakukan dengan delFirst (hapus Dhimas), delLast (hapus Joshua), dan delAfter dengan prev = Rizal (hapus Satro), sehingga tersisa Rizal → Arvin dengan jumlah node 2. Terakhir, deleteList menghapus seluruh node beserta memorinya sehingga list kembali kosong dengan jumlah node 0.

## Unguided 

### 1. Program ADT Singly Linked List - Insert First

```C++

File: singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct tElmtList *address;

typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address first;
} List;

void CreateList(List *L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List *L, address P);

#endif

File: singlylist.cpp
#include <iostream>
#include "Singlylist.h"

using namespace std;

void CreateList(List *L) {
    L->first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmtList;

    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }

    return P;
}

void dealokasi(address P) {
    delete P;
}

void printInfo(List L) {
    address P = L.first;

    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

void insertFirst(List *L, address P) {
    if (P != NULL) {
        P->next = L->first;
        L->first = P;
    }
}

File: main.cpp
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    CreateList(&L);

    P1 = alokasi(2);
    insertFirst(&L, P1);

    P2 = alokasi(0);
    insertFirst(&L, P2);

    P3 = alokasi(8);
    insertFirst(&L, P3);

    P4 = alokasi(12);
    insertFirst(&L, P4);

    P5 = alokasi(9);
    insertFirst(&L, P5);

    printInfo(L);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/andistafirza-droid/109082500093_Andhista-Novian-Firzatullah/blob/main/Modul-3/output/Output-Unguided-1.png)

Program menyimpan data maksimal 10 mahasiswa ke array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir dihitung fungsi hitungNilaiAkhir() dengan rumus 0.3uts + 0.4uas + 0.3*tugas.

### 2.ADT Pelajaran

```C++
File: pelajaran.h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif

File: pelajaran.cpp

#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;

    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}


File: unguided3.cpp

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/andistafirza-droid/109082500093_Andhista-Novian-Firzatullah/blob/main/Modul-3/output/Output-Unguided-2.png)

Program mengimplementasikan ADT Pelajaran dengan file pelajaran.h, pelajaran.cpp, dan main.cpp. Fungsi create_pelajaran sebagai konstruktor, prosedur tampil_pelajaran untuk menampilkan data.

### 3.  Program Array 2D dan Pointer

```C++

#include <iostream>
using namespace std;

void tampilArray(int A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3],
                int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int x = 100;
    int y = 200;

    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A sebelum ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B sebelum ditukar:" << endl;
    tampilArray(B);

    tukarArray(A, B, 1, 1);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(B);

    cout << "\nNilai sebelum pointer ditukar:" << endl;
    cout << "x = " << *p1 << endl;
    cout << "y = " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << "\nNilai setelah pointer ditukar:" << endl;
    cout << "x = " << *p1 << endl;
    cout << "y = " << *p2 << endl;

    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/andistafirza-droid/109082500093_Andhista-Novian-Firzatullah/blob/main/Modul-3/output/Output-Unguided-3.png)

Program menggunakan 2 array 2D 3x3 dan 2 pointer integer. Prosedur tampil menampilkan isi array, tukarElemen menukar elemen pada posisi tertentu, dan tukarPointer menukar nilai yang ditunjuk 2 pointer.

## Kesimpulan
Dari praktikum Modul 3 ini, dapat disimpulkan bahwa ADT merupakan konsep yang memisahkan spesifikasi tipe data dan implementasinya. Implementasi ADT di C++ dilakukan dengan memisahkan file .h (header), .cpp (realisasi), dan main.cpp (driver). Konsep ini membuat program lebih terstruktur dan mudah dikembangkan.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Modul 2 Struktur Data: Pengenalan Bahasa C++ (Bagian Kedua). Fakultas Informatika, Telkom University.

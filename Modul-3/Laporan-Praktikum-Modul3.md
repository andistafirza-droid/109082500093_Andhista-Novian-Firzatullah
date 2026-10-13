# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Andhista Novian Firzatullah - 109082500092</p>

## Dasar Teori

Abstract Data Type (ADT) adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi STATIK [1]. Definisi type dari sebuah ADT dapat mengandung sebuah definisi ADT lain. Misalnya ADT waktu yang terdiri dari ADT JAM dan ADT DATE, atau Garis terdiri dari dua buah ADT POINT [1]. TYPE diterjemahkan menjadi type terdefinisi dalam bahasa yang bersangkutan. Jika dalam bahasa C menggunakan struct PRIMITIF, dalam konteks prosedural, diterjemahkan menjadi fungsi atau prosedur. PRIMITIF dikelompokkan menjadi: Konstruktor/Kreator, Selector, Prosedur pengubah nilai komponen, Tipe validator komponen, Destruktor/Dealokator, Baca/Tulis, Operator relasional, Aritmatika, dan Konversi dari tipe tersebut ke tipe dasar dan sebaliknya [1].ADT biasanya diimplementasikan menjadi dua buah modul utama dan 1 modul interface program utama (driver). Dua modul tersebut adalah sebagai berikut:

Definisi/Spesifikasi Type dan Primitif/Header fungsi (.h) Spesifikasi type sesuai dengan kaidah bahasa yang dipakai Spesifikasi dari primitif sesuai dengan kaidah dalam konteks prosedural, yaitu: Fungsi: nama, domain, range, dan prekondisi jika ada Prosedur: Initial state, Final state, dan proses yang dilakukan
Body/realisasi dari primitif (.c) Berupa kode program dalam bahasa yang bersangkutan (dalam praktikum ini berarti dengan bahasa C++). Realisasi fungsi dan prosedur harus sedapat mungkin memanfaatkan selector dan konstruktor [1].

## Guided 

### 1.Program ADT Mahasiswa (Implementasi Konsep ADT)
Program ini merupakan implementasi konsep ADT (Abstract Data Type) yang memisahkan deklarasi tipe, variabel, dan fungsi ke dalam file .h, serta memisah definisi fungsi ke dalam file .cpp. Program terdiri dari tiga file: mahasiswa.h, mahasiswa.cpp, dan main.cpp.

```C++
File: mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif // MAHASISWA_H_INCLUDED

File: mahasiswa.cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai1 = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1+m.nilai2)/2;
}

File: main.cpp
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}
```
Program ini mendemonstrasikan penerapan konsep ADT dengan memisahkan deklarasi tipe dan primitif ke dalam file header (mahasiswa.h), realisasi primitif ke dalam file implementasi (mahasiswa.cpp), dan program utama (main.cpp). Struktur mahasiswa memiliki field nim, nilai1, dan nilai2. Prosedur inputMhs digunakan untuk mengisi data mahasiswa, sedangkan fungsi rata2 menghitung rata-rata dari dua nilai. Program utama memanggil prosedur inputMhs untuk mengisi data, kemudian menampilkan hasil rata-rata menggunakan fungsi rata2.

## Unguided 

### 1. Program Data Mahasiswa (Array Max 10)

```C++

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maksimal 10): ";
    cin >> jumlah;

    if (jumlah < 1 || jumlah > 10) {
        cout << "Jumlah mahasiswa harus 1 sampai 10." << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;

        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);

        cout << "NIM: ";
        cin >> mhs[i].nim;

        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(
            mhs[i].uts, mhs[i].uas, mhs[i].tugas
        );
    }

    cout << "\n=== DATA MAHASISWA ===" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nNama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "UTS: " << mhs[i].uts << endl;
        cout << "UAS: " << mhs[i].uas << endl;
        cout << "Tugas: " << mhs[i].tugas << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

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

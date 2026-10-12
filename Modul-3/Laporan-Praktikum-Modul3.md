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
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2/Output-Unguided1-2.png)

Program ini memakai dua *array* dua dimensi berukuran 3x3, yaitu `matA` dan `matB`, yang diisi lewat perulangan `for` bersarang. Untuk penjumlahan dan pengurangan, setiap elemen `matA[i][j]` dan `matB[i][j]` yang posisinya sama langsung dijumlahkan atau dikurangkan, lalu disimpan ke `hasilTambah` dan `hasilKurang`.

Untuk perkalian matriks, caranya berbeda karena tidak bisa langsung dikalikan per elemen seperti penjumlahan. Dipakai tiga perulangan `for` bersarang: `i` untuk baris hasil, `j` untuk kolom hasil, dan `k` untuk mengalikan baris matriks A dengan kolom matriks B lalu dijumlahkan semuanya (`hasilKali[i][j] += matA[i][k] * matB[k][j]`). Sebelum dijumlahkan, `hasilKali[i][j]` diberi nilai awal 0 dulu supaya hasilnya tidak tercampur dengan nilai sampah. Setelah semua proses selesai, ketiga hasil matriks ditampilkan dengan perulangan `for` yang sama seperti saat input.

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
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2/Output-Unguided2-2.png)

Program ini membuat dua fungsi untuk menukar nilai tiga variabel, satu memakai *pointer* dan satu lagi memakai *reference*, sesuai dengan materi *guided* sebelumnya. Pada fungsi `tukarPointer`, parameter yang dikirim berupa alamat variabel (`&a`, `&b`, `&c`), sehingga di dalam fungsi harus memakai tanda `*` untuk mengakses nilai yang ditunjuk oleh *pointer* tersebut.

Sedangkan pada fungsi `tukarReferensi`, parameternya dideklarasikan dengan tanda `&` di depan nama variabel (`int &x, int &y, int &z`). Karena memakai *reference*, saat pemanggilan fungsi cukup menuliskan nama variabelnya saja (`tukarReferensi(a, b, c);`) tanpa perlu `&`, tapi efeknya sama dengan *pointer* yaitu bisa langsung mengubah nilai variabel aslinya.

Proses penukaran pada kedua fungsi sama-sama memakai cara geser melingkar dengan bantuan variabel `temp`: nilai `x` disimpan dulu ke `temp`, lalu `x` diisi nilai `y`, `y` diisi nilai `z`, dan terakhir `z` diisi nilai `temp`. Jadi kalau awalnya a=1, b=2, c=3, maka setelah ditukar hasilnya menjadi a=2, b=3, c=1.

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
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan2_Modul2/Output-Unguided3-2.png)

Program ini menyimpan data `arrA` sebagai *array* satu dimensi berisi 10 elemen, lalu menyediakan menu berbentuk `switch-case` yang terus muncul berulang memakai `do...while` sampai user memilih keluar (pilihan 5). Setiap pilihan menu akan memanggil fungsi atau prosedur yang berbeda.

Untuk mencari nilai maksimum dan minimum, dibuat dua fungsi terpisah yaitu `cariMaksimum()` dan `cariMinimum()`. Keduanya menerima parameter berupa *array* dan jumlah elemennya, lalu nilai elemen pertama dianggap sebagai nilai maksimum/minimum sementara. Kemudian lewat perulangan `for`, setiap elemen dibandingkan satu per satu; kalau ditemukan elemen yang lebih besar (untuk maksimum) atau lebih kecil (untuk minimum) dari nilai sementara, nilai sementara itu diganti. Di akhir perulangan, nilai sementara itulah yang dikembalikan sebagai hasil akhir fungsi memakai `return`.

Untuk menghitung rata-rata, dipakai prosedur `hitungRataRata()` yang tidak mengembalikan nilai (`void`) karena hasilnya langsung dicetak di dalam prosedur itu sendiri. Caranya, semua elemen *array* dijumlahkan dengan perulangan `for` ke variabel `total`, lalu `total` dibagi dengan jumlah elemen `n`. Pembagian dilakukan dengan mengubah `total` menjadi `float` terlebih dahulu (`(float) total / n`) supaya hasilnya tidak dibulatkan ke bawah seperti pada pembagian bilangan bulat.

## Kesimpulan
Dari praktikum Modul 2 ini, saya belajar tentang *array*, *pointer*, fungsi, dan prosedur dalam bahasa C++. Pada soal pertama, saya memakai *array* dua dimensi dan perulangan `for` bersarang untuk operasi penjumlahan, pengurangan, dan perkalian matriks 3x3, di mana perkalian matriks ternyata membutuhkan perulangan tambahan dibanding penjumlahan dan pengurangan. Pada soal kedua, saya memahami perbedaan cara melewatkan parameter memakai *pointer* (dengan tanda `*` dan `&`) dan *reference* (dengan tanda `&` hanya di parameter formal) untuk mengubah nilai variabel yang ada di luar fungsi. Pada soal ketiga, saya belajar membuat program dengan menu `switch-case` yang memanggil fungsi `cariMinimum()`, `cariMaksimum()`, dan prosedur `hitungRataRata()` untuk mengolah data *array*. Dengan praktikum ini saya jadi lebih paham bagaimana memecah program menjadi fungsi-fungsi kecil membuat kode lebih rapi, terstruktur, dan mudah dipahami.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Modul 2 Struktur Data: Pengenalan Bahasa C++ (Bagian Kedua). Fakultas Informatika, Telkom University.

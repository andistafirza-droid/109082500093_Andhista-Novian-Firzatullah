# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

*Array* merupakan kumpulan data dengan nama yang sama dan setiap elemennya bertipe data sama, yang diakses berdasarkan indeks elemen tersebut [3]. Selain *array*, modul ini juga membahas *pointer* yaitu variabel yang menyimpan alamat memori dari variabel lain, serta fungsi dan prosedur sebagai cara untuk menyusun program menjadi lebih terstruktur [3].

### A. Array<br/>
*Array* digunakan untuk menyimpan sekumpulan data sejenis dalam satu nama variabel.
#### 1. Array Satu Dimensi
*Array* satu dimensi hanya terdiri dari satu larik data saja, dengan bentuk deklarasi `tipe_data nama_var[ukuran];`. Elemen pertama *array* memiliki indeks 0, sehingga *array* dengan 5 elemen memiliki indeks terakhir 4 [3].
#### 2. Array Dua Dimensi
*Array* dua dimensi mirip seperti tabel, memiliki dua indeks yaitu baris dan kolom, dengan bentuk deklarasi `tipe_data nama_var[baris][kolom];` [3].
#### 3. Array Berdimensi Banyak
*Array* berdimensi banyak memiliki indeks lebih dari dua, dengan bentuk deklarasi `tipe_data nama_var[ukuran1][ukuran2]...[ukuran-N];` [3].

### B. Pointer<br/>
*Pointer* merupakan variabel yang berisi alamat memori dari variabel lain.
#### 1. Alamat Memori
Setiap variabel yang dideklarasikan akan dialokasikan pada suatu alamat memori. Alamat memori suatu variabel dapat diketahui menggunakan *keyword* `&` di depan nama variabel tersebut [3].
#### 2. Deklarasi dan Penggunaan Pointer
*Pointer* dideklarasikan dengan bentuk `type *nama_variabel;`. Agar *pointer* menunjuk ke suatu variabel, *pointer* diisi dengan alamat variabel tersebut, misalnya `p_int = &j;`. Untuk mengambil nilai yang ditunjuk *pointer* digunakan tanda `*` di depan nama *pointer* [3].
#### 3. Pointer dan Array
*Pointer* memiliki keterhubungan kuat dengan *array*. Jika `pa = &a[0];`, maka `pa` menunjuk ke elemen pertama *array* `a`, dan `*(pa+i)` akan berisi nilai dari elemen `a[i]` [3].

### C. Fungsi, Prosedur, dan Parameter<br/>
Fungsi dan prosedur digunakan agar program lebih terstruktur dan mengurangi duplikasi kode [3].
#### 1. Fungsi
Fungsi adalah blok kode yang mengembalikan sebuah nilai balik, dengan bentuk umum `tipe_keluaran nama_fungsi(daftar_parameter) { ... }` [3].
#### 2. Prosedur
Prosedur adalah fungsi yang tidak mengembalikan nilai, dikenal dalam C++ sebagai fungsi `void`, dengan bentuk umum `void nama_prosedur(daftar_parameter) { ... }` [3].
#### 3. Parameter Fungsi
Parameter formal adalah variabel pada daftar parameter ketika fungsi didefinisikan, sedangkan parameter aktual adalah nilai yang dipakai saat memanggil fungsi [3]. Terdapat tiga cara melewatkan parameter: *call by value* (nilai disalin sehingga variabel asli tidak berubah), *call by pointer* (alamat variabel dilewatkan menggunakan `*` sehingga variabel asli bisa berubah), dan *call by reference* (alamat variabel dilewatkan menggunakan `&` pada parameter formal sehingga variabel asli bisa berubah tanpa perlu menuliskan `&` saat pemanggilan) [3].

## Guided 

### 1. Array satu dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "index ke-" << i << " = " << nilai[i] << endl;
    }

    return 0;
}
```
Program ini membuat *array* satu dimensi `nilai` berisi 5 elemen bertipe `int`. Setiap elemen diisi satu per satu lewat indeksnya (`nilai[0]` sampai `nilai[4]`), lalu seluruh isi *array* ditampilkan memakai perulangan `for` dari indeks 0 sampai 4.

### 2. Array dua dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 85, 90},
        {75, 80, 85},
        {90, 95, 100}
    };

    cout << nilai[0][0] << endl;
    cout << nilai[1][1] << endl;
    cout << nilai[2][2] << " ";

    return 0;
}
```
Program ini membuat *array* dua dimensi `nilai` berukuran 3x3 yang langsung diisi nilai awal saat dideklarasikan. Untuk mengakses elemen *array* dua dimensi dibutuhkan dua indeks, yaitu indeks baris dan indeks kolom, contohnya `nilai[1][1]` berarti mengambil elemen pada baris ke-1 kolom ke-1 yang hasilnya 80.

### 3. Array tiga dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        }
    };

    cout << data[0][1][1] << " ";

    return 0;
}
```
Program ini membuat *array* tiga dimensi `data` berukuran 2x3x3. Dimensi pertama bisa dibayangkan sebagai "lapisan" atau blok tabel, dimensi kedua sebagai baris, dan dimensi ketiga sebagai kolom. Jadi `data[0][1][1]` berarti mengambil elemen dari blok ke-0, baris ke-1, kolom ke-1, yang hasilnya 5.

### 4. Array berdimensi banyak (empat dimensi)

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
        {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        },
        {
            {
                {9, 10},
                {11, 12}
            },
            {
                {13, 14},
                {15, 16}
            }
        }
    };

    cout << data[0][0][0][0] << endl;
    cout << data[1][1][1][1] << endl;

    return 0;
}
```
Program ini membuat *array* berdimensi empat `data` berukuran 2x2x2x2 untuk menunjukkan bahwa *array* bisa memiliki indeks lebih dari tiga, meskipun semakin banyak dimensinya semakin sulit dibayangkan. Setiap elemen diakses dengan menuliskan empat indeks berurutan, misalnya `data[0][0][0][0]` mengambil elemen pertama yang hasilnya 1, sedangkan `data[1][1][1][1]` mengambil elemen terakhir yang hasilnya 16.

### 5. Pointer dan alamat memori

```C++
#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';
    j = 10;

    cout << a << endl;
    cout << &a << endl;

    cout << j << endl;
    cout << &j << endl;

    cout << arr[3] << endl;
    cout << &(arr[4]) << endl;

    return 0;
}
```
Program ini menunjukkan perbedaan antara nilai suatu variabel dan alamat memori tempat variabel itu disimpan. Nilai variabel dicetak langsung dengan `cout << a`, sedangkan alamat memorinya dicetak dengan menambahkan tanda `&` di depan nama variabel, misalnya `cout << &a`. Hal yang sama juga berlaku untuk elemen *array*, seperti `&(arr[4])` yang menunjukkan alamat dari elemen `arr[4]`.

### 6. Pointer menunjuk ke variabel

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;

    return 0;
}
```
Program ini membuat variabel *pointer* `px` yang menunjuk ke variabel `x` lewat pernyataan `px = &x;`, sehingga `px` berisi alamat memori dari `x`. Untuk mengambil nilai yang ditunjuk oleh *pointer* digunakan tanda `*` di depan nama *pointer*, seperti pada `y = *px;` yang menyalin nilai `x` ke variabel `y`. Dari *output*-nya terlihat bahwa alamat `x` sama dengan isi `px`, dan nilai yang ditunjuk `px` sama dengan nilai `x`.

### 7. Kombinasi array satu dan dua dimensi

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    for (i = 0; i < MAX; i++) {
        cout << "masukkan nilai ke-" << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa :\n";

    for (i = 0; i < MAX; i++)
        cout << "nilai k-" << i + 1 << "=" << nilai[i] << endl;

    cout << "\n nilai tahunan : \n";

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << nilai_tahun[i][j];

        cout << "\n";
    }

    return 0;
}
```
Program ini menggabungkan *array* satu dimensi `nilai` yang diisi lewat *input* user dengan *array* dua dimensi `nilai_tahun` yang sudah diisi nilai awal secara langsung (`static int`). *Array* `nilai` diisi dan ditampilkan memakai satu perulangan `for`, sedangkan *array* `nilai_tahun` ditampilkan memakai dua perulangan `for` bersarang karena memiliki dua indeks (baris dan kolom).

### 8. String sebagai array karakter

```C++
#include <iostream>
using namespace std;

int main() {
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;

    return 0;
}
```
Program ini membuat variabel `nama` bertipe `char[]` yang diisi dengan *string* "strukdat". Karena *string* pada dasarnya adalah *array* dari karakter, seluruh isi *string* bisa ditampilkan langsung dengan `cout << nama`, sedangkan satu karakter tertentu bisa diakses memakai indeksnya seperti pada *array* biasa, contohnya `nama[3]` yang mengambil karakter ke-3 dari "strukdat" yaitu huruf 'u'.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;

int main() {
    int matA[3][3], matB[3][3];
    int hasilTambah[3][3], hasilKurang[3][3], hasilKali[3][3];

    cout << "Masukkan elemen matriks A (3x3)" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> matA[i][j];
        }
    }

    cout << "\nMasukkan elemen matriks B (3x3)" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> matB[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilTambah[i][j] = matA[i][j] + matB[i][j];
            hasilKurang[i][j] = matA[i][j] - matB[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilKali[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasilKali[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    cout << "\nHasil Penjumlahan Matriks A + B :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << hasilTambah[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan Matriks A - B :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << hasilKurang[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian Matriks A x B :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << hasilKali[i][j] << " ";
        }
        cout << endl;
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

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z);
void tukarReferensi(int &x, int &y, int &z);

int main() {
    int a, b, c;

    cout << "Masukkan nilai variabel a = ";
    cin >> a;
    cout << "Masukkan nilai variabel b = ";
    cin >> b;
    cout << "Masukkan nilai variabel c = ";
    cin >> c;

    cout << "\nKondisi sebelum ditukar" << endl;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;

    tukarPointer(&a, &b, &c);
    cout << "\nKondisi setelah ditukar dengan pointer" << endl;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;

    tukarReferensi(a, b, c);
    cout << "\nKondisi setelah ditukar dengan reference" << endl;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;

    return 0;
}

void tukarPointer(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReferensi(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
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

### 3. Diketahui sebuah array 1 dimensi: arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}. Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata-rata dari array tersebut menggunakan function cariMinimum(), function cariMaksimum(), dan prosedur hitungRataRata(), dengan menu switch-case

```C++
#include <iostream>
using namespace std;

#define MAX 10

int cariMinimum(int arr[], int n);
int cariMaksimum(int arr[], int n);
void hitungRataRata(int arr[], int n);

int main() {
    int arrA[MAX] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. cari nilai maksimum" << endl;
        cout << "3. cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan anda = ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nIsi array arrA :" << endl;
                for (int i = 0; i < MAX; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "\nNilai maksimum dari array adalah = "
                     << cariMaksimum(arrA, MAX) << endl;
                break;

            case 3:
                cout << "\nNilai minimum dari array adalah = "
                     << cariMinimum(arrA, MAX) << endl;
                break;

            case 4:
                hitungRataRata(arrA, MAX);
                break;

            case 5:
                cout << "\nProgram selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;
    float rataRata;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    rataRata = (float) total / n;

    cout << "\nNilai rata-rata dari array adalah = " << rataRata << endl;
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

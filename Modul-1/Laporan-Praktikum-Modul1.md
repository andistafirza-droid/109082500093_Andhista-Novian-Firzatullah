# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

Bahasa C++ diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories pada awal tahun 1980-an. Bahasa ini berawal dari bahasa C yang ditambahi fasilitas kelas, sehingga pada mulanya disebut "C with class", lalu disempurnakan dengan penambahan pembebanlebihan operator dan fungsi hingga menjadi C++ [3]. Pada praktikum ini, C++ dipakai sebagai bahasa untuk mempelajari dasar-dasar pemrograman sebelum masuk ke materi struktur data.

### A. Struktur Program dan Identifier<br/>
Secara umum, program C++ tersusun dari beberapa bagian, yaitu pemanggilan *library* (`#include`), pendefinisian konstanta, pendefinisian tipe data bentukan, deklarasi variabel, deklarasi fungsi/prosedur, dan program utama `main()` [3]. Setiap pernyataan (*statement*) dalam C++ diakhiri dengan tanda titik koma (;).
#### 1. Library
Fungsi `cout` dan `cin` berada di *header file* `<iostream>`, sehingga harus dipanggil dengan `#include <iostream>` agar bisa dipakai [3].
#### 2. Identifier
*Identifier* adalah nama yang dipakai untuk variabel, konstanta, fungsi, atau objek lain. Aturannya: harus diawali huruf atau garis bawah (_), tidak boleh mengandung spasi, tidak boleh memakai operator aritmatika, dan bersifat *case sensitive* sehingga `panjang` berbeda dengan `Panjang` [3].
#### 3. Fungsi main()
`main()` adalah fungsi utama tempat program mulai dijalankan. Blok program ditulis di dalam kurung kurawal `{ }` dan biasanya diakhiri dengan `return 0;` [3].

### B. Tipe Data, Variabel, dan Konstanta<br/>
Data dapat dinyatakan dalam bentuk variabel atau konstanta. Tipe data dasar yang dibahas pada modul adalah `char`, `int`, `long`, `float`, dan `double` [3].
#### 1. Tipe Data Dasar
`int` dipakai untuk bilangan bulat, `float` dan `double` untuk bilangan pecahan (real) dengan presisi tunggal dan ganda, sedangkan `char` untuk karakter [3].
#### 2. Variabel
Variabel dipakai untuk menyimpan nilai yang bisa berubah selama program berjalan. Bentuk deklarasinya adalah `tipe_data nama_variabel;` dan variabel juga bisa langsung diberi nilai awal, misalnya `int x = 20;` [3].
#### 3. Konstanta
Konstanta menyimpan nilai yang selalu tetap. Untuk mendeklarasikannya cukup menambahkan kata `const` di depan tipe data, misalnya `const float phi = 3.14;` [3].

### C. Input dan Output<br/>
Operasi masukan dan keluaran pada C++ memakai `cin` dan `cout` dari *library* `iostream` [3].
#### 1. Output dengan cout
`cout` digunakan untuk mencetak data, baik teks maupun angka, dengan operator `<<`. Perintah `endl` atau `\n` dipakai untuk pindah ke baris baru [3].
#### 2. Input dengan cin
`cin` digunakan untuk membaca masukan dari *keyboard* dengan operator `>>`, dan nilainya langsung disimpan ke variabel yang dituju tanpa perlu penentu format seperti pada `printf()` [3].
#### 3. Escape Sequence
*Escape sequence* adalah karakter khusus yang diawali tanda `\`, contohnya `\n` untuk baris baru dan `\t` untuk tabulasi [3].

### D. Operator<br/>
Operator adalah simbol yang dipakai untuk melakukan suatu operasi atau manipulasi [3].
#### 1. Operator Aritmatika
Terdiri dari penjumlahan (+), pengurangan (-), perkalian (*), pembagian (/), dan sisa bagi (%). Untuk mengubah urutan pengerjaan dapat dipakai tanda kurung [3]. Pada pembagian dua bilangan bulat, hasilnya juga bilangan bulat sehingga bagian desimalnya dibuang.
#### 2. Operator Relasi dan Logika
Operator relasi (`==`, `!=`, `<`, `<=`, `>`, `>=`) dipakai untuk membandingkan dua nilai, sedangkan operator logika (`&&`, `||`, `!`) dipakai untuk menggabungkan atau membalik kondisi [3].
#### 3. Operator Increment dan Decrement
Operator `++` menambah nilai variabel sebanyak 1, sedangkan `--` menguranginya sebanyak 1 [3].

### E. Kondisional dan Perulangan<br/>
Untuk mengambil keputusan, C++ menyediakan pernyataan `if`, `if-else`, dan `switch` [3]. Untuk mengulang suatu proses, C++ menyediakan `for`, `while`, dan `do...while`, dan setiap perulangan harus punya kondisi berhenti [3].
#### 1. if dan if-else
Pernyataan `if` menjalankan perintah hanya jika kondisinya benar, dan `else` menjalankan perintah lain jika kondisinya salah [3].
#### 2. switch
`switch` dirancang khusus untuk pengambilan keputusan dengan banyak alternatif. Setiap `case` biasanya diakhiri `break`, dan `default` dijalankan bila tidak ada `case` yang cocok [3].
#### 3. for, while, dan do...while
Perulangan `for` cocok saat jumlah pengulangan sudah diketahui, `while` memeriksa kondisi di awal, sedangkan `do...while` memeriksa kondisi di akhir sehingga pasti berjalan minimal satu kali [3].

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float bil1, bil2;
    float tambah, kurang, kali, bagi;

    cout << "Masukkan bilangan pertama : ";
    cin >> bil1;
    cout << "Masukkan bilangan kedua   : ";
    cin >> bil2;

    tambah = bil1 + bil2;
    kurang = bil1 - bil2;
    kali = bil1 * bil2;

    cout << endl;
    cout << "Hasil penjumlahan  : " << bil1 << " + " << bil2 << " = " << tambah << endl;
    cout << "Hasil pengurangan  : " << bil1 << " - " << bil2 << " = " << kurang << endl;
    cout << "Hasil perkalian    : " << bil1 << " * " << bil2 << " = " << kali << endl;

    if (bil2 != 0) {
        bagi = bil1 / bil2;
        cout << "Hasil pembagian    : " << bil1 << " / " << bil2 << " = " << bagi << endl;
    } else {
        cout << "Hasil pembagian    : tidak bisa dilakukan (pembagi = 0)" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-2.png)

Program ini dibuat untuk menghitung empat operasi dasar dari dua bilangan yang diinputkan user. Pertama, dideklarasikan dua variabel bertipe `float` (`bil1` dan `bil2`) untuk menyimpan bilangan, serta empat variabel `float` lain untuk menyimpan hasil. Bilangan dibaca dengan `cin`, lalu dihitung memakai operator aritmatika `+`, `-`, dan `*`, kemudian hasilnya ditampilkan dengan `cout`.

Untuk pembagian, program mengecek dulu dengan `if` apakah `bil2` tidak sama dengan 0. Kalau tidak nol, pembagian dilakukan seperti biasa. Kalau nol, program menampilkan pesan bahwa pembagian tidak bisa dilakukan, supaya program tidak error. Karena tipe datanya `float`, bilangan pecahan seperti 7.5 dan 2.5 juga bisa dihitung dengan benar.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100. Contoh: 79 : tujuh puluh sembilan

```C++
#include <iostream>
using namespace std;

int main() {
    int angka, puluhan, satuan;

    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus berada di antara 0 sampai 100!" << endl;
        return 0;
    }

    cout << angka << " : ";

    if (angka == 0) {
        cout << "nol";
    } else if (angka == 100) {
        cout << "seratus";
    } else if (angka == 10) {
        cout << "sepuluh";
    } else if (angka == 11) {
        cout << "sebelas";
    } else if (angka > 11 && angka < 20) {
        // angka belasan (12 sampai 19)
        satuan = angka % 10;
        switch (satuan) {
            case 2: cout << "dua"; break;
            case 3: cout << "tiga"; break;
            case 4: cout << "empat"; break;
            case 5: cout << "lima"; break;
            case 6: cout << "enam"; break;
            case 7: cout << "tujuh"; break;
            case 8: cout << "delapan"; break;
            case 9: cout << "sembilan"; break;
        }
        cout << " belas";
    } else {
        // angka 1-9 dan 20-99
        puluhan = angka / 10;
        satuan = angka % 10;

        if (puluhan > 0) {
            switch (puluhan) {
                case 2: cout << "dua"; break;
                case 3: cout << "tiga"; break;
                case 4: cout << "empat"; break;
                case 5: cout << "lima"; break;
                case 6: cout << "enam"; break;
                case 7: cout << "tujuh"; break;
                case 8: cout << "delapan"; break;
                case 9: cout << "sembilan"; break;
            }
            cout << " puluh";
        }

        if (satuan > 0) {
            if (puluhan > 0) {
                cout << " ";
            }
            switch (satuan) {
                case 1: cout << "satu"; break;
                case 2: cout << "dua"; break;
                case 3: cout << "tiga"; break;
                case 4: cout << "empat"; break;
                case 5: cout << "lima"; break;
                case 6: cout << "enam"; break;
                case 7: cout << "tujuh"; break;
                case 8: cout << "delapan"; break;
                case 9: cout << "sembilan"; break;
            }
        }
    }

    cout << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-2.png)

Program ini mengubah angka 0 sampai 100 menjadi tulisan bahasa Indonesia. Setelah angka dibaca dengan `cin`, program mengecek dulu apakah angkanya berada di rentang 0 sampai 100. Kalau di luar rentang, program menampilkan pesan peringatan lalu berhenti.

Setelah itu, angka dibagi menjadi beberapa kondisi memakai `if - else if`. Angka yang punya penulisan khusus ditangani sendiri, yaitu 0 (nol), 10 (sepuluh), 11 (sebelas), dan 100 (seratus). Untuk angka 12 sampai 19, program mengambil digit satuannya dengan operator `%`, menuliskan nama angkanya lewat `switch`, lalu menambahkan kata "belas".

Untuk angka selain itu (1 sampai 9 dan 20 sampai 99), angka dipisah menjadi puluhan dengan operator `/` dan satuan dengan operator `%`. Contohnya 79, puluhan = 79 / 10 = 7 dan satuan = 79 % 10 = 9. Puluhan ditulis dengan `switch` diikuti kata "puluh", lalu satuan ditulis dengan `switch` juga, sehingga hasilnya `79 : tujuh puluh sembilan`. Kalau satuannya 0 (misalnya 40), bagian satuan tidak dicetak sehingga hasilnya cukup "empat puluh".

### 3. Buatlah program yang dapat memberikan input dan output sbb. (Gambar 1.25 Mirror)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for (int i = n; i >= 0; i--) {
        // spasi di depan supaya bentuknya rata tengah
        for (int s = 0; s < n - i; s++) {
            cout << " ";
        }

        // angka menurun dari i sampai 1
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        cout << "*";

        // angka menaik dari 1 sampai i
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-2.png)

Program ini membuat pola "cermin" dari angka yang diinputkan. Kalau input-nya 3, baris pertama berisi `321*123`, baris kedua `21*12`, baris ketiga `1*1`, dan baris terakhir hanya `*`, dengan posisi yang rata tengah seperti pada gambar soal.

Cara kerjanya memakai perulangan `for` bersarang. Perulangan paling luar memakai variabel `i` yang dimulai dari `n` lalu turun sampai 0, dan setiap putarannya menghasilkan satu baris. Di dalam satu baris ada empat tahap. Pertama, perulangan `s` mencetak spasi sebanyak `n - i` supaya baris makin ke bawah makin menjorok ke kanan. Kedua, perulangan `j` yang menurun dari `i` sampai 1 mencetak sisi kiri (misalnya 3 2 1). Ketiga, program mencetak tanda `*` di tengah. Keempat, perulangan `j` yang naik dari 1 sampai `i` mencetak sisi kanan (1 2 3). Terakhir, `endl` dipakai untuk pindah baris. Pada baris terakhir ketika `i = 0`, kedua perulangan angka tidak berjalan sehingga hanya tanda `*` yang muncul.

## Kesimpulan
Dari praktikum Modul 1 ini, saya belajar cara membuat program sederhana dalam bahasa C++, mulai dari struktur program, penggunaan variabel dengan tipe data yang sesuai, sampai input dan output memakai `cin` dan `cout`. Pada soal pertama, saya memakai tipe `float` dan operator aritmatika untuk menghitung dua bilangan. Pada soal kedua, saya memakai `if-else`, `switch`, serta operator `/` dan `%` untuk mengubah angka menjadi tulisan. Pada soal ketiga, saya memakai perulangan `for` bersarang untuk membentuk pola angka. Dengan latihan ini saya jadi lebih paham bahwa program yang rumit sebenarnya tersusun dari konsep dasar yang dipakai berulang, sehingga dasar-dasar ini penting dikuasai sebelum masuk ke materi struktur data.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Modul 1 Struktur Data: Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama). Fakultas Informatika, Telkom University.

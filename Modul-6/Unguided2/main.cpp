#include "Book.h"

void tambahData(List &L, string kode, string judul, int thn) {
    infotype x;
    x.kodeBuku = kode;
    x.judul = judul;
    x.thnTerbit = thn;
    insertLast(L, alokasi(x));
}

int main() {
    List L;
    CreateList(L);

    tambahData(L, "B001", "Algoritma", 2020);
    tambahData(L, "B003", "Struktur_Data", 2018);
    tambahData(L, "B004", "Jaringan_Komputer", 2022);

    infotype x;
    cout << "Masukkan Kode Buku yang dicari : ";
    cin >> x.kodeBuku;
    cout << endl;

    address P = findElm(L, x);
    if (P != NULL) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}
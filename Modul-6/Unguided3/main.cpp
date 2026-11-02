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
    cout << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> x.kodeBuku;

    address P = findElm(L, x);
    if (P == NULL) {
        cout << "Data tidak ditemukan." << endl;
    } else {
        address Q;
        if (P == L.First) {
            deleteFirst(L, Q);
        } else if (P == L.Last) {
            deleteLast(L, Q);
        } else {
            deleteAfter(P->prev, Q);
        }
        dealokasi(Q);
        cout << "Data dengan kode buku " << x.kodeBuku << " berhasil dihapus." << endl;
    }

    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
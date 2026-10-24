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
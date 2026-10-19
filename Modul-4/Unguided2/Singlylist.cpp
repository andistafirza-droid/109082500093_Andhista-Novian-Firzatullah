
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

void deleteFirst(List *L) {
    if (L->first != NULL) {
        address P = L->first;
        L->first = P->next;
        dealokasi(P);
    }
}

void deleteLast(List *L) {
    if (L->first == NULL) {
        return;
    }

    if (L->first->next == NULL) {
        deleteFirst(L);
        return;
    }

    address P = L->first;

    while (P->next->next != NULL) {
        P = P->next;
    }

    address Q = P->next;
    P->next = NULL;
    dealokasi(Q);
}

void deleteAfter(List *L, address prec) {
    if (prec != NULL && prec->next != NULL) {
        address P = prec->next;
        prec->next = P->next;
        dealokasi(P);
    }
}

int jumlahList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != NULL) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List *L) {
    while (L->first != NULL) {
        deleteFirst(L);
    }
}

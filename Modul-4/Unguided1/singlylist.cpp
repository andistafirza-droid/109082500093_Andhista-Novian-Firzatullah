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
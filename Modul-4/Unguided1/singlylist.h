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
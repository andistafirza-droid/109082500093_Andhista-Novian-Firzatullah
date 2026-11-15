#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

#define MAX_STACK 20

typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];   /* array [20] of integer */
    int top;                    /* indeks elemen teratas, -1 jika kosong */
};

void createStack(Stack &S);
/* I.S. sembarang
   F.S. terbentuk stack kosong dengan top = -1 */

bool isEmpty(Stack S);
/* mengembalikan true jika stack kosong */

bool isFull(Stack S);
/* mengembalikan true jika stack penuh (top = 19) */

void push(Stack &S, infotype x);
/* I.S. stack mungkin kosong, belum penuh
   F.S. x menjadi elemen teratas, top = top + 1 */

infotype pop(Stack &S);
/* I.S. stack tidak kosong
   F.S. top = top - 1, mengembalikan nilai elemen yang diambil */

void printInfo(Stack S);
/* I.S. stack mungkin kosong
   F.S. menampilkan isi stack dari TOP ke dasar */

void balikStack(Stack &S);
/* I.S. stack mungkin kosong
   F.S. urutan isi stack terbalik */

void pushAscending(Stack &S, infotype x);
/* I.S. stack sudah terurut menaik (dasar -> top)
   F.S. x disisipkan sehingga stack tetap terurut menaik dari dasar ke top */

#endif // STACK_H_INCLUDED
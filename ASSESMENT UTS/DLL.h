#ifndef DLL_H
#define DLL_H
#include <iostream>
#include <stdlib.h>

#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define NIL NULL

using namespace std;

//deklarasi struct infotype
struct Post {
    int id;
    string konten;
    int like;
    string username;
};
typedef Post infotype;

//deklarasi struct linked list
typedef struct elmList *address;
struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

//deklarasi subprogram
address createElement(infotype data);
List createNewList();
bool isEmpty(List a);
void insertFirst(List &a, address p);
void insertAfter(List &a, infotype x, address p);
void insertLast(List &a, address p);
void deleteFirst(List &a, address p);
void deleteLast(List &a, address p);
int length(List a);
address findElement(List a, infotype x);
void printList(List a);

//deklarasi subprogram split list
void splitList(List a);
#endif
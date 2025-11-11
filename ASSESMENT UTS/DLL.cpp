#include "DLL.h"

address createElement(infotype data){
    address p = new elmList;
    info(p) = data;
    next(p) = NIL;
    prev(p) = NIL;
    return p;
}

List createNewList(){
    List L;
    first(L) = NIL;
    last(L) = NIL;
    return L;
}

bool isEmpty (List a){
   return first(a) == NIL && last(a) == NIL;
}

//silahkan uncomment untuk NIM ganjil
//void insertFirst (List &a, address p){
//    ...
//}

//silahkan uncomment untuk NIM genap
void insertLast(List &a, address p){
    if (isEmpty(a)) {
        first(a) = p;
        last(a) = p;
    } else {
        next(last(a)) = p;
        prev(p) = last(a);
        last(a) = p;
    }
}

void insertAfter(List &a, infotype x, address p){
    //tidak wajib diisi
}

void deleteFirst(List &a, address p){
    if (isEmpty(a)) {
        cout << "list kosong" << endl;
    } else if (first(a) != last(a)){
        p = first(a);
        first(a) = next(p);
        prev(first(a)) = NIL;
        next(p) = NIL;
    } else { //tinggal 1 elemen
        p = first(a);
        first(a) = NIL;
        last(a) = NIL;
        next(p) = NIL;
        prev(p) = NIL;
    }
}

void deleteLast(List &a, address p){
    if (isEmpty(a)) {
        cout << "list kosong" << endl;
    } else if (next(first(a))==NIL){
        p = first(a);
        first(a) = NIL;
        last(a) = NIL;
        next(p) = NIL;
        prev(p) = NIL;
    }else{
        p = last(a);
        last(a) = prev(p);
        prev(p) = NIL;
        next(last(a)) = NIL;
    }

}

int length(List a) {
    int jml = 1;
    address p = first(a);
    if(p == NIL){
       return 0;
    }else {
       while(p != last(a)){
           jml++;
           p = next(p);
       }
       return jml;
    }
}

address findElement (List a, infotype x) {
    address Q;
    if (isEmpty(a)){
        return NIL;
    }else {
        Q = first(a);
        while(Q != NIL && info(Q).id != x.id) {
            Q = next(Q);
        }

        if (Q == NIL){
            return NIL;
        }else
            return Q;
    }
}

void printList(List a){
    if (isEmpty(a)) {
        cout << "List kosong" << endl;
    } else {
        address p = first(a);
        cout << "===== TIMELINE MY TELU =====" << endl;
        while (p != NIL) {
            cout << "ID Post: " << info(p).id << endl;
            cout << "User   : " << info(p).username << endl;
            cout << "Konten : " << info(p).konten << endl;
            cout << "Likes  : " << info(p).like << endl;
            cout << "-----------------------------" << endl;
            p = next(p);
        }
    }
}

//buatlah subprogram splitlist
void splitList(List a){
    //contoh: membagi list jadi dua berdasarkan like > 50
    List populer = createNewList();
    List biasa = createNewList();

    address p = first(a);
    while (p != NIL) {
        if (info(p).like > 50) {
            insertLast(populer, createElement(info(p)));
        } else {
            insertLast(biasa, createElement(info(p)));
        }
        p = next(p);
    }

    cout << "\nPost Populer (>50 like):\n";
    printList(populer);
    cout << "\nPost Biasa (<=50 like):\n";
    printList(biasa);
}

// ✅ Subprogram tambahan sesuai soal:
void insertAscending(List &L, infotype data){
    address p = createElement(data);
    if (isEmpty(L)) {
        insertLast(L, p);
    } else if (info(first(L)).id > data.id) {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    } else {
        address q = first(L);
        while (next(q) != NIL && info(next(q)).id < data.id) {
            q = next(q);
        }
        next(p) = next(q);
        if (next(q) != NIL) prev(next(q)) = p;
        next(q) = p;
        prev(p) = q;
        if (next(p) == NIL) last(L) = p;
    }
}

void showByUsername(List L, string uname){
    address p = first(L);
    bool found = false;
    while (p != NIL) {
        if (info(p).username == uname) {
            cout << "ID: " << info(p).id << " | " << info(p).konten 
                 << " (" << info(p).like << " likes)" << endl;
            found = true;
        }
        p = next(p);
    }
    if (!found) cout << "Tidak ada postingan dari user tersebut.\n";
}

void showPopularPost(List L){
    if (isEmpty(L)) {
        cout << "List kosong" << endl;
        return;
    }
    address p = first(L);
    address max = p;
    while (p != NIL) {
        if (info(p).like > info(max).like) {
            max = p;
        }
        p = next(p);
    }
    cout << "\n=== Post Terpopuler ===" << endl;
    cout << "ID: " << info(max).id << endl;
    cout << "User: " << info(max).username << endl;
    cout << "Konten: " << info(max).konten << endl;
    cout << "Likes: " << info(max).like << endl;
}

void updateLike(List &L, int id, bool like){
    infotype temp;
    temp.id = id;
    address p = findElement(L, temp);
    if (p == NIL) {
        cout << "Post tidak ditemukan.\n";
    } else {
        if (like) info(p).like++;
        else if (info(p).like > 0) info(p).like--;
    }
}

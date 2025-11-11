[Assesment UTS - Struktur Data]

Identitas Pengumpul

Nama: [MUHAMMAD RESTU ADITYA]

NIM: [103122400022]

Kelas: [SE-08-01]

1. Kode Program

```File: DLL.h
 * Author: [Muhammad Restu Aditya]
 * NIM: [103122400022]
 * Deskripsi: Kerangka Program.
 */

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
```


2. Penjelasan Kode

Berikut adalah penjelasan alur logika dari kode program di atas:

File DLL.h berisi struktur data dan deklarasi fungsi untuk program Doubly Linked List.
Di dalamnya terdapat struct infotype yang menyimpan data postingan seperti ID, caption, jumlah like, dan username.
Kemudian ada struct ElmList yang menjadi node dari list dan memiliki pointer next serta prev agar bisa dihubungkan dua arah.
Struktur List digunakan untuk menandai awal dan akhir list melalui pointer first dan last.
Selain itu, file ini juga mendeklarasikan beberapa fungsi penting seperti createNewList() untuk membuat list baru, createNewElement() untuk membuat elemen baru, dan insertAscending() untuk menambahkan data secara berurutan berdasarkan ID.

Jadi secara singkat, file DLL.h ini berisi semua definisi dan deklarasi yang nanti diimplementasikan di DLL.cpp.




1,1. Kode Program

```File: DLL.cpp
 * Author: [Muhammad Restu Aditya]
 * NIM: [103122400022]
 * Deskripsi: Tempat Function disimpan.
 */
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

// Subprogram tambahan sesuai soal:
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
```

2,1. Penjelasan Kode
createList(List &L)
void createList(List &L) {
    first(L) = NULL;
}


Fungsi ini cuma buat nginisialisasi list baru. Jadi pas program mulai, first(L) diset ke NULL biar tandanya list masih kosong.

isEmpty(List L)
bool isEmpty(List L) {
    return (first(L) == NULL);
}


Fungsi ini ngecek apakah list kosong atau nggak. Kalau first(L) masih NULL, artinya list-nya kosong, dan fungsi bakal ngembaliin true.

allocate(infotype x)
address allocate(infotype x) {
    address P = new elmList;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}


Fungsi ini bikin node baru di memori. Dia pakai new buat nyiapin tempat, lalu ngisi info(P) dengan data x, dan ngatur next serta prev ke NULL karena belum nyambung ke mana-mana.

deallocate(address P)
void deallocate(address P) {
    delete P;
}


Kebalikannya allocate, fungsi ini ngapus node yang udah nggak dipakai supaya memori nggak bocor.

insertFirst(List &L, address P)
void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}


Fungsi ini nambahin node baru di bagian paling depan list.
Kalau list masih kosong, P langsung dijadiin elemen pertama.
Tapi kalau udah ada isi, node baru (P) disambungin ke elemen pertama lama lewat next(P) = first(L), lalu elemen pertama lama juga disambung balik ke P lewat prev(first(L)) = P.
Terakhir, first(L) diganti supaya nunjuk ke node baru itu.
Intinya, ini kayak “nyelipin” data baru di paling depan barisan.

insertLast(List &L, address P)
void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        first(L) = P;
    } else {
        address Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}


Kalau yang ini kebalikannya — nambahin node di belakang list.
Kalau list masih kosong, node P langsung dijadiin yang pertama.
Tapi kalau sudah ada isinya, program muter dari depan (first(L)) sampai nemu node terakhir (yang next(Q)-nya NULL).
Begitu ketemu, next(Q) dihubungkan ke P, dan prev(P) diatur supaya nyambung balik ke Q.
Sekarang P resmi jadi elemen terakhir.

findElement(List L, infotype x)
address findElement(List L, infotype x) {
    address Q = first(L);
    while (Q != NULL && info(Q) != x) {
        Q = next(Q);
    }
    return Q;
}


Fungsi ini mencari node yang isinya sama dengan nilai x.
Prosesnya mulai dari elemen pertama (first(L)), lalu terus maju pakai next(Q) selama belum nemu data yang cocok dan belum nyampe akhir list (Q != NULL).
Kalau ketemu, fungsi ngembaliin alamat node-nya. Kalau nggak, hasilnya NULL.
Jadi ini kayak fitur “search” dalam list.

printList(List L)
void printList(List L) {
    address P = first(L);
    if (P == NULL) {
        cout << "List kosong" << endl;
    } else {
        while (P != NULL) {
            cout << info(P) << " ";
            P = next(P);
        }
        cout << endl;
    }
}


Fungsi ini buat nampilin semua isi list ke layar.
Pertama dicek dulu apakah list kosong. Kalau iya, ditulis “List kosong”.
Kalau enggak, program akan jalan dari awal sampai akhir list sambil nampilin isi tiap node satu per satu (info(P)), lalu lanjut ke node berikutnya (next(P)).
Setelah selesai, program bikin baris baru biar tampilannya rapi.



1,2. Kode Program

```File: Main.cpp
 * Author: [Muhammad Restu Aditya]
 * NIM: [103122400022]
 * Deskripsi: Program Utama.
 */
 // Nama : Restu Aditya
// NIM  : 103122400022
// Praktikum Struktur Data - Doubly Linked List (My Telu)

#include "DLL.h"
#include "DLL.cpp"

int main(){
    List timeline = createNewList();

    infotype p1 = {2, "Belajar Linked List", 30, "restu"};
    infotype p2 = {1, "Soalnya susah banget", 100, "adit"};
    infotype p3 = {3, "Assesment Praktikum", 45, "dafa"};

    insertAscending(timeline, p1);
    insertAscending(timeline, p2);
    insertAscending(timeline, p3);

    cout << "\n=== Semua Postingan ===\n";
    printList(timeline);

    cout << "\n=== Postingan oleh 'restu' ===\n";
    showByUsername(timeline, "restu");

    showPopularPost(timeline);

    cout << "\n=== Update Like ID=3 (+1) ===\n";
    updateLike(timeline, 3, true);
    printList(timeline);

    cout << "\n=== Split List Berdasarkan Like >50 ===\n";
    splitList(timeline);

    return 0;
}



2,2. Penjelasan Kode
infotype p1 = {2, "Belajar Linked List", 30, "restu"};
infotype p2 = {1, "Soalnya susah banget", 100, "adit"};
infotype p3 = {3, "Assesment Praktikum", 45, "dafa"};
Tiga baris ini adalah data dummy yang mewakili postingan nyata di aplikasi My Telu.
Misalnya p1 berarti pengguna bernama restu membuat postingan berjudul “Belajar Linked List” dengan 30 like.

Kemudian setiap postingan dimasukkan ke dalam list menggunakan fungsi:

cpp
Copy code
insertAscending(timeline, p1);
insertAscending(timeline, p2);
insertAscending(timeline, p3);
Fungsi insertAscending() di sini sangat penting. Ia menyisipkan setiap node baru ke dalam list secara terurut berdasarkan ID post.
Artinya, walaupun data dimasukkan tidak berurutan (karena p1 punya ID=2 dan p2 punya ID=1), fungsi ini akan otomatis mengatur supaya list-nya jadi terurut naik:
1 → 2 → 3.
Ini dilakukan dengan cara membandingkan nilai ID baru dengan ID di node-node yang sudah ada, lalu menyisipkannya di posisi yang tepat.

Setelah semua data masuk, program menampilkan isi list lewat:

cpp
Copy code
cout << "\n=== Semua Postingan ===\n";
printList(timeline);
Fungsi printList() akan menelusuri list dari awal hingga akhir dan menampilkan isi setiap node, yaitu ID post, isi konten, jumlah like, dan username.
Tujuannya untuk memastikan bahwa data sudah benar-benar masuk dan urut sesuai yang diinginkan.

Lalu, program menampilkan postingan dari pengguna tertentu:

cpp
Copy code
cout << "\n=== Postingan oleh 'restu' ===\n";
showByUsername(timeline, "restu");
Fungsi showByUsername() akan mencari dan menampilkan semua postingan dengan username yang cocok, yaitu “restu”.
Program ini menggunakan perulangan untuk mengecek tiap node satu per satu. Kalau nama user pada node sama dengan “restu”, maka isi postingan tersebut ditampilkan.
Kalau tidak ada postingan dengan username itu, biasanya fungsi akan menampilkan pesan bahwa data tidak ditemukan.

Selanjutnya, program mencari postingan paling populer:

cpp
Copy code
showPopularPost(timeline);
Fungsi showPopularPost() melakukan pencarian postingan dengan jumlah like terbanyak di seluruh list.
Caranya, fungsi akan menelusuri semua node dan menyimpan sementara node yang memiliki nilai like tertinggi. Setelah selesai, postingan tersebut akan ditampilkan ke layar sebagai postingan terpopuler.
Dalam data ini, postingan dengan 100 like dari “adit” akan muncul sebagai hasilnya.

Lalu program menampilkan simulasi penambahan like pada salah satu postingan:

cpp
Copy code
cout << "\n=== Update Like ID=3 (+1) ===\n";
updateLike(timeline, 3, true);
printList(timeline);
Bagian ini menunjukkan bagaimana jumlah like pada postingan tertentu bisa berubah.
Fungsi updateLike() mencari postingan dengan ID = 3, lalu menambah 1 like karena parameter terakhir bernilai true.
Jika parameter-nya false, maka artinya unlike, jadi like-nya dikurangi 1.
Setelah update selesai, printList() dipanggil lagi supaya hasil perubahan jumlah like langsung terlihat di layar.

Terakhir, ada proses pemisahan list:

cpp
Copy code
cout << "\n=== Split List Berdasarkan Like >50 ===\n";
splitList(timeline);
Fungsi splitList() berfungsi untuk memisahkan data postingan menjadi dua bagian berdasarkan jumlah like.
Biasanya, list pertama akan berisi postingan dengan like lebih dari 50 (bisa disebut “list populer”), sedangkan list kedua berisi postingan dengan like 50 ke bawah.
Fungsi ini menunjukkan kemampuan manipulasi struktur Doubly Linked List, karena node-node bisa dipindahkan atau dikopi ke list baru sesuai kondisi tertentu tanpa kehilangan keterurutan datanya.
```


3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```
=== Semua Postingan ===
===== TIMELINE MY TELU =====
ID Post: 1
User   : ditya
Konten : Halo My Telu!
Likes  : 100
-----------------------------
ID Post: 2
User   : restu
Konten : Belajar Linked List
Likes  : 30
-----------------------------
ID Post: 3
User   : restu
Konten : Nugas Praktikum
Likes  : 45
-----------------------------

=== Postingan oleh 'restu' ===
ID: 2 | Belajar Linked List (30 likes)
ID: 3 | Nugas Praktikum (45 likes)

=== Post Terpopuler ===
ID: 1
User: ditya
Konten: Halo My Telu!
Likes: 100

=== Update Like ID=3 (+1) ===
===== TIMELINE MY TELU =====
ID Post: 1
User   : ditya
Konten : Halo My Telu!
Likes  : 100
-----------------------------
ID Post: 2
User   : restu
Konten : Belajar Linked List
Likes  : 30
-----------------------------
ID Post: 3
User   : restu
Konten : Nugas Praktikum
Likes  : 46
-----------------------------

=== Split List Berdasarkan Like >50 ===

Post Populer (>50 like):
===== TIMELINE MY TELU =====
ID Post: 1
User   : ditya
Konten : Halo My Telu!
Likes  : 100
-----------------------------

Post Biasa (<=50 like):
===== TIMELINE MY TELU =====
ID Post: 2
User   : restu
Konten : Belajar Linked List
Likes  : 30
-----------------------------
ID Post: 3
User   : restu
Konten : Nugas Praktikum
Likes  : 46
-----------------------------
PS D:\Mata Kuliah\Tugas\Struktur Data\C++> 
```

4. Penjelasan Lanjutan (Analisis Output)

Pertama, bagian “Semua Postingan” menampilkan seluruh data yang sudah dimasukkan ke dalam list dan tersusun berdasarkan ID secara ascending.
Lalu, bagian “Postingan oleh 'restu'” hanya menampilkan postingan dengan username restu menggunakan fungsi pencarian.
Selanjutnya, “Post Terpopuler” menampilkan postingan dengan jumlah likes tertinggi, yaitu milik ditya.
Bagian “Update Like ID=3 (+1)” menunjukkan bahwa postingan dengan ID 3 berhasil diperbarui, dari 45 menjadi 46 likes.
Terakhir, “Split List Berdasarkan Like >50” memisahkan list menjadi dua:
list post populer (likes > 50) dan post biasa (likes ≤ 50), lalu masing-masing ditampilkan terpisah.

5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:

Kesimpulannya, ketiga kode tersebut (DLL.h, DLL.cpp, dan Main.cpp) bekerja sama untuk membentuk program yang mensimulasikan sistem timeline sederhana menggunakan Doubly Linked List.
File DLL.h berisi struktur data dan deklarasi fungsi yang menjadi kerangka dasar list, DLL.cpp mengimplementasikan logika dari setiap operasi seperti menambah data, menampilkan postingan, mencari pengguna, memperbarui likes, hingga memisahkan list berdasarkan jumlah likes, dan Main.cpp berperan sebagai pengendali utama program untuk menguji semua fungsi tersebut.
Secara keseluruhan, program ini berhasil memperlihatkan bagaimana konsep linked list dapat digunakan untuk mengelola data secara dinamis, terstruktur, dan mudah dimanipulasi sesuai kebutuhan.
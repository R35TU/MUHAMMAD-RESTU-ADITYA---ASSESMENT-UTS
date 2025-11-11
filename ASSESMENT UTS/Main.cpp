// Nama : Restu Aditya
// NIM  : 103122400022
// Praktikum Struktur Data - Doubly Linked List (My Telu)

#include "DLL.h"
#include "DLL.cpp"

int main(){
    List timeline = createNewList();

    infotype p1 = {2, "Belajar Linked List", 30, "restu"};
    infotype p2 = {1, "Halo My Telu!", 100, "ditya"};
    infotype p3 = {3, "Nugas Praktikum", 45, "restu"};

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

#include "ui.h"
// Diperbolehkan membuat fungsi antara jikaK dibutuhkan!

void dealokasiList(List *l) {
    Address p_current = FIRST(*l); // Dapatkan pointer ke elemen pertama
    Address p_next;

    while (p_current != NULL) {
        p_next = NEXT(p_current); // Simpan pointer ke elemen berikutnya
        free(p_current);          // Bebaskan memori elemen saat ini
        p_current = p_next;       // Pindah ke elemen berikutnya
    }

    *l = NULL; // Setelah semua node dibebaskan, set pointer list utama ke NULL
}

void insertSorted(List *l, ElType val) {
    Address p;
    p = *l;

    while (p != NULL){
        
    }
}

List getUnion(List l1, List l2){
    // your implementation
}

List getIntersect(List l1, List l2){
    // your implementation
}

void getData(List *Union, List *Irisan){
    // your implementation
}
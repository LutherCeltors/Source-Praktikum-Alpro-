#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>


#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }else{
	    printf("Gagal melakukan alokasi");
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address List;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    (*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim TRUE jika list kosong */
{
    if (l == NULL) return TRUE;
    else return FALSE;
}
/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    Address p = l;
    int count = 0;
    boolean found = FALSE;
    while (p != NULL && !(found)){
        if (count < idx ){
            p = p->next;
            count++;
        }else{
            found = TRUE;
        }
    }
    return p->info;
}
void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    Address p = (*l);
    int count = 0;
    while (count < idx ){
        p = p->next;
        count++;
    }
    p->info = val;
} 
int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    Address p = l;
    int count = 0;
    boolean found = FALSE;
    while (p != NULL && !(found)){
        if (INFO(p) != val){
            p = NEXT(p);
            count++;
        }else{
            found = TRUE;
        }
    }
    if (found) return count;
    else return IDX_UNDEF;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address add = newNode(val);
    if (add != NULL){
        add->next = (*l); 
        (*l) = add;
    }
}
void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address add = newNode(val);
    if (add != NULL){
        Address p = (*l);
        Address prev = NULL;
        while (p != NULL){
        prev = p;
        p = p->next;
        }
        if (prev == NULL){
            insertFirst(l, val);
        }else{
            prev->next = add;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address add = newNode(val);
    if (add != NULL){
        Address p = (*l);
        Address prev = NULL;
        int count = 0;
        boolean found = FALSE;
        while (p != NULL && !(found)){
            if (count < idx ){
                prev = p;
                p = p->next;
                count++;
            }else{
                found = TRUE;
            }
        }
        if (prev == NULL){
            insertFirst(l, val);   
        }else if (idx == length(*l)) insertLast(l, val);
        else{
            add->next = prev->next;
            prev->next = add;
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    if(length(*l) == 0) return;
    Address p = (*l);
    (*val) = INFO(p);
    (*l) = NEXT(p);   
    free(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    if (length(*l) == 0) return;
    Address p = (*l);
    Address prev = NULL;
    while (NEXT(p) != NULL){
      prev = p;
      p = p->next;
    }
    (*val) = INFO(p);
    if (prev != NULL)prev->next = NULL;
    else (*l) = NULL;
    free(p); 
} 
void deleteAt(List *l, int idx, ElType *val) 
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    Address p = (*l);
    Address prev = NULL;
    int count = 0;
    boolean found = FALSE;
    while (p != NULL && !(found)){
        if (count < idx ){
            prev = p;
            p = p->next;
            count++;
        }else{
            found = TRUE;
        }
    }
    if (prev == NULL) {
        deleteFirst(l, val);
    }
    else{
        prev->next = p->next;
        (*val) = p->info;
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    Address p = (l);
    printf("[");
    while (p != NULL){
        printf("%d", p->info);
        p = p->next;
        if (p != NULL){
            printf(",");
        }
    }
    printf("]");
}
int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    Address p = l;
    int count = 0;
    while (p != NULL){
        count++;
        p = p->next;
    }
    return count;
}
/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    Address l3;
    CreateList(&l3);
    Address p1 = l1;
    Address prev1 = NULL;
    while (p1 != NULL){
      prev1 = p1;
      p1 = p1->next;
    }
    if(prev1 == NULL){
	    l3 = l2;
    }else{
	    l3 = l1;
        prev1->next = l2;
    }
    return l3;

    CreateList(&l1);
    CreateList(&l2);
}

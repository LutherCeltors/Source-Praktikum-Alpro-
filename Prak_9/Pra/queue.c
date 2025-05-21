#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}
/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim TRUE jika q kosong: lihat definisi di atas */
{
    if (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF) return TRUE;
    else return FALSE;
}   
boolean isFull(Queue q)
/* Mengirim TRUE jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    if (length(q) == CAPACITY) return TRUE;
    else return FALSE;
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (q.idxHead == q.idxTail && q.idxHead == IDX_UNDEF) return 0;
    else if (q.idxHead > q.idxTail){
        return (CAPACITY - q.idxHead + q.idxTail + 1);
    }else if (q.idxHead < q.idxTail){
        return(IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }else if (q.idxHead == q.idxTail){
        return 1;
    };
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh. Jangan lakukan apapun apabila penampung penuh. */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    if (isEmpty(*q)) {
        q->idxHead = 0;
        q->idxTail = 0;
        q->buffer[IDX_HEAD(*q)] = val;
    }
    else if (length(*q) < CAPACITY && !isFull(*q))
    {
        q->idxTail = (IDX_TAIL(*q) + 1) % CAPACITY;
        q->buffer[IDX_TAIL(*q)] = val; 
    }
}

void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, jangan lakukan apa-apa bila kosong*/
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "if ";
        q mungkin kosong */
{
    if (IDX_HEAD(*q) != IDX_TAIL(*q)){
        (*val) = HEAD(*q);
        q->idxHead = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
    else if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        (*val) = HEAD(*q);
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang setiap elemen queue, termasuk spasi dan enter */
/* Tambahkan \n ketika Queue sudah selesai di tulis */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    printf("[");
    int i = q.idxHead;
    int count = 0;
    if (!isEmpty(q)){
        for (;;){
            printf("%d", q.buffer[i]);
            if (i != q.idxTail) printf(",");
            else break;
            i = (i + 1) % CAPACITY;
        }
    }
    printf("]\n");
}


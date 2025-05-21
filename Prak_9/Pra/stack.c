#include "stack.h"
#include <stdio.h>

void CreateEmpty(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    S->TOP = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
/* Mengirim False jika Stack kosong: lihat definisi di atas */
{
    if (Top(S) == Nil) return true;
    else return false;
}
boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    if (Top(S) == MaxEl - 1) return true;
    else return false;
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsFull(*S) == false){
        Top(*S)++;
        InfoTop(*S) = X;
    }
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = InfoTop(*S);
    S->TOP -= 1;
}

// int main (){
//     Stack s;
//     int X;
//     CreateEmpty(&s);
//     scanf("%d", &X);
//     Push(&s, X);
//     printf("Top : %d", s.TOP);
//     printf("[");
//     for (int i = s.TOP; i >= 0; i--){
//         printf("%d", s.T[i]);
//         if (i != 0) printf(",");
//     }
//     printf("]\n");
//     scanf("%d", &X);
//     Push(&s, X);
//     printf("Top : %d", s.TOP);
//     printf("[");
//     for (int i = s.TOP; i >= 0; i--){
//         printf("%d", s.T[i]);
//         if (i != 0) printf(",");
//     }
//     printf("]\n");
//     Pop(&s, &X);
//     printf("[");
//     for (int i = s.TOP; i >= 0; i--){
//         printf("%d", s.T[i]);
//         if (i != 0) printf(",");
//     }
//     printf("]\n");
//     printf("Pop : %d\n", X);
//     printf("[");
//     for (int i = s.TOP; i >= 0; i--){
//         printf("%d", s.T[i]);
//         if (i != 0) printf(",");
//     }
//     printf("]\n");
// }

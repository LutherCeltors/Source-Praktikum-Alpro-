#include "listkontigu.h"
// /* List Kontigu varian alt-1b */
// typedef struct {
//     ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
// } ListKontigu;

/* ********** SELEKTOR FISIK ********** */
#define ELMT(l, i) (l).contents[(i)]
/* Macro ELMT digunakan untuk mengakses elemen pada indeks FISIK i dari array. */
/* Perhatian: Indeks fisik i belum tentu sama dengan indeks logis elemen list. */
/* Gunakan fungsi getElmt/setElmt untuk akses berdasarkan indeks logis. */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong */
void CreateList(ListKontigu *l)
/* I.S. l sembarang */
/* F.S. Terbentuk ListKontigu l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen fisik ListKontigu l dengan MARK */
{
    for (int i = 0; i < CAPACITY; i++){
        l->contents[i] = MARK;
    }
}
/* ********** SELEKTOR  ********** */

/* *** Pencari Indeks Fisik Batas Efektif *** */
int firstIdx(ListKontigu l)
/* Prekondisi : List l boleh kosong */
/* Mengirimkan indeks fisik elemen valid pertama dalam list l, */
/* atau IDX_UNDEF jika l kosong */
{
    int i = 0;
    while (i < CAPACITY && l.contents[i] == MARK){
        i += 1;
    }
    if (i = 0){
        return IDX_UNDEF;
    }
    return i;
}
int lastIdx(ListKontigu l)
/* Prekondisi : List l boleh kosong */
/* Mengirimkan indeks fisik elemen valid terakhir dalam list l, */
/* atau IDX_UNDEF jika l kosong */
{
    int i = CAPACITY - 1;
    while ( i >= 0 && l.contents[i] == MARK){
        i -= 1;
    }
    if (i == CAPACITY - 1){
        return IDX_UNDEF;
    }
    return i;
}
/* *** Banyaknya elemen *** */
int listLength(ListKontigu l)
/* Mengirimkan banyaknya elemen efektif ListKontigu */
/* Mengirimkan nol jika List kosong */
{
    if (lastIdx(l) == IDX_UNDEF && firstIdx(l) == IDX_UNDEF){
        return lastIdx(l) - firstIdx(l) + 1;
    }else{
        return 0;
    }
}
ElType getElmt(ListKontigu l, int i)
/* Prekondisi : List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* Mengirimkan elemen List yang ke-i (indeks logis) */
{
    return ELMT(l, i);
}
/* *** Mengubah elemen berdasarkan indeks logis *** */
void setElmt(ListKontigu *l, int i, ElType val)
/* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* F.S. Elemen List yang ke-i secara logis bernilai val */
{
    l->contents[i] = val;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(int i)
/* Mengirimkan true jika i adalah indeks fisik yang valid untuk array  */
/* yaitu antara IDX_MIN dan CAPACITY-1 */
{
    if (i >= IDX_MIN && i < CAPACITY){
        return true;
    }else return false;
}
boolean isIdxEff(ListKontigu l, int i)
/* Mengirimkan true jika i adalah indeks fisik yang efektif (valid secara fisik */
/* dan merupakan bagian dari elemen list yang valid). */
/* yaitu i >= firstIdx(l) dan i <= lastIdx(l). */
/* Mengembalikan false jika l kosong. */
{
    if (i >= firstIdx(l) && i <= lastIdx(l)) return true;
    else return 0;
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListKontigu l)
/* Mengirimkan true jika List l kosong (tidak memiliki elemen efektif) */
{
    if (listLength == 0){
        return true;
    }else return false;
}

/* *** Test List penuh *** */
boolean isFull(ListKontigu l)
/* Mengirimkan true jika List l penuh (jumlah elemen efektif == CAPACITY) */
{
    if (CAPACITY == listLength(l)){
        return true;
    }else return false;
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListKontigu *l)
/* I.S. l sembarang */
/* F.S. ListKontigu l terdefinisi  */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya secara kontigu dalam list, seluruh elemen fisik lain di luar blok efektif di-set MARK.  */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
    int N;
    do{
        scanf("%d", &N);
    }while (N < 0 || N > CAPACITY);

    if (N == 0){
        CreateList(l);
    }else{
        for (int i = 0; i < CAPACITY; i++){
            scanf("%d", &l->contents[i]);
        }
    }
}
void printList(ListKontigu l)
/* Proses : Menuliskan isi list efektif dengan traversal. */
/* List ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma". */
/* Tanpa tambahan karakter di depan, di tengah, atau di belakang. */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] (e adalah elemen pada indeks logis) */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    printf("[");
    for (int i = firstIdx(l); i < listLength(l); i++){
        prinf("%d", l.contents[i]);
        if (i != listLength(l) - 1){
            printf(",");
        }
    }
    printf("]\n");
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListKontigu l1, ListKontigu l2)
/* Mengirimkan true jika l1 sama dengan l2 */
/* yaitu jika panjangnya sama dan elemen pada indeks logis yang sama juga sama */
{
    if (listLength(l1) == listLength(l2)){
        for (int i = firstIdx(l1) ; i < listLength(l1); i ++){
            if (l1.contents[i] != l2.contents[i]) return false;
        }
    }else{
        return false;
    }
}
/* ********** SEARCHING ********** */
/* *** Mencari elemen berdasarkan nilai *** */
int indexOf(ListKontigu l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks LOGIS (0..length-1) elemen pertama yang bernilai val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
{
    int i = firstIdx(l);
    while (i <= lastIdx(l)){
        if (l.contents[i] == val){
            return i;
        }else{
            i += 1;
        }
    }return IDX_UNDEF;
}

/* ********** OPERASI LAIN ********** */
void copyList(ListKontigu lIn, ListKontigu *lOut)
/* I.S. lIn terdefinisi, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (elemen efektif disalin, */
/*      dimulai dari indeks fisik 0 di lOut, sisanya MARK). */
{
    CreateList(lOut);
    for (int i = firstIdx(lIn); i <= lastIdx(lIn); i++){
        lOut->contents[i] = lIn.contents[i];
    }
}

void shiftBlock(ListKontigu *l, int startPhys, int endPhys, int delta)
/* I.S. List l terdefinisi, ada cukup ruang MARK di arah pergeseran */
/* F.S. Elemen fisik dari startPhys hingga endPhys digeser ke kanan (delta > 0) */
/* atau ke kiri (delta < 0), elemen yang kosong dijadikan MARK. */
{
    
}
/* ********** PENAMBAHAN ELEMEN ********** */
/* *** Menambahkan elemen berdasarkan nilai *** */
void insertFirst(ListKontigu *l, ElType val);
/* Menambahkan val sebagai elemen pertama List l (indeks logis 0) */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val menjadi elemen pertama l, list mungkin bergeser secara fisik. */
/* Proses:
   1. Jika list kosong, tempatkan val di indeks fisik 0.
   2. Jika tidak kosong dan ada ruang di indeks fisik firstIdx(l)-1, tempatkan val di sana.
   3. Jika tidak kosong dan tidak ada ruang di kiri (firstIdx=0) tapi ada ruang di kanan,
      geser semua elemen efektif [firstIdx..lastIdx] ke kanan satu posisi,
      lalu tempatkan val di firstIdx fisik yang lama. */

void insertLast(ListKontigu *l, ElType val);
/* Menambahkan val sebagai elemen terakhir List l (indeks logis length) */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val menjadi elemen terakhir l, list mungkin bergeser secara fisik. */
/* Proses: Mirip insertFirst, tapi di ujung kanan (lastIdx).
   1. Jika list kosong, tempatkan val di indeks fisik 0.
   2. Jika tidak kosong dan ada ruang di indeks fisik lastIdx(l)+1, tempatkan val di sana.
   3. Jika tidak kosong dan tidak ada ruang di kanan  tapi ada ruang di kiri,
      geser semua elemen efektif [firstIdx..lastIdx] ke kiri satu posisi,
      lalu tempatkan val di lastIdx fisik yang lama. */

void insertAt(ListKontigu *l, ElType val, int i);
/* Menambahkan val sebagai elemen pada indeks logis ke-i */
/* I.S. List l tidak penuh, mungkin kosong. */
/*      Jika l tidak kosong, i adalah indeks logis yang valid untuk penambahan (0..listLength(l)). */
/* F.S. val disisipkan pada indeks logis ke-i, elemen setelahnya digeser. List mungkin bergeser secara fisik. */
/* Proses:
   1. Jika list kosong (i harus 0), sama seperti insertFirst/Last.
   2. Jika 0 < i < listLength(l):
      a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
      b. Cek ruang: Prioritaskan menggeser ke kanan jika ada ruang setelah lastIdx.
         Geser elemen dari physTarget hingga lastIdx ke kanan satu posisi.
      c. Jika tidak ada ruang kanan, coba geser ke kiri jika ada ruang sebelum firstIdx.
         Geser elemen dari firstIdx hingga physTarget-1 ke kiri satu posisi.
         physTarget sekarang menjadi physTarget-1.
      d. Tempatkan val di ELMT(*l, physTarget). */


/* ********** PENGHAPUSAN ELEMEN ********** */
void deleteFirst(ListKontigu *l, ElType *val);
/* Menghapus elemen pertama List l (indeks logis 0) */
/* I.S. List l tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum dihapus. */
/*      Elemen pertama fisik (di firstIdx) di-set menjadi MARK. */

void deleteLast(ListKontigu *l, ElType *val);
/* Menghapus elemen terakhir list (indeks logis length-1) */
/* I.S. List l tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum dihapus. */
/*      Elemen terakhir fisik (di lastIdx) di-set menjadi MARK. */

void deleteAt(ListKontigu *l, int i, ElType *val);
/* Menghapus elemen pada indeks logis ke-i */
/* I.S. List l tidak kosong, i adalah indeks logis yang valid (0..listLength(l)-1) */
/* F.S. val adalah nilai elemen pada indeks logis i sebelum dihapus. */
/*      Elemen pada indeks logis i dihapus dari list, elemen setelahnya digeser ke kiri */
/*      secara fisik untuk menjaga kontiguitas blok. */
/* 
    Jika 0 < i < listLength(l)-1:
      a. Tentukan indeks fisik target: physTarget = firstIdx(l) + i.
      b. Simpan ELMT(l, physTarget) ke val.
      c. Geser elemen dari physTarget+1 hingga lastIdx(l) ke kiri satu posisi.
      d. Set ELMT(*l, lastIdx(l)) = MARK (posisi fisik terakhir yang lama). */


/* ********** OPERASI PENGGABUNGAN ********** */
void concat(ListKontigu l1, ListKontigu l2, ListKontigu *l3);
/* I.S. l1 dan l2 terdefinisi, boleh kosong. l3 sembarang. */
/* F.S. l3 adalah hasil penggabungan elemen efektif l1 dan l2. */
/*      Elemen l1 disalin terlebih dahulu, diikuti elemen l2. */
/*      Hasilnya ditempatkan di l3 mulai dari indeks fisik 0. */
/*      Jika total elemen > CAPACITY, hanya elemen yang muat yang disalin. */


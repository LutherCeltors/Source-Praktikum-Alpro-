#include "liststatik.h"
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
{
   for (int i = 0; i<CAPACITY; i++) l->contents[i] = MARK;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
   int length = 0;
   int i = 0;
   while(l.contents[i] != MARK && i < CAPACITY){
      length += 1;
      i++;
   }  
   return length;
}
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
   int i = 0;
   while(l.contents[i] == MARK && i < CAPACITY){
      i += 1;
   }  
   return i;
}

IdxType getLastIdx(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
   int i = CAPACITY-1;
   while(l.contents[i] == MARK && i >= 0){
      i -= 1;
   }  
   return i;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   if (i < CAPACITY && i >= 0) return true;
   else return false;
}
boolean isIdxEff(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
   int last_idx = getLastIdxk(l);
   int first_idx = getFirstIdx(l);

   if (i >= first_idx && i <= last_idx) return true;
   else return false;
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
   if (listLength(l) == 0) return true;
   else return false;
}
boolean isFull(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
   if (listLength(l) == CAPACITY) return true;
   else return false;
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
   int n;
   do {
      scanf("%d", &n);
   }while (n < 0 && n >= CAPACITY);
   if (0 < n && n <= CAPACITY){
      CreateListStatik(l);
      for (int i = 0; i < n; i++){
         scanf("%d\n", l->contents[i]);
      }
   } else if(n == 0){
      CreateListStatik(l);
   }
}

void printList(ListStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
   int n = listLength(l);
   if (0 < n && n<= CAPACITY){
      int fidx = getFirstIdx(l);
      for (int i = fidx; i < n; i++){
         if (i == (n-1)){
            printf(",%d]", l.contents[n]);
         }else if(i == fidx){
            printf("[%d", l.contents[0]);
         }else{
            printf(",%d", l.contents[i]);
         }
      }
   } else if(n == 0){
      printf("[]");
   }
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{
   if (listLength(l1) == listLength(l2) && listLength(l1) != 0){
      ListStatik l;
      CreateListStatik(&l);
      if (plus){
         for (int i = getFirstIdx(l); i < listLength(l1) + getFirstIdx(l1); i++){
            l.contents[i] = l1.contents[i] + l2.contents[i]; 
         }
      }
      else if(!plus){
         for (int i = getFirstIdx(l); i < listLength(l1) + getFirstIdx(l1); i++){
            l.contents[i] = l1.contents[i] - l2.contents[i]; 
         }
      }
   }
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
   if (listLength(l1) == listLength(l2) && listLength(l1) != 0){
      for(int i = 0; i < listLength(l1); i++){
         if (l1.contents[i] != l2.contents[i]){
            return false;
            break;
         }
      }
   }else{
      return false;
   }
   return true;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
   if (listLength(l) != 0){
      for(int i = getFirstIdx(l); i < listLength(l) + getFirstIdx(l); i++){
         if (ELMT(l,i) == val){
            return i;
         }
      }return IDX_UNDEF;
   }else return IDX_UNDEF;
}
/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
   *max = l.contents[0];
   *min = l.contents[1];

   for (int i = getFirstIdx(l); i < getFirstIdx(l) + listLength(l); i++){
      if (*max < l.contents[i]){
         *max = l.contents[i];
      }else if(*min > l.contents[i]){
         *min = l.contents[i];
      }
   }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
{
   for (int i = listLength(*(l)) + getFirstIdx(*(l)); i > getFirstIdx(*(l)); i--){
      l->contents[i] = l->contents[i-1]; 
   }
   l->contents[0] = val;
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
{
   /* anggap first_idx = 0*/
   for(int i = getLastIdx(*(l)) + 1; i > idx; i--){
      l->contents[i] = l->contents[i-1];
   }
   l->contents[idx] = val;
}
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   l->contents[getLastIdx(*(l))+1] = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val);
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

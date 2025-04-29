#include "time.h"

// /* *** Definisi TYPE TIME <HH:MM:SS> *** */
// typedef struct { 
// 	int HH; /* integer [0..23] */
// 	int MM; /* integer [0..59] */
// 	int SS; /* integer [0..59] */
// } TIME;

// /* *** Notasi Akses: selektor TIME *** */
// #define Hour(T) (T).HH
// #define Minute(T) (T).MM
// #define Second(T) (T).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    if (H >= 0 && H <= 23 && M >= 0 && M <= 59 && S >= 0 && S <= 59){
        return true;
    }else return false;
}
/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
{
    T->HH = HH;
    T->MM = MM;
    T->SS = SS;
}
/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
{
    int HH, MM, SS;
    for (;;){
        scanf("%d %d %d", &HH, &MM, &SS);
        if (HH >= 0 && HH <= 23 && MM >= 0 && MM <= 59 && SS >= 0 && SS <= 59) break;
        else printf("Jam tidak valid\n");
    }
    CreateTime(T, HH, MM, SS);
}
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
    printf("%d:%d:%d", T.HH, T.MM, T.SS);
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    long sum = 3600*T.HH + 60*T.MM + T.SS;
    return sum;
}
TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
    TIME T;
    int sec;
    sec = N % 86400;

    int HH = sec/3600;
    int MM = (sec - HH*3600)/60;
    int SS = sec - (HH*3600) - (MM*60);

    CreateTime(&T, HH, MM, SS);
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    boolean status = false;
    if (T1.HH == T2.HH){
        if (T2.MM == T1.MM){
            if (T1.SS == T1.SS){
                status = true;
            }
        }
    }
    return true;
}
boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    boolean status = TEQ(T1, T2);
    if (status) return false;
    else return true;
}
boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
    long a = TIMEToDetik(T1);
    long b = TIMEToDetik(T2);
    if (a>=b) return false;
    else return true;
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
{
    long a = TIMEToDetik(T1);
    long b = TIMEToDetik(T2);
    if (a<=b) return false;
    else return true;
}
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */{
    long a = TIMEToDetik(T);
    a += 1;
    T = DetikToTIME(a);
    return T;
}
TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
    long a = TIMEToDetik(T);
    a += N;
    T = DetikToTIME(a);
    return T;
}
TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
    long a = TIMEToDetik(T);
    a -= 1;
    T = DetikToTIME(a);
    return T;
}
TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
{
    long a = TIMEToDetik(T);
    a -= N;
    T = DetikToTIME(a);
    return T;
}
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    long a = TIMEToDetik(TAkh);
    long b = TIMEToDetik(TAw);
    if (a < b){
        a += 86400;
        return a-b;
    }else{
        return a-b;
    }
}

#include "operasi.h"
#include <stdio.h>
#include <string.h>

// /* ADT Vital: Menyimpan data vital pasien */
// typedef struct {
//     int tekananDarah;        // dalam mmHg
//     int detakJantung;        // dalam bpm
//     float saturasiOksigen;   // dalam persen (0.0 - 100.0)
// } Vital;

// /* ADT Lokasi: Menyimpan koordinat pasien dalam ruangan RS */
// typedef struct {
//     int x;  // Kolom (misal: 0 = IGD, 1 = ICU, dst)
//     int y;  // Baris (misal: 0 = lantai 1, dst)
// } Lokasi;

// /* ADT Pasien */
// typedef struct {
//     char nama[50];
//     Vital v;
//     Lokasi l;
// } Pasien;

/* --- Konstruktor --- */
Vital MakeVital(int tekanan, int detak, float saturasi){
    Vital v;
    v.detakJantung = detak;
    v.tekananDarah = tekanan;
    v.saturasiOksigen = saturasi;
    return v;
}
Lokasi MakeLokasi(int x, int y){
    Lokasi l;
    l.x = x;
    l.y = y;
    return l;
}
Pasien MakePasien(char nama[], Vital v, Lokasi l){
    Pasien p;
    strcpy(p.nama, nama);
    p.l = l;
    p.v = v;
}

/* --- Aksesor --- */
int GetTekanan(Vital v){
    return v.tekananDarah;
}
int GetDetak(Vital v){
    return v.detakJantung;
}
float GetSaturasi(Vital v){
    return v.saturasiOksigen;
}
int GetX(Lokasi l){
    return l.x;
}
int GetY(Lokasi l){
    return l.y;
}
Vital GetVital(Pasien p){
    return p.v;
}
Lokasi GetLokasi(Pasien p){
    return p.l;
}

/* --- Mutator --- */
void SetTekanan(Vital *v, int tekanan){
    v->tekananDarah = tekanan;
}
void SetDetak(Vital *v, int detak){
    v->detakJantung = detak;
}
void SetSaturasi(Vital *v, float saturasi){
    v->saturasiOksigen = saturasi;
}
void SetX(Lokasi *l, int x){
    l->x = x;
}
void SetY(Lokasi *l, int y){
    l->y = y;
}
void SetVital(Pasien *p, Vital v){
    p->v = v;
}
void SetLokasi(Pasien *p, Lokasi l){
    p->l = l;
}

/* --- Operasi Vital --- */
bool IsSehat(Vital v)
/* True jika:
   90 <= tekanan darah <= 140
   60 <= detak jantung <= 100
   saturasi >= 95.0 */
{
    bool issehat;
    if (v.tekananDarah >= 90 && v.tekananDarah <=140 && v.detakJantung >= 60 && v.detakJantung <= 100 && v.saturasiOksigen >= 95.0){
        issehat = true;
    }else issehat = false;
    return issehat;
}

void ResetVital(Vital *v)
/* Mengatur kembali semua nilai vital ke default (120/80/98.0) */
{
    v->tekananDarah = 120;
    v->detakJantung = 80;
    v->saturasiOksigen = 98.0;
}
int CompareVital(Vital a, Vital b)
/* Mengembalikan:
   -1 jika a < b (tekanan + detak + saturasi total)
    0 jika sama
    1 jika a > b
*/
{
    float sum_a = a.detakJantung + a.saturasiOksigen + a.tekananDarah;
    float sum_b = b.detakJantung + b.saturasiOksigen + b.tekananDarah;
    if (sum_a < sum_b) return -1;
    else if (sum_a == sum_b) return 0;
    else return 1;
}

/* --- Operasi Lokasi --- */
void PindahPasien(Lokasi *l, int dx, int dy)
/* Memindahkan pasien ke koordinat baru berdasarkan delta */
{
    l->x += dx;
    l->y += dy;
}
/* --- Print --- */
void PrintVital(Vital v)
/* Format: "Tekanan: xxx mmHg, Detak: xxx bpm, Saturasi: xx.xx%" */{
    printf("Tekanan: %d mmhg, Detak: %d bpm, Saturasi: %.2f%\n", v.tekananDarah, v.detakJantung, v.saturasiOksigen);
}

void PrintLokasi(Lokasi l)
/* Format: "Lokasi: (x, y)" */
{
    printf("Lokasi: (%d, %d)\n", l.x, l.y);
}

void PrintPasien(Pasien p)
/* Menampilkan semua info pasien:
   Nama
   Vital
   Lokasi
*/
{
    printf("%s\n", p.nama);
    PrintVital(p.v);
    PrintLokasi(p.l);
}

#include "point.h"
#include <math.h>

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y){
    P->X = X;
    P->Y = Y;
}
/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P){
    float X, Y;
    scanf("Masukkan %d %d", &X, &Y);
    CreatePoint(&P, X, Y);
}
/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P){
    printf("(%d, %d)\n", Absis(P), Ordinat(P));
}

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P){
    printf("%f\n",Absis(P));
}
float GetY(const POINT P){
    printf("%f\n",Ordinat(P));
}
void  SetX(POINT *P, float X){
    P->X = X;
}
void  SetY(POINT *P, float Y){
    P->Y = Y;
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P){
    if (P.X == 0 && P.Y == 0){
        return true;
    }else return false;
}     /* true jika P = (0,0) */
boolean IsOnSbX(POINT P){
    if (P.Y == 0){
        return true;
    }else return false;
}     /* true jika Y = 0 */
boolean IsOnSbY(POINT P){
    if (P.X == 0){
        return true;
    }else return false;
}    /* true jika X = 0 */
int Kuadran(POINT P){
    if (P.X != 0 && P.Y != 0){
        if (P.X < 0 && P.Y > 0){
            return 2;
        }else if(P.X > 0 && P.Y > 0) return 1;
        else if(P.X < 0 && P.Y < 0) return 3;
        else if(P.X > 0 && P.Y < 0) return 4;
    }
}      /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */

/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2){
    if (P1.X == P2.X && P1.Y == P2.Y) return true;
    else return false;
}   /* true jika X dan Y identik */
boolean NonEquals(POINT P1, POINT P2){/* negasi Equals */
if (P1.X != P2.X && P1.Y != P2.Y) return true;
    else return false;
}
/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float  Distance(POINT P1, POINT P2){
    return sqrtf(((P1.X-P2.X)*(P1.X-P2.X)) + ((P1.Y-P2.Y)*(P1.Y-P2.Y)));
}
/* Menghasilkan titik tengah P1 dan P2 */
POINT  MidPoint(POINT P1, POINT P2){
    POINT mid;
    mid.X = (P1.X+P2.X)/2;
    mid.Y = (P1.Y+P2.Y)/2;
    return mid;
}

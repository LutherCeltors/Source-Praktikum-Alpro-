#include "kalkulus.h"
#include "Boolean.h"
#include "matrix.h"

Matrix dilate(Matrix v, int scale)
/* Setiap titik (x, y) menjadi (x*scale, y*scale) */
{
    Matrix dilate;
    copyMatrix(v, &dilate);
    for (int i = 0; i < v.rowEff; i++){
        for (int j = 0; j < v.colEff; j++){
            dilate.mem[i][j]  *= scale;
        }
    }
    return dilate;
}

Matrix translate(Matrix v, int dx, int dy)
/* Setiap titik (x, y) menjadi (x+dx, y+dy) */
{
    Matrix translate;
    copyMatrix(v, &translate);
    for (int i = 0; i < v.rowEff; i++){
            translate.mem[i][0]  += dx;
            translate.mem[i][1]  += dy;
    }
    return translate;

}
Matrix reflect(Matrix v, char axis)
/* 'x' → y = -y, 'y' → x = -x */
{
    Matrix reflect;
    copyMatrix(v, &reflect);
    if(axis == 'x'){
        for (int i = 0; i < v.rowEff; i++){
            reflect.mem[i][1] *= -1;
        }
    }else if (axis == 'y'){
        for (int i = 0; i < v.rowEff; i++){
            reflect.mem[i][0] *= -1;
        }
    }
    return reflect;
}

Matrix rotate(Matrix v, int degree)
/* Memutar setiap titik (x, y) sebesar degree derajat searah jarum jam dari (0,0) */
/* Gunakan rumus rotasi:
   x' = x * cosθ + y * sinθ
   y' = -x * sinθ + y * cosθ
   degree hanya 0, 90, 180, 270 (bisa pakai konstanta tanpa trigonometri float) */
/* cos0 = 1, sin0 = 0*/
/* cos90 = 0, sin90 = 1*/
/* cos180 = -1, sin180 = 0*/
/* cos270 = 0, sin270 = -1*/
/* DEGREE SUDAH PASTI 4 JENIS, HARDCODE SAJA, TIDAK PERLU PAKE <math.h> */
{
    Matrix rotate;
    copyMatrix(v, &rotate);
    if(degree == 0){
        return rotate;
    }else if (degree == 90){
        for (int i = 0; i < v.rowEff; i++){
            rotate.mem[i][0] = rotate.mem[i][0]*0 + rotate.mem[i][1]*1;
            rotate.mem[i][1] = -1 * rotate.mem[i][0]*1 + rotate.mem[i][1]*0;
        }
    }
    else if (degree == 180){
        for (int i = 0; i < v.rowEff; i++){
            rotate.mem[i][0] = rotate.mem[i][0]*-1 + rotate.mem[i][1]*0;
            rotate.mem[i][1] = -1 * rotate.mem[i][0]*0 + rotate.mem[i][1]*-1;
        }
    }
    else if (degree == 270){
        for (int i = 0; i < v.rowEff; i++){
            rotate.mem[i][0] = rotate.mem[i][0]*0 + rotate.mem[i][1]*-1;
            rotate.mem[i][1] = -1 * rotate.mem[i][0]*-1 + rotate.mem[i][1]*0;
        }
    }
    return rotate;

}
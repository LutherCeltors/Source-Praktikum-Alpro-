#include <stdio.h>
#include <stdlib.h>
#include "tester.h" /*Jadikan komentar apabila ingin dijalankan*/

/* Tulis kode disini jika perlu */

int main() {
    init(); /*Jadikan komentar apabila ingin dijalankan*/
    FILE *f;
    int ID, Succes, mValue;
    int totMis, succMis, valMis;
    f = fopen("input.txt", "r");
    fscanf(f, "%d %d %d", &ID, &Succes, &mValue);
    totMis = 0 ; 
    succMis = 0 ; 
    valMis = 0;
    while (ID != -1 || Succes != 0 || mValue != 0){
        totMis += 1;
        if (Succes == 1){
            succMis += 1;
            valMis += mValue;
        }
        fscanf(f, "%d %d %d", &ID, &Succes, &mValue);
    }
    printf("Total Misi: %d\n", totMis);
    printf("Misi Berhasil: %d\n", succMis);
    printf("Total Nilai Misi: %d\n", valMis);
    fclose(f);
    return 0;
}
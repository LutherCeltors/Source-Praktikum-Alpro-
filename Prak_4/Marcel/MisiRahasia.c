#include <stdio.h>
#include <stdlib.h>
#include "tester.h" /*Jadikan komentar apabila ingin dijalankan*/


int main() {
    init(); /*Jadikan komentar apabila ingin dijalankan*/
    FILE *fin, *fquer;
    int ID, Succ, mVal;
    typedef struct{
        int id;
        int succ;
        int mval;
    }Miss;
    Miss arr[1000];
    Miss temp;
    int neff, Pass, Tukar;
    int tindex, ix;
    /* Tulis kode dibawa ini */
    fin = fopen("input.txt", "r");
    fquer = fopen("query.txt", "r");
    // TODO: tulis kode untuk algoritma utama
    neff = 0;
    fscanf(fin, "%d %d %d", &ID, &Succ, &mVal);
    while (ID != -1 || Succ != 0 || mVal != 0){
        arr[neff].id = ID; 
        arr[neff].succ = Succ; 
        arr[neff].mval = mVal; 
        fscanf(fin, "%d %d %d", &ID, &Succ, &mVal);
        neff += 1;
    }
 
    // Prioritas 1: Success (descending)
    for (int i = 0; i < neff - 1; i++) {
        for (int j = 0; j < neff - i - 1; j++) {
            if (arr[j].succ > arr[j+1].succ) {
                temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }

    // Prioritas 2: Mission Value (descending)
    for (int i = 0; i < neff - 1; i++) {
        for (int j = 0; j < neff - i - 1; j++) {
            if (arr[j].succ == arr[j+1].succ && arr[j].mval > arr[j+1].mval) {
                temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }

    // Prioritas 3: ID (descending)
    for (int i = 0; i < neff - 1; i++) {
        for (int j = 0; j < neff - i - 1; j++) {
            if (arr[j].succ == arr[j+1].succ && arr[j].mval == arr[j+1].mval && arr[j].id > arr[j+1].id) {
                temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }

    fscanf(fquer, "%d", &tindex);
    for (int i = 0; i<tindex; i++){
        fscanf(fquer, "%d", &ix);
        printf("%d %d\n", arr[ix-1].id, arr[ix-1].mval);
    }

    fclose(fin);
    fclose(fquer);
    return 0;
}
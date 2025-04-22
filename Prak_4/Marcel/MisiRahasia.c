#include <stdio.h>
#include <stdlib.h>
#include "tester.h"


int main() {
    init();
    FILE *fin, *fquer;
    int ID, Succ, mVal;
    typedef struct{
        int id;
        int succ;
        int mval;
    }Miss;
    Miss arr[1000];
    int neff, Pass, Tukar, temp;
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
    //sort prioritas 1
    Pass = 1;
    Tukar = 1;
    while (Pass <= neff-1  && Tukar){
        Tukar = 0;
        for (int i = neff; i>=Pass+1; i--){
            if (arr[i].succ < arr[i-1].succ){
                temp = arr[i].succ;
                arr[i].succ = arr[i+1].succ;
                arr[i+1].succ = temp;
                Tukar = 1;
            }
        }Pass += 1;
    }
    //prioritas 2
    Pass = 1;
    Tukar = 1;
    while (Pass <= neff-1  && Tukar){
        Tukar = 0;
        for (int i = neff; i>=Pass+1; i--){
            if (arr[i].mval < arr[i-1].mval){
                temp = arr[i].mval;
                arr[i].mval = arr[i+1].mval;
                arr[i+1].mval = temp;
                Tukar = 1;
            }
        }Pass += 1;
    }
    //prioritas 3
    Pass = 1;
    Tukar = 1;
    while (Pass <= neff-1  && Tukar){
        Tukar = 0;
        for (int i = neff; i>=Pass+1; i--){
            if (arr[i].id < arr[i-1].id && arr[i].succ == arr[i-1].succ && arr[i].mval == arr[i-1].mval){
                temp = arr[i].id;
                arr[i].id = arr[i+1].id;
                arr[i+1].id = temp;
                Tukar = 1;
            }
        }Pass += 1;
    }

    fscanf(fquer, "%d", &tindex);
    for (int i = 0; i<tindex; i++){
        fscanf(fquer, "%d", &ix);
        printf("%d %d\n", arr[ix].id, arr[ix].mval);
    }

    fclose(fin);
    fclose(fquer);
    return 0;
}
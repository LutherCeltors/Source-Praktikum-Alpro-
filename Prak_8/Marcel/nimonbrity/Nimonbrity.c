#include <stdio.h>
#include "matrix.h"

int main(){
    Matrix m;
    int N;
    scanf("%d", &N);
    createMatrix(N, N, &m);

    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            scanf("%d", &m.mem[i][j]);
        }
    }

    int nimonbrity = -1;
    if (N == 1){
        printf("0\n");
    }
    else{
        nimonbrity = -1;
        for (int i = 0; i < m.rowEff && nimonbrity == -1; i++){
            for (int j = 0; j < m.colEff; j++){
                if (m.mem[i][j] == 0 && i != j){
                    nimonbrity = 1;
                }
            }
        }
        printf("%d\n", nimonbrity);
    }
    return 0;
}
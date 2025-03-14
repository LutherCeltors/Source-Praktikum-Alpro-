#include <stdio.h>

int main(){
    /*Kamus*/
    int N, i, j, k, l, m;

    /*Algoritma*/
    scanf("%d", &N);
    /*Validasi*/
    if ((N % 2)== 0){
        printf("Input tidak valid !");
    }else{
        /*inisiasi*/
        k = 0;
        l = 0;
        m = 0;
        for (i=1; i<=N;++i){
            for (j=1; j<=N;++j){
                if (j == ((N+1)/2) && i == 1 && l == 0){
                    k = j;
                    printf("*");
                }else if((j == k || j == (k + ((j-1)*2))) && l == 0){
                    printf("*");
                }else if(k == 1){
                    k = 0;
                    l = 1;
                    m = ((j-1)*2);
                }else if (j == l || j == l + m){
                    printf("*");
                }else if (i == N){
                    if (j == ((N+1)/2)){
                        printf("*");
                    }
                }else{
                    printf(".");
                }
            }
            printf("\n");
            k = k - 1;
            l = l + 1;
            m = m - 2;
        }
    }
}
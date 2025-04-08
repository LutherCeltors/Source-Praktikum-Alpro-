#include <stdio.h>
#include <stdlib.h>

int main(){
    int sumi, bil, idx, k;
    scanf("%d", &sumi);
    int n[sumi], sumk[50];
    for (int i = 0; i<=sumi; i++)
        scanf("%d", &n[i]);
    do{
        scanf("%d", &bil);
        k = 0;
        int idxl = -2;
        for (int j=0 ; j<=sumi; j++){
            printf("%d", j);
            if (n[j] == bil){
                k = k + 1;
                idx = j;  
                if (idxl != idx)
                    sumk[k] = idx;  
                idxl = idx; 
                printf("-%d-\n", idx);
                printf("I%dI\n", k);
                break;
            }
        }if (k==0){
            idx = -1;
            k = k + 1;
            sumk[k] = idx;
            printf("I%dI\n", k);
            printf("-%d-\n", idx);
        }
    }while(idx != -1);

    printf("[");
    for (int l=1; l<= k; l++){
        printf("%d", sumk[l]);
        if (l != k){
            printf(", ");
        }
    }
    printf("]\n");
    
}
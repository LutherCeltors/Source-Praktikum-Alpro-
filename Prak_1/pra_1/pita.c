#include <stdio.h>

int main(){
    int A, B, i;

    scanf("%d", &A);
    scanf("%d", &B);
    /*Validasi*/
    if (A > 1000000000 || A < 1 || B > 1000000000 || B < 1){
        printf("Masukan tidak valid.");
    }else{
        if (A>= B){
            for (i=B; i>=1; i--){
                if ((B % i) == 0 && ((A % i) == 0)){
                    printf("%d\n", i);
                    break;
                }
            }
        }else{
            for (i=A; i>=1; i--){
                if ((A % i) == 0 && ((B % i) == 0)){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
}
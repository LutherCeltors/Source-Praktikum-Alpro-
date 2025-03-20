#include <stdio.h>

long long int kombinasi (int a, int b);

int main(){
    int i, j, n, sp;
    long long int k;
    int spasi;

    scanf("%d", &n);
    for (i=0;i<n;i++){
        spasi = (n-1)-i;
        for (sp=spasi;sp>=0;sp--){
            printf(" ");
        }
        for (j=0;j<=i;j++){
            k = kombinasi(i,j);
            printf("%lld ", k);
        }
        printf("\n");
    }
}

long long int kombinasi (int a, int b){
    long long int k1, k2, k3, i;
    k1 = 1;
    k2 = 1;
    k3 = 1;
    for (i = a; i >=1; i--){
        k1 *= i; 
        if (i==0){
            k1 = 1;
        }
    }
    for (i = b; i >=1; i--){
        k2 *= i;
        if (i==0){
            k2 = 1;
        } 
    }
    for (i = (a-b); i >=1; i--){
        k3 *= i; 
        if (i==0){
            k3 = 1;
        }
    }
    return k1/(k2*k3);
    
}

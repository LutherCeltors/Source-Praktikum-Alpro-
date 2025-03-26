#include <stdio.h>

long long kombinasi (int a, int b);

int main(){
    int i, j, n, sp;
    long long k;
    int spasi;

    scanf("%d", &n);
    for (i=0;i<n;i++){
        spasi = (n-2)-i;
        for (sp=spasi;sp>=0;sp--){
            printf(" ");
        }
        for (j=0;j<=i;j++){
            k = kombinasi(i,j);
            printf("%lld", k);
            if (j != i){
                printf(" ");
            }
        }
        printf("\n");
    }
}

long long kombinasi(int a, int b) {
    if (b == 0 || b == a) return 1;
    
    long long hasil = 1;
    if (b > a - b) b = a - b;  

    for (int i = 0; i < b; i++) {
        hasil = hasil * (a - i) / (i + 1); 
    }
    return hasil;
}

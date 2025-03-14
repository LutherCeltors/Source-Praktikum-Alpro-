#include <stdio.h>

int fibbo(int n) {
    if (n == 0) {
        return 0;
    }else if (n == 1){
        return 1;
    }else{
        return fibbo(n - 2) + fibbo(n - 1);
    }
}

int main() {
    // int hasil = fibbo(5);
    // printf("%d\n", hasil);
    int i, N, hasil;
    scanf("%d",&N);

    for (i=0;i<=N-1;i++){
        hasil = fibbo(i);
        printf("%d\n", hasil);
    }
    return 0;
}

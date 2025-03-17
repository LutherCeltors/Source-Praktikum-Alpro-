#include <stdio.h>

int main() {
    int i;
    int N;
    scanf("%d", &N);
    int a = 0;
    int b = 1;
    int temp;
    if (N < 1) {
        printf("Tidak Valid");
    }
    else {
        for (i=1; i<=N; i++) {
            printf("%d ", a);
            temp = b;
            b += a;
            a = temp;
        }

    }
    return 0;
    
}
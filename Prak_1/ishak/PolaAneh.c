#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N < 1 || N > 25 || N % 2 == 0) {
        return 0;
    }
    int mid = N / 2; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {     
            int distance;
            if (i <= mid) {
                distance = i; 
            } else {
                distance = N - 1 - i; 
            }          
            if (j == mid - distance || j == mid + distance) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n"); 
    }

    return 0;
}

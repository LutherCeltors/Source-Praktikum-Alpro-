#include <stdio.h>

int main() {
    int N, k;
    scanf("%d %d", &N, &k);
    int arr[10001];
    int result[10001]; 

    for (int i = 0;i<N;i++) {
        scanf("%d", &arr[i]);
    }
    k = k % N; 

    for (int i = 0;i<N;i++) {
        result[(i + k) % N] = arr[i];
    }

    for (int i = 0;i<N;i++) {
        printf("%d", result[i]);
        if (i < N-1) printf(" ");
    }
    printf("\n");
}

#include <stdio.h>

typedef struct {
    int contents[100];
    int nEff;
} List;

int maxInWindow(List l, int start, int k) {
    int max = l.contents[start];
    for (int i = 1; i < k; i++) {
        if (l.contents[start + i] > max) {
            max = l.contents[start + i];
        }
    }
    return max;
}

int main() {
    int N, K;
    List l;

    scanf("%d", &N);
    l.nEff = N;

    for (int i = 0; i < N; i++) {
        scanf("%d", &l.contents[i]);
    }

    scanf("%d", &K);

    printf("[");
    for (int i = 0; i <= N - K; i++) {
        int max = maxInWindow(l, i, K);
        printf("%d", max);
        if (i < N - K) printf(",");
    }
    printf("]\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[1000];
    int arr2[1000];
    int arr3[1000];
    int N;
    int val;
    int val2;
    int Q;

    scanf("%d", &N);

    for (int i = 0;i<=N-1;i++) {
        scanf("%d", &val);
        arr[i] = val;
    }

    scanf("%d", &Q);
    for (int j = 0;j<=Q-1;j++) {
        scanf("%d", &val2);
        arr2[j] = val2;
    }

    int x = 0;
    int index;
    for (int j = 0;j<=Q-1;j++) {
        int benar = 0;
        for (int i = 0;i<=N-1;i++) {
            if (arr2[j] == arr[i]) {
                benar = 1;
                index = i;
                break;
            }
        }
        if (benar == 1) {
            arr3[x] = index;
            x += 1;
        }
        else {
            arr3[x] = -1;
            x += 1;      
        }
    }


    printf("[");
    for (int y = 0;y<=x-1;y++) {
        if (y == x-1) {
            printf("%d", arr3[y]);
        }
        else {
            printf("%d, ", arr3[y]);
        }
    }
    printf("]\n");
}
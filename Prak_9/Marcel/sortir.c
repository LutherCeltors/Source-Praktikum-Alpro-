#include <stdio.h>

void displayQueue(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int scores[100];  

    for (int i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
    }

    sortDescending(scores, N);
    displayQueue(scores, N);

    return 0;
}

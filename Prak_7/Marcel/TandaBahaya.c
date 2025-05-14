#include <stdio.h>

int main () {
    int N, a, b, c;
    int repeat;
    int arr[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    if (N < 3){
        printf("Santai\n");
    }else{
        repeat = 1;

        for (int i = 0; i < N - 2 && repeat; i++) {
            for (int j = i + 1; j < N - 1 && repeat; j++) {
                for (int k = j + 1; k < N && repeat; k++) {
                    if (arr[i] < arr[k] && arr[k] < arr[j]) {
                        repeat = 1;
                    }
                }
            }
        }

        if (!repeat) {
            for (int i = 0; i < N - 2; i++){
                a = arr[i];
                b = arr[i + 1];
                c = arr[i + 2];
                if (a < c && c < b){
                    repeat = 0;
                }
            }if (!repeat){
                printf("Santai\n");
            }else{
                printf("Nyalakan\n");
            }
        }else{
            printf("Nyalakan\n");
        }
    }    
}

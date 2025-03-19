#include <stdio.h>

int main() {
    int N;
    int x;
    int init = 1;
    int add;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i = i + 1) {
        x = init;
        add = i;
        
        for (int j = 0; j < N; j = j + 1) {
            if (j < N - i - 1) {
                printf("%d", x);
                add = add + 1;
                x = x + add;
            } else {
                printf("%d", x);
                if (j != N - i - 1) {
                    add = add - 1;
                }
                x = x + add;
            }
            printf(" ");
        }
        
        printf("\n");
        init = init + i + 2;
    }
    
    return 0;
}

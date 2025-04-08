#include <stdio.h>

int main() {
    int code = 0;
    int arr[1000];
    int n,x,target;
    scanf("%d", &n);
    for (int k=0;k<n;k++) {
        scanf("%d", &x);
        arr[k] = x;
    }

    scanf("%d", &target);


    for (int i=0;i<n;i++ ) {
        for (int j=0;j<n;j++) {
            code = 0;
            if ((arr[i] + arr[j]) == target) {
                code = 1;
            }
            if (i == j) {
                code = 0;
            }
            if (code == 1) {
                printf("[%d, %d]\n", i, j);
                break;
            }
        }
        if (code == 1) {
            break;
        }
    }
}
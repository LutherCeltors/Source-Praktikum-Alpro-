#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[20]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int total = 0;
    int total_subsets = 1 << n;  

    for (int mask = 1; mask < total_subsets; mask++) { 
        int max_val = -1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                if (arr[i] > max_val) {
                    max_val = arr[i];
                }
            }
        }
        total += max_val;
    }

    printf("%d\n", total);
    return 0;
}

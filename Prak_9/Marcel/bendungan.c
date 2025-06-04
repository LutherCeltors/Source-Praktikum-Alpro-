#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int height[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int left_max[MAX], right_max[MAX];
    

    left_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = (height[i] > left_max[i-1]) ? height[i] : left_max[i-1];
    }

    right_max[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--) {
        right_max[i] = (height[i] > right_max[i+1]) ? height[i] : right_max[i+1];
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        int water_level = (left_max[i] < right_max[i]) ? left_max[i] : right_max[i];
        if (water_level > height[i]) {
            total += water_level - height[i];
        }
    }

    printf("%d\n", total);
    return 0;
}

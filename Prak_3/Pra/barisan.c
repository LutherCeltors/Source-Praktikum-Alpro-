#include <stdio.h>

int fpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int kpk(int a, int b) {
    return a * b / fpb(a, b);
}

int main() {
    int n; scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    
    if (n == 0) printf("0\n");
    else {
        int temp_fpb = A[0];
        int temp_kpk = A[0];
        for (int i = 0; i < n; i++) {
            temp_fpb = fpb(A[i], temp_fpb);
            temp_kpk = kpk(A[i], temp_kpk);
        }
        int max = temp_fpb * temp_kpk;

        for (int i = 0; i < n; i++) {
            temp_fpb = 0; temp_kpk = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (!temp_fpb) temp_fpb = A[j];
                else temp_fpb = fpb(temp_fpb, A[j]);

                if (!temp_kpk) temp_kpk = A[j];
                else temp_kpk = kpk(temp_kpk, A[j]);
            }
            int current = temp_fpb * temp_kpk;
            if (current > max) max = current;
        }

        printf("%d\n", max);
    }
}
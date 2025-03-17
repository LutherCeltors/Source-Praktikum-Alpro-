#include <stdio.h>

int main () {
    int n, i, count;
    scanf("%d", &n);
    for (i=2;i<=n;i++) {
        count = 0;
        while (n % i == 0) {
            n /= i;
            count += 1;
            if (n % i != 0) {
                if (count == 1) {
                    printf("%d", i);
                }
                else if (count != 1) {
                    printf("%d^%d", i, count);
                }
                if (n != 1) {
                    printf(" * ");
                }

            }

        }        
    }
}
#include <stdio.h>

int main () {
    int b, i, count;
    scanf("%d", &b);
    for (i=2;i<=b;i++) {
        count = 0;
        while (b % i == 0) {
            b /= i;
            count += 1;
            if (b % i != 0) {
                if (count == 1) {
                    printf("%d", i);
                }
                else if (count != 1) {
                    printf("%d^%d", i, count);
                }
                if (b != 1) {
                    printf(" * ");
                }

            }

        }        
    }
    printf("\n");
}
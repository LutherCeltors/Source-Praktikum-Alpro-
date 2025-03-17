#include <stdio.h>

int main () {
    int A;
    int B;
    int i;

    scanf("%d", &A);;
    scanf("%d", &B);
    if (A < 1 || B < 1 || B > 1000000000 || A > 1000000000) {
        printf("Input TIDAK VALID");
    }

    else {
        if (A <= B) {
            for (i=A;i>=1;i--) {
                if (A % i == 0 && B % i == 0) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
        else {
            for (i=B;i>=1;i--) {
                if (A % i == 0 && B % i == 0) {
                    printf("%d\n", i);
                    break;
                }
        
            }
        }
    }

    return 0;
}
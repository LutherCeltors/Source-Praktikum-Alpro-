#include <stdio.h>

int main () {
    int n, lastdig, new = 0, ori;
    scanf("%d", &n);
    ori = n;
    while (n >= 1) {
        lastdig = n % 10;
        new = 10*new + lastdig;
        n /= 10;
    }

    if (ori == new) {
        printf("1");
    }
    else {
        printf("0");
    }
}
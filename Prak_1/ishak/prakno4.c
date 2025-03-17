#include <stdio.h>

int main () {
    int n, i, j, div, num = 1;
    scanf("%d", &n);
    for (i=2;i<n;i++) {
        if (n % i == 0) {
            for (j=2;j<i;j++) {
                if (j*j == i) {
                    if (num*i < n) {
                        printf("%d * ",i);
                        num = num*i;
                    }
                    else if (num*i == n) {
                        printf("%d",i);
                        num = num*i;
                    }
                      
                }
            }

        }
    }
    if (num < n) {
        div = n/num;
        printf("%d",div );
    }
    
}

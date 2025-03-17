#include <stdio.h>

int main() {
    int count;
    int i;
    count = 0;
    for (i=1;i <= 500;i++) {
        if (((i % 3 == 0)||(i % 7 == 0)) && (i % 5 != 0) && !((i % 3 == 0) && (i % 7 == 0))) {
            count += 1;
        }

    }

    printf("%d", count);

    return 0;
}

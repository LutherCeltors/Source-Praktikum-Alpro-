#include <stdio.h>
#include "tester.h" /*Jadikan komentar apabila ingin dijalankan*/

int main () {
    init(); /*Jadikan komentar apabila ingin dijalankan*/
    FILE *fa, *fb;
    int a1,b1,a2,b2;
    fa = fopen("file_a.txt", "r");
    fb = fopen("file_b.txt", "r");
    fscanf(fa, "%d %d", &a1, &b1);
    fscanf(fb, "%d %d", &a2, &b2);
    while (a1 != -1 && b1 != 99 && a2 != -1 && b2 != 99){
        if (a1<=a2) {
            printf("%d %d\n", a1, b1);
            fscanf(fa, "%d %d\n", &a1, &b1);
        }else{
            printf("%d %d\n", a2, b2);
            fscanf(fb, "%d %d\n", &a2, &b2);
        }
    }
    while (a1 != -1 && b1 != 99){
        printf("%d %d\n", a1, b1);
        fscanf(fa, "%d %d\n", &a1, &b1);

    }
    while (a2 != -1 && b2 != 99){
        printf("%d %d\n", a2, b2);
        fscanf(fb, "%d %d\n", &a2, &b2);
    }
    fclose(fa);
    fclose(fb);
    /* Write your code here */
    return 0;
}
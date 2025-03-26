#include <stdio.h>

int main(){
    int p1, p2, p3, p4, p5;
    float mean;

    scanf("%d", &p1);
    scanf("%d", &p2);
    scanf("%d", &p3);
    scanf("%d", &p4);
    scanf("%d", &p5);

    mean = (p1 + p2 + p3 + p4 + p5)/5;
    printf("%d\n", (p1 + p2 + p3 + p4 + p5));
    printf("%f\n", mean);

    if (mean >= 10){
        printf("Pesta Nimons Sukses!\n");
    }else{
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
    return 0;
}
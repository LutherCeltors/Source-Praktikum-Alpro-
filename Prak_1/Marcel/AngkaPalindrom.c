#include <stdio.h>

int main(){
    int sisa,n, angka, reverse;

    scanf("%d", &angka);
    n = angka;
    sisa = 1;
    reverse = 0;
    while (n != 0){
        sisa = n%10;
        reverse = (reverse*10) + sisa;
        n = n/10;   
    }
    if (angka == reverse){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}
#include <stdio.h>

int main(){
    int a,b; //a lebih kecil dari b, a,b masukan pengguna
    int count;

    scanf("%d %d", &a, &b);
    count = 0;
    for (int i = a; i <= b; i++){
        for (int j = 2; j <= i; j++){
            if (i%j == 0){
                if (j==i){
                    count += 1;
                }else{
                    break;
                } 
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
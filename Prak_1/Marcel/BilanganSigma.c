#include <stdio.h>
#include <math.h>

int main(){
    int bil, i, kuads, count;
    
    scanf("%d", &bil);
    count = 0;
    for(i = bil; i>0; i--){
        if (bil%i == 0){
            kuads = sqrt(i);
            if ((kuads*kuads) == i){
                count += 1;
            }
        }
    }
    printf("%d\n", count);
}
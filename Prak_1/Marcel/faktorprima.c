#include <stdio.h>

int main(){
    int n, i, count, ilama;

    scanf("%d", &n);
    i = 2;
    count = 0;
    ilama = 0;
    while (n>1){
        if (n%i == 0){
            // printf("-%d-\n", i);
            count += 1;
            n /= i;
            // printf("-%d-\n", n);
            if (count > 1){
                /*bandingkan dengan yg lama*/   
                if (ilama != i){
                    count -= 1;
                    if (n==1){
                        if (count == 1){
                            printf("%d * %d", ilama, i);
                        }else{
                            printf("%d^%d ", ilama, count);
                            printf("* %d", i);
                        }
                    }else{
                        if (count == 1){
                            printf("%d *", ilama);
                        }else{
                            printf("%d^%d *", ilama, count);
                            count = 1;
                        }
                    }
                }else if (ilama == i && n==1){
                    printf(" %d^%d", i, count);
                }
            }
            ilama = i;

        }else{
            i += 1;
        }
    }
}



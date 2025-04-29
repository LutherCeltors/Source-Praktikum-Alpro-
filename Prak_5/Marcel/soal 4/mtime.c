#include "time.h"
#include <stdio.h>

int main(){
    int i_tot, HH, MM, SS;
    TIME t1, t2;
    TIME tmin, tmax;
    long a, b;
    scanf("%d", &i_tot);
    for (int i = 1; i<=i_tot; i++){
        printf("[%d]\n", i);
        BacaTIME(&t1);
        BacaTIME(&t2);
        a = TIMEToDetik(t1);
        b = TIMEToDetik(t2);
        if (a >= b){
            printf("%ld\n", a-b);
            if (i == 0){
                tmin = t2;
                tmax = t1;
            }else{
                if (TIMEToDetik(tmax)<TIMEToDetik(t1)){
                    tmax = t1;
                }else if (TIMEToDetik(tmin) > TIMEToDetik(t2)){
                    tmin = t2;
                }
            }
        }else{ /*a<b*/
            printf("%ld\n", b-a);
            if (i == 0){
                tmin = t2;
                tmax = t1;
            }else{
                if (TIMEToDetik(tmax)<TIMEToDetik(t2)){
                    tmax = t2;
                }else if (TIMEToDetik(tmin) > TIMEToDetik(t1)){
                    tmin = t1;
                } 
            }
        }
    }
    TulisTIME(tmin);
    printf("\n");
    TulisTIME(tmax);
    printf("\n");
}
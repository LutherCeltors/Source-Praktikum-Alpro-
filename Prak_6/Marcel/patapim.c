#include <stdio.h>

int gcd(int a, int b){
    if (b == 0){
        return a;
    }else{
        return gcd (b, a % b);
    }
}

int main(){
    int n, retval;
    typedef struct{
        int contents [100];
        int nEff;
    }list;

    list a;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a.contents[i]);
    a.nEff = n;

    retval = gcd(abs(a.contents[0]), abs(a.contents[1]));
    
    for (int i = 2; i < a.nEff; i++){
        retval = gcd(retval, abs(a.contents[i]));
    }

    //debug
    // for (int i = 0; i < a.nEff; i++) printf("%d", a.contents[i]);
    // printf("\n");

    printf("%d\n", retval);

}


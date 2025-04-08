#include <stdio.h>
#include <string.h>

int main(){
    int len, count, palin;
    char s[1001];
    scanf("%s", &s);

    len = strlen(s);

    count = 0;
    for (int i = 0; i<len; i++){
        palin = 0;
        if(i != ((len/2)-1)){
            for (int j = 0; j<len; j++){
                if (i != j){
                    count += 1;
                }
            }
        }if ((count)%2 == 0){
            palin = 1;
        }else{
            palin = 0;
        }
    }
    if (palin == 1) printf("YES\n");
    else printf("NO\n");
}
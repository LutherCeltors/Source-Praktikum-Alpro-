#include <stdio.h>
#include <string.h>

int main(){
    int len, count, palin, sumchar, even, odd;
    char s[1001];
    char samp;

    scanf("%s", &s);

    len = strlen(s);
    samp = 'X';
    count = 0;
    sumchar = 0;
    even = 0; odd = 0;
    for (int i = 0; i<len; i++){
        if (samp != s[i]) samp = s[i];
        else i += 1;
        // printf("%c", samp);
        count = 0;
        for (int j = 0; j<len; j++){
            if (samp == s[j]) count += 1;
        }
        // printf("%d\n", count);
        if (count%2 == 0) even += 1;
        else odd += 1;
        sumchar += count;
        if (sumchar == len) break;
    }
    // printf("even: %d\n", even);
    // printf("odd: %d\n", odd);

    if (len%2 == 0 && even%2 == 0 && odd == 0) palin = 1;
    else if (len%2 == 1 && odd == 1) palin = 1;
    else palin = 0;

    if (palin == 1) printf("YES\n");
    else printf("NO\n");
}
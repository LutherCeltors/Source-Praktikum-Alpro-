#include <stdio.h>

int main(){

    long long int n, k, effect, temp_effect, hasil, t1, t2;
    long long int gkanan, gkiri;
    int arr[1001];

    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; i++) scanf("%d", &arr[i]);

    effect = 0;
    gkiri = arr[0];
    gkanan = arr[n-1];
    // printf("%d - gkiri\n", gkiri);
    // printf("%d - gkanan\n", gkanan);
    effect = 0;
    temp_effect = 0;
    if (k>1) effect = gkiri + gkanan;
    for (int j = 1; j<n-1; j++){
        if (k>1) temp_effect = gkiri + gkanan + arr[j];
        t1 = gkiri + arr[j];
        t2 = gkanan + arr[j];
        // printing(t1, t2);
        if (t1 >= t2) temp_effect = t1;
        else temp_effect = t2;
        if (temp_effect > effect) effect = temp_effect;
    }
    printf("%lld\n", effect);
   
}

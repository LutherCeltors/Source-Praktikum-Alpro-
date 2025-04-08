#include <stdio.h>

int main(){
    int N, arr[1001], tot_search, arrhasil[1001], search;
    int baw, bak, bat; /*batas awal, akhir dan tengah*/

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    scanf("%d", &tot_search);

    for (int j = 0; j < tot_search; j++){
        scanf("%d", &search);
        baw = 0;
        bak = N-1;
        arrhasil[j] = -1;

        while (bak >= baw){
            bat = (baw+bak)/2;
            if (arr[bat] == search){
                arrhasil[j] = bat;
                bak = bat - 1;
            }else if(search > arr[bat]){
                baw = bat + 1;
            }else if(search < arr[bat]){
                bak = bat - 1;
            }
        }
    }
    printf("[");
    for (int k = 0; k<tot_search; k++) {
        if (k != tot_search -1) printf("%d, ", arrhasil[k]);
        else printf("%d]\n", arrhasil[k]);
    }
}
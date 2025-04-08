#include <stdio.h> 

int main(){
    int N,rot,temp;
    int arr[100];
    scanf("%d %d", &N, &rot);

    for(int i = 0; i<N; i++) scanf("%d", &arr[i]);

    temp = 0;
    rot = rot % N;
    for (int j = 1; j<= rot; j++){
        for (int k = N-1; k>0; k--){
            temp = arr[k];
            arr[k] = arr[k-1];
            arr[k-1] = temp;
        }
    }

    for (int l = 0; l<N; l++){
        if (l != N-1) printf("%d ", arr[l]);
        else printf("%d\n", arr[l]);
    }
}

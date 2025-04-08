#include <stdio.h>

int main(){
    int N, sum, target; 
    int arr[1000]; 

    scanf("%d", &N);
    for (int i = 0; i<N ; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);

    for (int j = 0; j<N ; j++){
        if (sum == target){
            break;
        }
        for (int k = 0; k<N ; k++){
            if (j != k){
                sum = arr[j] + arr[k];
                }
            if (sum == target){
                printf("[%d, %d]\n", j, k);
                break; 
            }            
        }
    }
}
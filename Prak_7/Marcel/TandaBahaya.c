#include <stdio.h>

int main () {
    int N, a, b, c;
    int idxa, idxb, idxc;
    int repeat;
    int arr[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    repeat = 1;
    
    idxa = 0;
    idxb = 1;
    idxc = 2;

    while (idxa <= N-3 && repeat){
        while (idxb <= N-2 && repeat){
            while (idxc <= N-1 && repeat){
                a = arr[idxa];
                b = arr[idxb];
                c = arr[idxc];
                // printf("c1\n");
                if (a < c && c < b) {
                    repeat = 0;
                }
                idxc += 1;
            }
            a = arr[idxa];
            b = arr[idxb];
            c = arr[idxc];
            // printf("c2\n");
            if (a < c && c < b) {
                repeat = 0;
            }
            idxb += 1;
        }
        a = arr[idxa];
        b = arr[idxb];
        c = arr[idxc];
        // printf("c3\n");
        if (a < c && c < b) {
            repeat = 0;
        }
        idxa += 1;
    }

    if (!(a < c && c < b) && repeat) {
        printf("Santai\n");
    }else{
        printf("Nyalakan\n");
    }
}

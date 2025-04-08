#include <stdio.h>

int main(){
    int efektivitas (int arr[],int sorted[], int jumlah_virus, int n);
    void sorting (int sorted[], int n);
    int n, k, effect, temp_effect, hasil;
    int gkanan, gkiri;
    int arr[1001];
    int sorted[1001];

    scanf("%d %d", &n, &k);
    for(int i = 0; i<n; i++) scanf("%d", &arr[i]);

    //copy ke sorted
    // for(int i = 0; i<n; i++) sorted[i] = arr[i];
    // sorting(sorted, n);
    // for (int i = 0; i<n; i++) printf("%d\n", sorted[i]);
    /*cari maksimum apabila titik sebar virus hanya satu saja*/
    // hasil = efektivitas(arr, sorted, k, n);
    // printf("%d\n", hasil); 

    effect = 0;
    gkiri = arr[0];
    gkanan = arr[n-1];
    effect = gkiri + gkanan;
    for (int j = 1; j<n-1; j++){
        temp_effect = gkiri + gkanan + arr[j];
        if (temp_effect > effect) effect = temp_effect;
    }
    printf("%d\n", effect);
   
}

int efektivitas (int arr[],int sorted[], int jumlah_virus, int n){
    int effect, temp_effect;
    int gkanan, gkiri;
    if (jumlah_virus== 1){
        effect = 0;
        gkiri = arr[0];
        gkanan = arr[n-1];
        effect = gkiri + gkanan;
        for (int j = 1; j<n-1; j++){
            temp_effect = gkiri + gkanan + arr[j];
            if (temp_effect > effect) effect = temp_effect;
        }
    }else if(jumlah_virus> 1);
    return effect;
}
void sorting (int sorted[], int n){
    int temp, pass;
    int tukar = 1;
    while (n>1 && tukar == 1){
        tukar = 0;
        pass = 0;
        for (int i = n; i > pass + 1; i--){
            if (sorted[i] > sorted[i-1]){
                temp = sorted[i];
                sorted[i] = sorted[i-1];
                sorted[i-1] = temp;
                tukar = 1;
            }
        } pass += 1;   
    }
}
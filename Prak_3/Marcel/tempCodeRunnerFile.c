    temp = 0;
    for (int j = 1; j<= rot; j++){
        for (int k = N-1; j>1; j--){
            temp = arr[k];
            arr[k] = arr[k-1];
            arr[k-1] = temp;
        }
    }
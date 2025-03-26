#include "TekaTeki.h"

/**
 * Fungsi untuk menghitung kombinasi C(n, k) = n! / (k! * (n - k)!)
 * Note: jangan menggunakan perhitungan faktorial secara langsung, 
 * tetapi sederhanakan bentuk perhitungan kombinasi
 * @param n int
 * @param k int
 * @return Mengembalikan hasil kombinasi C(n, k) dalam bentuk long long
 */
long long int kombinasi(int n, int k){
    if (k == 0 || k == n) return 1;
    
    long long hasil = 1;
    if (k > n - k) k = n - k;  

    for (int i = 0; i < k; i++) {
        hasil = hasil * (n - i) / (i + 1); 
    }
    return hasil; 
}

/**
 * Fungsi untuk menghitung bilangan Catalan ke-N
 * Catalan(N) = C(2N, N) / (N + 1)
 * @param n int
 * @return Mengembalikan Catalan(n)
 */
long long int catalan(int n){
    float hasil;

    hasil = (kombinasi(2*n, n))/(n + 1);

    return hasil;
}

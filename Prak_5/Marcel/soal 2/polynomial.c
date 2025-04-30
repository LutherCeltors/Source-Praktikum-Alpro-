#include "polynomial.h"
 /**
  * Definisi dari ADT Polynomial
  * Sebuah Polynomial direpresentasikan oleh sebuah array of coefficients
  * dimana sebuah index menunjukkan eksponennya
  * Contoh: 3^2 + 2x + 1 direpresentasikan sebagai coeff[0] = 1, coeff[1] = 2, coeff[2] = 3
  */
 
//  typedef struct {
//      int coeff[MAX_DEGREE + 1];  // Array untuk menyimpan koefisien polynomial
//      int degree;                 // Derajat tertinggi sebuah polynomial
//  } Polynomial;
 
 /* ==================== Polynomial Operations ==================== */
 
 /* Konstruktor */
 void CreatePolynomial(Polynomial *p)
 /**
  * I.S. -
  * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi dengan 0.0
  * dan degree juga diinisialisasi dengan 0
  */
 {
    for (int i = 0; i <= MAX_DEGREE; i++) {
        p->coeff[i] = 0;
    }
    p->degree = 0;
 }
 void CreatePolynomialFromArray(Polynomial *p, int coeffArray[], int size)
 /**
  * I.S. CoeffArray adalah array of coefficients yang terdefinisi, 
  * size adalah ukuran dari coeffArray yang terdefinisi
  * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi berdasarkan coeffArray
  * dan degree diinisialisasikan dengan index tertinggi dari elemen coeffArray yang tidak nol
  */
 {  
    if (size != 0){
        for (int i = 0; i<size; i++){
            p->coeff[i] = coeffArray[i];
            if (p->coeff[i] != 0) p->degree = i;
        }
    }
 }
 
 /* Selektor */
 int GetCoefficient(Polynomial *p, int exponent)
 /**
  * Mengembalikan nilai koefisien pada suku dengan eksponen = exponent
  */
 {
    return p->coeff[exponent];
 }
 
 int GetDegree(Polynomial *p)
 /**
  * Mengembalikan derajat tertinggi dari polynomial dengan koefisien tak nol
  */
 {
    int test_degree = p->degree;
    int val = p->coeff[test_degree];
    if (val == 0){
        do {
            test_degree -= 1;
            val = p->coeff[test_degree]; 
        }while(val == 0);
        return test_degree;
    }else return test_degree;
 }
 int Evaluate(Polynomial *p, int x)
 /**
  * Mengembalikan hasil evaluasi polynomial p dengan masukan x
  * Contoh: 
  * p = 3x^2 + 3x + 1
  * Evaluate(p, 1) = 3(1^2) + 3(1) + 1 = 7
  */
 {
    int val = 0;
    for (int i = 0; i <= p->degree; i++){
        val += p->coeff[i]*pow(x,i);
    }
    return val;
 }
 /* Mutator */
 void SetCoefficient(Polynomial *p, int exponent, int coefficient)
 /**
  * I.S. Polynomial p, exponent, dan coefficient terdefinisi
  * F.S. Polynomial p diupdate dengan koefisien baru (coefficient)
  * pada suku dengan eksponen yang diberikan (exponent)
  */
 {
    p->coeff[exponent] = coefficient;
    if(exponent > p->degree && coefficient != 0){
        p->degree = exponent;
    }else if(exponent == p->degree && coefficient == 0){
        p->degree = GetDegree(p);
    }
 }
 /* Operasi Baca/Tulis */
 void ReadPolynomial(Polynomial *p)
 /**
  * I.S. Polynomial p belum terdefinisi
  * F.S. Polynomial p terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input
  * - Meminta input size yang merupakan banyak koefisien yang akan dimasukkan (dari koefisien 0)
  * - Meminta input koefisien sebanyak size dan menginisialisasi p berdasarkan nilai ini (dari koefisien 0)
  */
 {
    int size;
    scanf("%d", &size);
    for (int i = 0; i<size; i++){
        scanf("%d", &p->coeff[i]);  
    }
    p->degree = size-1;
    p->degree = GetDegree(p);

 }
 /* Operator Aritmatika */
 void AddPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result)
 /**
  * I.S. Polynomial p1 dan p2 terdefinisi
  * F.S. Hasil penjumlahan p1 dan p2 (p1 + p2) disimpan di polynomial result
  */
 {
    int i = 0;
    if (GetDegree(p1) >= GetDegree(p2)){
        result->degree = GetDegree(p1);
    }else result->degree = GetDegree(p2);
    for (int i = 0; i<= result->degree; i++){
        result->coeff[i] = 0;
    }
    while (i <= p1->degree && i <= p2->degree){
        result->coeff[i] = p1->coeff[i] + p2->coeff[i];
        i += 1;
    }
    while (i <= p1->degree){
        result->coeff[i] += p1->coeff[i]; 
        i+= 1;
    }
    while (i <= p2->degree){
        result->coeff[i] += p2->coeff[i];
        i++;
    }
 }
 
 void SubtractPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result)
 /**
  * I.S. Polynomial p1 dan p2 terdefinisi
  * F.S. Hasil pengurangan p1 dan p2 (p1 - p2) disimpan di polynomial result
  */
 {
    
    if (GetDegree(p1) >= GetDegree(p2)){
        result->degree = GetDegree(p1);
    }else result->degree = GetDegree(p2);

    for (int i = 0; i<= result->degree; i++){
        result->coeff[i] = 0;
    }
    int i = 0;
    while (i <= p1->degree && i <= p2->degree){
        result->coeff[i] = p1->coeff[i] - p2->coeff[i];
        i += 1;
    }
    while (i <= p1->degree){
        result->coeff[i] += p1->coeff[i]; 
        i+= 1;
    }
    while (i <= p2->degree){
        result->coeff[i] -= p2->coeff[i];
        i++;
    }
 }
 
 int IsEqual(Polynomial *p1, Polynomial *p2)
 /**
  * I.S. Polynomial p1 dan p2 terdefinisi
  * F.S. Mengembalikan 1 jika kedua polynomial adalah sama, dan 0 jika sebaliknya
  * Dua polynomial dianggap sama jika keduanya memiliki derajat yang sama dan semua koefisiennya bernilai sama
  */
 {
    int i = 1;
    p1->degree = GetDegree(p1);
    p2->degree = GetDegree(p2);
    if(p1->degree == p2->degree){
        for (int i = 0; i <= p1->degree; i++){
            if (p1->coeff[i] != p2->coeff[i]){
                i = 0;
                break;
            }
        }
    } else i = 0;
    return i;
 }
 
 /* Operasi Lain */
 void PrintPolynomial(Polynomial *p)
 /**
  * I.S. P terdefinisi
  * F.S. Polynomial p ditampilkan dengan aturan sebagai berikut:
  * - Elemen ditampilkan dari derajat paling tinggi ke derajat paling rendah
  * - Hanya tampilkan elemen dengan koefisien tak nol
  * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien positif, tidak perlu berikan tanda + di depan
  * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien negatif, tidak perlu berikan spasi antara tanda - dan suku (-x^n)
  * - Untuk suku yang bukan derajat tertinggi, tampilkan tanda + dan - dengan diberikan spasi (x^3 + 6x)
  * - Untuk koefisien 1, hanya tampilkan x^n (bukan 1x^n), kecuali untuk suku konstan
  * - Untuk koefisien -1, hanya tampilkan -x^n atau - x^n (bukan -1x^n dan - 1x^n), kecuali untuk suku konstan
  * - Untuk suku derajat 1, tampilkan x (bukan x^1)
  * - Untuk suku derajat 0, tampilkan koefisiennya saja
  * - Berikan newline (\n) di akhir baris
  * Contoh: -4x^3 + 3x^2 - 2x + 1
  */
{
    for (int i = p->degree; i >= 0; i--){
        if (p->coeff[i] != 0){
            if (i == p->degree){
                if (p->coeff[i] == 1) printf("x^%d", i);
                else printf("%dx^%d", p->coeff[i], i);
            }else if (i != p->degree){
                if (i != 0 && i != 1){
                    if (p->coeff[i] < 0 && p->coeff[i] != -1){
                        printf(" - %dx^%d", abs(p->coeff[i]), i);
                    }else if (p->coeff[i] > 0 && p->coeff[i] != 1){
                        printf(" + %dx^%d", p->coeff[i], i);
                    }else if (p->coeff[i] == 1){
                        printf(" + x^%d", i);
                    }else if (p->coeff[i] == -1){
                        printf(" - x^%d", i);
                    }
                }else if (i == 1){
                    if (p->coeff[i] < 0 && p->coeff[i] != -1){
                        printf(" - %dx", abs(p->coeff[i]), i);
                    }else if (p->coeff[i] > 0 && p->coeff[i] != 1){
                        printf(" + %dx", p->coeff[i], i);
                    }else if (p->coeff[i] == 1){
                        printf(" + x", i);
                    }else if (p->coeff[i] == -1){
                        printf(" - x", i);
                    }
                }else if (i == 0){
                    if (p->coeff[i] < 0){
                        printf(" - %d", abs(p->coeff[0]));
                    }else{
                        printf(" + %d", p->coeff[0]);
                    }
                }
            }
        }
    }
    printf("\n");
}

// int main(){
//     Polynomial *p = (Polynomial *) malloc(sizeof(Polynomial));

//     ReadPolynomial(p);
//     PrintPolynomial(p);

//     free(p);
// }
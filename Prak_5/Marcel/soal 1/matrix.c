/* Konstruktor */
#include "matrix.h"
// #ifndef MATRIX_H
// #define MATRIX_H
// #include <stdbool.h>
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #define MAX_ROWS 100
// #define MAX_COLS 100

// typedef struct
// {
//   float data[MAX_ROWS][MAX_COLS];
//   int rows;
//   int cols;
// } Matrix;

void CreateMatrix(int rows, int cols, Matrix *M)
/* I.S. rows dan cols terdefinisi dan valid (1 <= rows,cols <= MAX) */
/* F.S. Terbentuk matrix M dengan ukuran rows x cols */
/* Semua elemen diinisialisasi dengan 0.0 */
{
    if (rows >= 1 && rows <= MAX_ROWS && cols >= 1 && cols <= MAX_COLS){
        M->rows = rows;
        M->cols = cols;
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                M->data[i][j] = 0.0;
            }
        }
    }
}

/* Selector */
int GetRows(Matrix M)
/* Mengembalikan jumlah baris matrix M */
{
    return M.rows;
}

int GetCols(Matrix M)
/* Mengembalikan jumlah kolom matrix M */
{
    return M.cols;
}

float *GetElement(Matrix *M, int row, int col)
/* Mengembalikan pointer ke elemen matrix M pada baris row dan kolom col */
/* Mengembalikan NULL jika row atau col tidak valid untuk matrix M */
{
    if ((M->rows) > row && (M->cols) > col && row >= 0 && col >= 0) return &M->data[row][col];
    else return NULL;
}

/* Mutator */
bool SetElement(Matrix *M, int row, int col, float value)
/* I.S. M terdefinisi */
/* F.S. Jika row dan col valid, elemen M pada baris row dan kolom col bernilai value, mengembalikan true */
/*      Jika row atau col tidak valid, mengembalikan false */
{
    bool status;
    if ((M->rows) > row && (M->cols) > col && row >= 0 && col >= 0){
        M->data[row][col] = value;
        status = true;
    }else status = false;
    return status;
}

/* Operasi Baca/Tulis */
void ReadMatrix(Matrix *M)
/* I.S. M belum terdefinisi */
/* F.S. M terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input */
/*      Meminta input ukuran matrix (rows, cols) hingga valid
        Valid: 0 < rows < MAX_ROWS and 0 < cols < MAX_COLS */
/*      Meminta input elemen matrix M sebanyak rows * cols 
        Format input: Setiap elemen dipisahkan oleh spasi
        Contoh input: 
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
        Contoh input tidak valid:
        -1 -1
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
*/
{
    int rows, cols;
    do {
        scanf("%d %d", &rows, &cols);       
    } while (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS);
    M->rows = rows; M->cols = cols;

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            scanf("%f", &M->data[i][j]);
        }
    }
    

}

void PrintMatrix(Matrix M)
/* I.S. M terdefinisi */
/* F.S. Seluruh elemen M tertulis ke layar dalam format matrix */
/* Baris dipisahkan oleh newline, kolom dipisahkan oleh spasi */
/* Format output: Setiap elemen diformat "%.2f" */
{
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            printf("%.2f ", M.data[i][j]);
        }printf("\n");
    }
}

/* Operator Relasional */
bool IsSquare(Matrix M)
/* Mengembalikan true jika M adalah matrix persegi (rows = cols) */
{
    bool status;
    if (M.rows == M.cols) status = true;
    else status = false;
    return status;
}

bool IsSymmetric(Matrix M)
/* Mengembalikan true jika M adalah matrix simetrik terhadap diagonal */
/* Matrix simetrik adalah matrix yang memiliki elemen tercermin oleh diagonal*/
/* Prekondisi: M adalah matrix persegi */
{
    bool check = true;
    for (int i = 0; i < M.cols; i++){
        for (int j = 0; j < M.rows; j++){
            if (i != j && M.data[i][j] != M.data[j][i]) check = false;
        }
    }
    return check;
}

bool IsDiagonallyDominant(Matrix M)
/* Mengembalikan true jika M adalah matrix diagonal dominant */
/* |a[i][i]| > sum(|a[i][j]|) untuk j != i pada setiap baris i */
/* Hint: Gunakan fabs untuk melakukan abs terhadap float */
{
    int sum = 0;
    bool isdominant = true;
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            if (j != i){
                sum += fabs(M.data[i][j]);
            }
        }if (sum >= fabs(M.data[i][i])){
            isdominant = false;
            break;
        }
    }
    return isdominant;
}

/* Operator Aritmatika */
Matrix *MultiplyMatrix(Matrix M1, Matrix M2)
/* Menghasilkan hasil perkalian matrix M1 dan M2 */
/* Mengembalikan NULL jika jumlah kolom M1 != jumlah baris M2 */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */
{   
    Matrix *pointer = (Matrix*)malloc(sizeof(Matrix));
    
    int mcol, mrow;
    mcol = 0; mrow = 0;
    // pointer->data[mrow][mcol] = 0;
    // if (M1.cols == M2.rows){
    //     while (mrow < M2.cols && mcol < M1.rows){
    //         for (int i = 0; i < M1.rows; i++){
    //             mrow += 1;
    //             for (int j = 0; j < M1.cols; j++){
    //                 pointer->data[mrow][mcol] += M1.data[i][j]*M2.data[j][mcol];
    //             }
    //         }
    //         mcol += 1;
    //     }
    // }
    if (M1.cols == M2.rows){
        CreateMatrix(M1.rows, M2.cols, pointer);
        for (int irow_p = 0; irow_p < pointer->rows; irow_p++){
            for (int icol_p = 0; icol_p < pointer->cols; icol_p++){
                for (int ishr = 0; ishr < M1.cols; ishr++){
                    pointer->data[irow_p][icol_p] += M1.data[irow_p][ishr]*M2.data[ishr][icol_p];
                }
            }
        }
        return pointer;
    }else return NULL;
}

Matrix *AddMatrix(Matrix M1, Matrix M2)
/* Menghasilkan hasil penjumlahan matrix M1 dan M2 */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */
{   
    Matrix *M = (Matrix*)malloc(sizeof(Matrix));
    if (M1.rows == M2.rows && M1.cols == M2.cols){
        M->cols = M1.cols; M->rows = M1.rows;
        for (int i = 0; i < M1.rows; i++){
            for (int j = 0; j < M1.cols; j++){
                M->data[i][j] = M1.data[i][j] + M2.data[i][j];     
            }
        }
    }else return NULL;
    return M;
}

Matrix *SubtractMatrix(Matrix M1, Matrix M2)
/* Menghasilkan hasil pengurangan matrix M1 dan M2 (M1 - M2) */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */
{
    Matrix *M = (Matrix*)malloc(sizeof(Matrix));
    if (M1.rows == M2.rows && M1.cols == M2.cols){
        M->cols = M1.cols; M->rows = M1.rows;
        for (int i = 0; i < M1.rows; i++){
            for (int j = 0; j < M1.cols; j++){
                M->data[i][j] = M1.data[i][j] - M2.data[i][j];     
            }
        }
    }else return NULL;
    return M;
}

Matrix MultiplyScalar(Matrix M, float scalar)
/* Menghasilkan hasil perkalian matrix M dengan skalar scalar */
/* Prekondisi: M terdefinisi dan skalar terdefinisi */
/* Hint: Buat matrix baru untuk menyimpan hasil */
{   
    Matrix Ms;
    CreateMatrix(M.rows, M.cols, &Ms);
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            Ms.data[i][j] = M.data[i][j]*scalar;     
        }
    }
    return Ms;
}

Matrix GetTranspose(Matrix M)
/* Menghasilkan matrix transpose dari M */
/* Hint: Buat matrix baru untuk menyimpan hasil */
{
    Matrix Mt;
    CreateMatrix(M.cols, M.rows, &Mt);
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            Mt.data[j][i] = M.data[i][j];     
        }
    }
    return Mt;
}
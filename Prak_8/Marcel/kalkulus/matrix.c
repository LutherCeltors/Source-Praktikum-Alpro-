#include "matrix.h"
#define boolean unsigned char
#define True 1
#define False 0
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    if (nRows >= 1 && nRows <= ROW_CAP && nCols >= 1 && nCols <= COL_CAP){
        m->rowEff = nRows;
        m->colEff = nCols;
        for (int i = 0; i<nRows; i++){
            for (int j = 0; j<nCols; j++){
                m->mem[i][j] = 0.0;
            }
        }
    }
}
/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan True jika i, j adalah index yang valid untuk matriks apa pun */
{
    return(i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return m.rowEff -1;
}
IdxType getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return m.colEff - 1;
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
/* Mengirimkan True jika i, j adalah Index efektif bagi m */
{
    if (i >= 0 && i < m.rowEff && j >= 0 && j < m.colEff) return True;
    else return False;
}
ElType getElmtDiagonal(Matrix m, IdxType i)
/* Mengirimkan elemen m(i,i) */
{
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    mOut->colEff =  mIn.colEff;
    mOut->rowEff =  mIn.rowEff;
    for (int i = 0; i < mIn.rowEff; i++){
        for (int j = 0; j < mIn.colEff; j++){
            mOut->mem[i][j] = mIn.mem[i][j];
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    if (isMatrixIdxValid(nRow, nCol)){
        m->rowEff = nRow;
        m->colEff = nCol;
        for (int i=0; i<nRow; i++){
            for (int j=0; j<nCol; j++){
                scanf("%f", &m->mem[i][j]);
            }
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j <m.colEff; j++){
            printf("%d", m.mem[i][j]);
            if (j < m.colEff -1){
                printf(" ");
            }
        }
        if (i < m.rowEff -1){
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    Matrix sumMatrix;
    if (m1.colEff == m2.colEff && m1.rowEff == m2.rowEff){
        createMatrix(m1.rowEff, m2.colEff, &sumMatrix);
        for (int i = 0; i < m1.rowEff; i++){
            for (int j = 0; j < m2.colEff; j++){
               sumMatrix.mem[i][j] = m1.mem[i][j] + m2.mem[i][j];
            }
        }
    }
    return sumMatrix;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    Matrix subMatrix;
    if (m1.colEff == m2.colEff && m1.rowEff == m2.rowEff){
        createMatrix(m1.rowEff, m2.colEff, &subMatrix);
        for (int i = 0; i < m1.rowEff; i++){
            for (int j = 0; j < m2.colEff; j++){
               subMatrix.mem[i][j] = m1.mem[i][j] - m2.mem[i][j];
            }
        }
    }
    return subMatrix;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Matrix mult;
    if (m2.rowEff == m1.colEff){
        createMatrix(m1.rowEff, m2.colEff, &mult);
        for (int row_mul = 0; row_mul < m1.rowEff; row_mul++){
            for (int col_mul = 0; col_mul < m2.colEff; col_mul++){
                for (int rwcl_mtx = 0; rwcl_mtx < m2.rowEff; rwcl_mtx++){
                    mult.mem[row_mul][col_mul] += m1.mem[row_mul][rwcl_mtx] * m2.mem[rwcl_mtx][col_mul]; 
                }
            }
        }
    }
    return mult;
}
Matrix multiplyByConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    Matrix multc;
    multc.rowEff = m.rowEff;
    multc.colEff = m.colEff;
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            multc.mem[i][j] = m.mem[i][j] * x; 
        }
    }
    return multc;
}
void pMultiplyByConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    for (int i = 0; i < m->rowEff; i++){
        for (int j = 0; j < m->colEff; j++){
            m->mem[i][j] = m->mem[i][j] * k; 
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
/* Mengirimkan True jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
{
    if (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2)){
        for (int i = 0; i < ROW_EFF(m1); i++) {
            for (int j = 0; j < COL_EFF(m1); j++) {
                if (ELMT(m1, i, j) != ELMT(m2, i, j)) return False;
            }
        }
        return True;
    }else return False;
}
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan True jika m1 tidak sama dengan m2 */
{
    if (isMatrixEqual(m1, m2)){
        return False;
    }else{
        return True;
    }
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan True jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    if (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2)) return True;
    else return False;
}
/* ********** Operasi lain ********** */
int countElmt(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return ROW_EFF(m) * COL_EFF(m);
}
/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan True jika m adalah matriks dg ukuran baris dan kolom sama */{
    if (m.colEff == m.rowEff) return True;
    else return False;
}
boolean isSymmetric(Matrix m)
/* Mengirimkan True jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    if (isSquare(m)){
        for (int i = 0; i < m.rowEff; i++ ){
            for (int j = 0; j < m.colEff; j++){
                if (ELMT(m, i, j) != ELMT(m, j ,i)) return False;
            }
        }
        return True;
    }else return False;
}
boolean isIdentity(Matrix m)
/* Mengirimkan True jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    if (!isSquare(m)) return False;
    for (int i = 0; i < m.rowEff; i++) {
        for (int j = 0; j < m.colEff; j++) {
            if (i == j && ELMT(m, i, j) != 1) return False;
            if (i != j && ELMT(m, i, j) != 0) return False;
        }
    }
    return True;
}
boolean isSparse(Matrix m)
/* Mengirimkan True jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    int countNonZero = 0;
    int total = countElmt(m);
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) countNonZero++;
        }
    }
    return (countNonZero <= (total * 5 / 100));

}
Matrix negation(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
{
    return multiplyByConst(m, -1);
}
void pNegation(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    pMultiplyByConst(m, -1);
}
float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    if (!isSquare(m)) return 0;
    int n = ROW_EFF(m);
    if (n == 1) return ELMT(m, 0, 0);
    if (n == 2) return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0);

    float det = 0;
    for (int x = 0; x < n; x++) {
        Matrix sub;
        createMatrix(n - 1, n - 1, &sub);
        for (int i = 1; i < n; i++) {
            int colSub = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                ELMT(sub, i - 1, colSub++) = ELMT(m, i, j);
            }
        }
        float sign = (x % 2 == 0) ? 1 : -1;
        det += sign * ELMT(m, 0, x) * determinant(sub);
    }
    return det;

}
Matrix transpose(Matrix m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix r;
    createMatrix(COL_EFF(m), ROW_EFF(m), &r);
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            ELMT(r, j, i) = ELMT(m, i, j);
        }
    }
    return r;

}
void pTranspose(Matrix *m)
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix temp = transpose(*m);
    copyMatrix(temp,m);
}

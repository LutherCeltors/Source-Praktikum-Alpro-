#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    Matrix A, B;

    printf("Enter matrix A:\n");
    ReadMatrix(&A);
    printf("Matrix A:\n");
    PrintMatrix(A);
    printf("cols : %d\n", GetCols(A));
    printf("rows : %d\n", GetRows(A));

    printf("\nEnter matrix B:\n");
    ReadMatrix(&B);
    printf("Matrix B:\n");
    PrintMatrix(B);

    // Addition
    Matrix *Sum = AddMatrix(A, B);
    if (Sum != NULL) {
        printf("\nA + B:\n");
        PrintMatrix(*Sum);
        free(Sum);
    } else {
        printf("\nCannot add A and B (incompatible dimensions).\n");
    }

    // Subtraction
    Matrix *Diff = SubtractMatrix(A, B);
    if (Diff != NULL) {
        printf("\nA - B:\n");
        PrintMatrix(*Diff);
        free(Diff);
    } else {
        printf("\nCannot subtract A and B (incompatible dimensions).\n");
    }

    // Multiplication
    Matrix *Prod = MultiplyMatrix(A, B);
    if (Prod != NULL) {
        printf("\nA * B:\n");
        PrintMatrix(*Prod);
        free(Prod);
    } else {
        printf("\nCannot multiply A and B (incompatible dimensions).\n");
    }

    // Scalar multiplication
    float scalar = 2.0;
    Matrix Scaled = MultiplyScalar(A, scalar);
    printf("\nA * %.2f:\n", scalar);
    PrintMatrix(Scaled);

    // Transpose
    Matrix TA = GetTranspose(A);
    printf("\nTranspose of A:\n");
    PrintMatrix(TA);

    // Relational checks
    printf("\nMatrix A is %ssquare.\n", IsSquare(A) ? "" : "not ");
    if (IsSquare(A)) {
        printf("Matrix A is %ssymmetric.\n", IsSymmetric(A) ? "" : "not ");
    }
    printf("Matrix A is %sdiagonally dominant.\n", IsDiagonallyDominant(A) ? "" : "not ");

    return 0;
}

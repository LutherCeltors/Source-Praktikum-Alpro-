#include "matrix.h"

int main(){
    Matrix M;
    CreateMatrix(4, 4, &M);
    PrintMatrix(M);
    ReadMatrix(&M);
    PrintMatrix(M);
    printf("%d\n", GetCols(M));
    printf("%d\n", GetRows(M));
    float *fptr = GetElement(&M, 1, 4);
    if (fptr != NULL){
        printf("%.2f\n", (*fptr));
    }else{
        printf("Invalid position.\n");
    }
    printf("%.2f\n", (*GetElement(&M, 1, 1)));
    bool status = SetElement(&M, 1, 3, 4.2);
    PrintMatrix(M);
    printf("%d\n", status);
    ReadMatrix(&M);
    PrintMatrix(M);
    printf("Is Symetric : %d\n", IsSymmetric(M));
    printf("Is Diagonal Dominant : %d\n", IsDiagonallyDominant(M));
}
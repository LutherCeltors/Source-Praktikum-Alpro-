#include <stdio.h>

int main() {
    int n;
    
    // Taking user input for matrix size
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    int arr[n][n]; 
    int num = 1;

    // Filling diagonally from top-left to bottom-right (row-wise)
    for (int d = 0; d < 2 * n - 1; d++) {
        int row = (d < n) ? d : n - 1;
        int col = (d < n) ? 0 : d - n + 1;
        
        while (row >= 0 && col < n) {
            arr[col][row] = num++;  // Swap row and col to get correct order
            row--;
            col++;
        }
    }

    // Printing the matrix
    printf("Generated %d x %d pattern:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

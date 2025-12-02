// Write a program to display the non-zero elements of the sparse array.

#include <stdio.h>

int main() {
    int rows, cols, i, j;

    // Input matrix size
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    // Input matrix elements
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display non-zero elements
    printf("\nNon-zero elements in the sparse matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                printf("Element at [%d][%d] = %d\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}

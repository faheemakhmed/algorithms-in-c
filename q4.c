//program to creaate a 2-D array and display the elements of the array
#include <stdio.h>

int main() {
    int rows, cols, i, j;

    // Input number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare the 2-D array
    int arr[rows][cols];

    // Input elements
    printf("Enter the elements of the %dx%d array:\n", rows, cols);
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the array
    printf("\nThe 2-D array is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

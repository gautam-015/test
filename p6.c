#include <stdio.h>

#define MAX 100

void convertToSparse(int matrix[MAX][MAX], int rows, int cols) {
    int sparse[MAX][3]; // [0] = row, [1] = col, [2] = value
    int k = 1; // start from index 1, index 0 will store metadata

    // Traverse matrix and store non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Store metadata in first row
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;

    // Print the sparse matrix
    printf("\nSparse Matrix Representation (Triple Format):\n");
    printf("Row  Col  Value\n");
    for (int i = 0; i < k; i++) {
        printf("%3d  %3d  %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int matrix[MAX][MAX];
    int rows, cols;

    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    convertToSparse(matrix, rows, cols);

    return 0;
}
#include <stdio.h>
#include <stdlib.h> // For malloc() and free()

#define N 1000 // Adjust this to test larger matrix sizes

void displayMatrix(int** matrix, int n) 
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiply(int** A, int** B, int** C, int n) 
{
    //Loop through rows of C and A
    for (int i = 0; i < n; i++){
        //Loop through columns of C and B
        for (int j = 0; j < n; j++){
            //Loop through columns of row i for A and row of column j of B
            for (int m = 0; m < n; m++){
                C[i][j] += A[i][m] * B[m][j];
            }
        }
    }
}
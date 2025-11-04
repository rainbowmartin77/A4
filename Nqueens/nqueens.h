#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isSafe(int board[], int row, int col, int n) 
{
    for (int i = 0; i < col; i++) {
        if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(int board[], int col, int n) 
{
    // Base case
    // All column have been gone through
    if (col == n) {
        // print the solution
        printf("The board is solved:\n");
        for( int i = 0; i < n; i++) {
            printf("%d", board[i]);
        }
        printf("\n");
        return;
    }

    // Recursive case
    // Looping through the rows
    for(int row = 0; row < n; row++) {
        // If the position is safe, place the queen in that row and column
        // and recursively call this function for the next column
        if (isSafe(board, row, col, n)) {
            board[col] = row;
            solveNQueensUtil(board, col+1, n);
        }
    }
    
    return;
}
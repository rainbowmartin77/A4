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

int solveNQueensUtil(int board[], int col, int n) 
{
    int solutions = 0;

    // Base case
    // All column have been gone through
    if (col == n) {
        return 1;
    }

    // Recursive case
    // Looping through the rows
    for(int row = 0; row < n; row++) {
        // If the position is safe, place the queen in that row and column
        // and recursively call this function for the next column
        if (isSafe(board, row, col, n)) {
            board[col] = row;
            solutions += solveNQueensUtil(board, col+1, n);
        }
    }
    
    return solutions;
}
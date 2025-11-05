#include "nqueens.h"

int main() 
{
    int n = 15;

    // Allocate memory for board
    int* board = (int*)malloc(n * sizeof(int));
    if (board == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize board
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }

    int solutions = 0;
    solutions = solveNQueensUtil(board, 0, n);

    printf("There are %d solutions.\n", solutions);

    free(board);
    return 0;
}
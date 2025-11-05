#include "nqueens.h"
#include <omp.h>

int main() 
{
    omp_set_num_threads(7);
    int n = 15;
    int solutions = 0;

    // Allocate memory for board
    // Parallelize board? Use dynamic scheduling for load balancing
    // Each thread needs its own board so they don't overwrite each other
    #pragma omp parallel for schedule(dynamic) reduction(+:solutions)
    for (int row = 0; row < n; row++)
    {
        // Allocate memory for the boards
        int* board = (int*)malloc(n * sizeof(int));
        if (board == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            continue;
        }

        // Initialize board
        for (int i = 0; i < n; i++) {
            board[i] = -1;
        }

        // Set the start of the board for each thread
        board[0] = row;
    
        // Accumulate solutions
        solutions += solveNQueensUtil(board, 1, n);

        free(board);
    }

    printf("There are %d solutions.\n", solutions);

    return 0;
}
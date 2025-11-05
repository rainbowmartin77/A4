#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000

int main() 
{
    // Set number of threads
    omp_set_num_threads (7);
    
    // Initialize array
    int* arr = (int*)malloc(SIZE * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; 
    }

    // Shared variables
    long long total = 0;
    int n = SIZE;
    long long thisTotal = 0;

    // Parallel portion
    #pragma omp parallel for reduction (+:total) 
    for(int x = 0; x < n; x++)
    {
        total += arr[x];
    }

    printf("Total Sum: %lld\n", total);

    return 0;
}
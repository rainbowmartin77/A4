#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000
#define NUM_THREADS 9

int main() 
{
    long long total = 0;

    omp_set_num_threads (NUM_THREADS);
    
    // Initialize array
    int* arr = (int*)malloc(SIZE * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; 
    }

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        long long thisTotal = 0;

        long long divide = (SIZE + NUM_THREADS - 1) / NUM_THREADS;
        long long start = id * divide;
        long long end = (start + divide > SIZE) ? SIZE : start + divide;

        for (long long i = start; i < end; i++) {
            thisTotal += arr[i];
        }

        #pragma omp critical
        {
            total += thisTotal;
        }
    }

    printf("Total Sum: %lld\n", total);

    return 0;
}

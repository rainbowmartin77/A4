#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000

int main() 
{
    //omp_set_num_threads (9);
    
    int* arr = (int*)malloc(SIZE * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; 
    }

    long long total = 0;
    int n = SIZE;

    for(int x = 0; x < n; x++) {
        total += arr[x];
    }

    printf("Total Sum: %lld\n", total);

    return 0;
}
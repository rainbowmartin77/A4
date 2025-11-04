#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000000

long long sumArray(int arr[], int size) 
{
    long long total = 0;
    int n = SIZE;

    for(int x = 0; x < n; x++) {
        total += arr[x];
    }

    return total;
}

int main() 
{
    
    int* arr = (int*)malloc(SIZE * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1; 
    }

    long long totalSum = sumArray(arr, SIZE);
    printf("Total Sum: %lld\n", totalSum);

    return 0;
}
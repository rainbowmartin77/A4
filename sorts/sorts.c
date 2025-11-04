#include "sorts.h"

// Merge Sort 
static void merge(int arr[], int left, int mid, int right) 
{
    int x = mid - left + 1;
    int y = right - mid;

    // Temporary arrays
    int templ[x], tempr[y];

    // Copy data from the two arrays into the temporary arrays
    for (int i = 0; i < x; i++) {
        templ[i] = arr[left + i];
    }
    for (int j = 0; j < y; j++) {
        tempr[j] = arr[mid + 1 + j];
    }

    int p = 0; // templ index
    int o = 0; // tempr index
    int t = left; // merged array index, starting at 0

    // Loop through both arrays within their respective sizes
    while (p < x && o < y) {
        // if the index of temp left is less than or equal to temp right, move temp left into the next index of the merged array
        if (templ[p] <= tempr[o]) {
            arr[t] = templ[p];
            p++;
        }
        // else move temp right into the index of the merged array
        else {
            arr[t] = tempr[o];
            o++;
        }
        // Move to the next index of the merged array
        t++;
    }

    // Move remaining elements in templ into merged array
    while (p < x) {
        arr[t] = templ[p];
        p++;
        t++;
    }

    // Move remaining elements in tempr into merged array
    while(o < y) {
        arr[t] = tempr[o];
        o++;
        t++;
    }

    
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) 
{
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
#include "algo.h"

static int arr_size;

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { 
            i++;
            swap(arr + i, arr + j);
            step(arr, arr_size);
        }
    }
    
    swap(arr + i + 1, arr + high);

    return (i + 1);
} 
  
void _quicksort(int *arr, int low, int high) { 
    if (low < high) {
        int pi = partition(arr, low, high);
        _quicksort(arr, low, pi - 1);
        _quicksort(arr, pi + 1, high);
    } 
} 

const void *quicksort(int *arr, int size) {
    arr_size = size;
    _quicksort(arr, 0, size - 1);
    return NULL;
}

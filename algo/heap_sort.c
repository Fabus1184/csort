#include "algo.h"

void heapify(uint32_t *arr, size_t n, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
     if (largest != i) {
        size_t tmp = arr[i] ;
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, n, largest);
    }
}
 
void heap_sort(uint32_t *arr, size_t size)
{
    for (int64_t i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    } 
 
    for (int64_t i = size - 1; i >= 0; i--) {
        uint32_t tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);

        step(arr, size);
    }
    
}

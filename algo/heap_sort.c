#include "algo.h"

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
     if (largest != i) {
        int tmp = arr[i] ;
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify(arr, N, largest);
    }
}
 
const void *heap_sort(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    } 
 
    for (int i = size - 1; i >= 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);

        step(arr, size);
    }
    return NULL;
}

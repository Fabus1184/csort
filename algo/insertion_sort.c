#include "algo.h"

void insertion_sort(int *arr, int size, void (*step)(int*, int)) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
  
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;

        }
        arr[j + 1] = key;

        step(arr, size);
    }
}
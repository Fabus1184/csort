#include "algo.h"

void insertion_sort(uint32_t *arr, size_t size) {
    size_t i, key;
    int64_t j;
    
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

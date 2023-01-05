#include "algo.h"

void bogo_sort(uint32_t *arr, size_t size) {
    while(!is_sorted(arr, size)) {
        size_t n = rand() % size, m = rand() % size, tmp = arr[n];
        arr[n] = arr[m];
        arr[m] = tmp;

        step(arr, size);
    }
    
}

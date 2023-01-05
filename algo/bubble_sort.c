#include "algo.h"

void bubble_sort(uint32_t *arr, size_t size) {
    while (!is_sorted(arr, size)) {
        for (size_t i = 1; i < size; i++) {
            if (arr[i] < arr[i - 1]) {
                size_t tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;

                step(arr, size);
            }
        }
    }
    
}

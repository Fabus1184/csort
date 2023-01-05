#include "algo.h"

bool is_sorted(uint32_t *arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void swap(uint32_t *x, uint32_t *y) {
    uint32_t k = *x;
    *x = *y;
    *y = k;
}

#include "algo.h"

size_t arr_size;

void bitonic_merge(uint32_t *arr, size_t start, size_t seq_size, bool dir) {
    if (seq_size > 1) {
        size_t k = seq_size / 2;
        for (size_t i = 0; i < k; i++) {
            if ((start + i + k) < arr_size) {
                if (dir == (arr[start + i] > arr[start + i + k])) {
                    swap(arr + start + i, arr + start + i + k);
                    step(arr, arr_size);
                }
            } else break;
        }
        bitonic_merge(arr, start, k, dir);
        bitonic_merge(arr, start + k, k, dir);
   }
}
void _bitonic_sort(uint32_t *arr, size_t start, size_t seq_size, bool dir) {
    if (seq_size > 1) {
        size_t k = seq_size / 2;
        _bitonic_sort(arr, start, k, true);
        _bitonic_sort(arr, start + k, k, false);
        bitonic_merge(arr, start, seq_size, dir);
   }
}

size_t next_power_of_two(size_t x) {
    for (size_t i = 1; ; i *= 2) {
        if (i > x) return i;
    }
}

void bitonic_sort(uint32_t *_arr, size_t size) {
    arr_size = size;

    size_t npot = next_power_of_two(size);

    uint32_t *arr = malloc(npot * sizeof(uint32_t));
    memcpy(arr, _arr, size * sizeof(uint32_t));
    memset(arr + size, 0xFF, (npot - size) * sizeof(uint32_t));

    _bitonic_sort(arr, 0, npot, true);
    
    memcpy(_arr, arr, size * sizeof(uint32_t));
    free(arr);
}

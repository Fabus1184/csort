#include "algo.h"

#include <stdio.h>

void counting_sort(uint32_t *arr, size_t size) {
    uint32_t _arr[size];

    size_t _i = 0;
    for (size_t n = 0; n <= RAND_ARRAY_MAX; n++) {
        for (size_t i = 0; i < size; i++) {
            if (arr[i] == n) {
                _arr[_i++] = n;
                step(_arr, _i);
            }
        }
    }
    
    memcpy(arr, _arr, size * sizeof(uint32_t));    
}

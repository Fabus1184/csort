#include "algo.h"

static size_t arr_size;

size_t partition(uint32_t pivot, uint32_t *smaller, uint32_t *bigger, uint32_t *arr, size_t size) {
    size_t bigger_size = 0;
    size_t smaller_size = 0;

    for (size_t i = 0; i < size; i++) {
        uint32_t x = arr[i];
        if (x < pivot) {
            smaller[smaller_size++] = x;            
        } else {
            bigger[bigger_size++] = x;
        }
    }

    return smaller_size;
}


void _quicksort(uint32_t *arr, size_t size) {
    if (size > 1) {
        uint32_t pivot = *arr;
        uint32_t bigger[size], smaller[size];

        size_t smaller_size = partition(pivot, smaller, bigger, arr + 1, size - 1);
        _quicksort(smaller, smaller_size);
        _quicksort(bigger, size - smaller_size - 1);

        memcpy(arr, smaller, smaller_size * sizeof(uint32_t));
        arr[smaller_size] = pivot;
        memcpy(arr + smaller_size + 1, bigger, (size - smaller_size - 1) * sizeof(uint32_t));
    }
}


void quicksort(uint32_t *arr, size_t size) {
    arr_size = size;
    _quicksort(arr, size);
}

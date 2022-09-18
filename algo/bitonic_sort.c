#include "algo.h"

static int arr_size;

void bitonic_merge(int *arr, int start, int seq_size, int direction) {
    if (seq_size > 1) {
        int k = seq_size / 2;
        for (int i = start; i < start + k; i++) {
            if (direction == (arr[i] > arr[i + k])) {
                swap(arr + i, arr + i + k);
                if (i < arr_size) {
                    step(arr, arr_size);
                }
            }
        }
        bitonic_merge(arr, start, k, direction);
        bitonic_merge(arr, start + k, k, direction);
   }
}
void _bitonic_sort(int *arr, int start, int seq_size, int direction) {
    if (seq_size > 1) {
        int k = seq_size / 2;
        _bitonic_sort(arr, start, k, 1);
        _bitonic_sort(arr, start + k, k, 0);
        bitonic_merge(arr, start, seq_size, direction);
   }
}

int next_power_of_two(int x) {
    for (int i = 1; ; i *= 2) {
        if (i > x) return i;
    }
}

const void *bitonic_sort(int *_arr, int size) {
    arr_size = size;

    int npot = next_power_of_two(size);
    int *arr = malloc(npot * sizeof(int));

    memcpy(arr, _arr, size * sizeof(int));
    for (int i = size; i < npot; i++) {
        arr[i] = RAND_ARRAY_MAX;
    }
    
    _bitonic_sort(arr, 0, npot, 1);

    memcpy(_arr, arr, size);
    free(arr);
    
    return NULL;
}

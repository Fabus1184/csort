#include "algo.h"

void counting_sort(int *arr, int size, void (*step)(int*, int)) {
    int _arr[size];
    memcpy(_arr, arr, size * sizeof(int));
    int _i = 0;
    for (int n = 0; n <= 255; n++) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == n) {
                _arr[_i++] = n;
            }
        }

        step(arr, size);
    }
    
    memcpy(arr, _arr, size * sizeof(int));
}

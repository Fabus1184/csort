#include "algo.h"

const void *bubble_sort(int *arr, int size, const void *step(int*, int)) {
    while (!is_sorted(arr, size)) {
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[i - 1]) {
                int tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;

                step(arr, size);
            }
        }
    }
    return NULL;
}

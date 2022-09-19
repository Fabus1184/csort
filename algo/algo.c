#include "algo.h"

bool is_sorted(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

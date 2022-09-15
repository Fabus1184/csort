#include "algo.h"

void bogo_sort(int *arr, int size, void (*step)(int*, int)) {
    while(!is_sorted(arr, size)) {
        int n = rand() % size, m = rand() % size, tmp = arr[n];
        arr[n] = arr[m];
        arr[m] = tmp;

        step(arr, size);
    }
}
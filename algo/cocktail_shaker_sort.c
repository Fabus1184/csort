#include "algo.h"

void cocktail_shaker_sort(uint32_t *arr, size_t size) {
    bool swapped = true;
    size_t start = 0;
    size_t end = size - 1;
 
    while (swapped) {
        swapped = false; 
        for (size_t i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                size_t tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;

                step(arr, size);
            }
        }
        
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;

        for (int64_t i = end - 1; i >= (int64_t) start; --i) {
            if (arr[i] > arr[i + 1]) {
                size_t tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;

                step(arr, size);
            }
        }
        ++start;
    }
}

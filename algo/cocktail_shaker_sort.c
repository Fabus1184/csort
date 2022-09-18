#include "algo.h"

const void *cocktail_shaker_sort(int *arr, int size) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;
 
    while (swapped) {
        swapped = false; 
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
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

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;

                step(arr, size);
            }
        }
        ++start;
    }
    return NULL;
}

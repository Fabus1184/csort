#include "algo.h"

void selection_sort(int *arr, int size, void (*step)(int*, int))
{
    step(arr, size);
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if(min_idx != i) {
            int tmp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = tmp;

            step(arr, size);
        }    
    }
}

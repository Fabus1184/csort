#include "algo.h"

void merge(uint32_t *arr, size_t size, size_t l, size_t m, size_t r) {
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
  
    size_t L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;

	    step(arr, size);
    }

  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    	step(arr, size);
    }
    

	while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    	step(arr, size);
    }
}

void _merge_sort(uint32_t *arr, size_t size, size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;
  
        _merge_sort(arr, size, l, m);
        _merge_sort(arr, size, m + 1, r);

        merge(arr, size, l, m, r);
    }
}

void merge_sort(uint32_t *arr, size_t size) {
	_merge_sort(arr, size, 0, size - 1);
	
}

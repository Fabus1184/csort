#include "algo.h"

void merge(int *arr, int size, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
 
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

void _merge_sort(int *arr, int size, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
  
        _merge_sort(arr, size, l, m);
        _merge_sort(arr, size, m + 1, r);

        merge(arr, size, l, m, r);
    }
}

const void *merge_sort(int *arr, int size) {
	_merge_sort(arr, size, 0, size - 1);
	return NULL;
}

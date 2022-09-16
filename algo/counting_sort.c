#include "algo.h"

#include <stdio.h>

const void *counting_sort(int *arr, int size, const void *step(int*, int)) {
    int _arr[size];

	int max = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

    int _i = 0;
    for (int n = 0; n <= max; n++) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == n) {
                _arr[_i++] = n;
            }
        }
        step(_arr, _i);
    }
    
    memcpy(arr, _arr, size * sizeof(int));
    return NULL;
}

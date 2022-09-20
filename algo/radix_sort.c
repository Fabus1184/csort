#include "algo.h"

int max(int *arr, int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}
 
void count_sort(int *arr, int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
    }
    
    for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
    }
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

 	for (i = 0; i < n; i++) {
		arr[i] = output[i];
		step(arr, n);
 	}
}
 
const void *radix_sort(int *arr, int size) {
    int m = max(arr, size);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        count_sort(arr, size, exp);
    }
    return NULL;
}

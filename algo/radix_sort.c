#include "algo.h"

size_t max(uint32_t *arr, size_t n) {
    size_t x = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > x) {
            x = arr[i];
        }
    }
    return x;
}
 
void count_sort(uint32_t *arr, size_t n, size_t exp) {
    size_t output[n];
    size_t count[10] = { 0 };
    int64_t i;
 
    for (i = 0; i < (int64_t) n; i++) {
		count[(arr[i] / exp) % 10]++;
    }
    
    for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
    }
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

 	for (i = 0; i < (int64_t) n; i++) {
		arr[i] = output[i];
		step(arr, n);
 	}
}
 
void radix_sort(uint32_t *arr, size_t size) {
    size_t m = max(arr, size);

    for (size_t exp = 1; m / exp > 0; exp *= 10) {
        count_sort(arr, size, exp);
    }
    
}

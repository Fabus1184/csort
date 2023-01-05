#include "algo.h"

void gnome_sort(uint32_t *arr, size_t size) {
    size_t pos = 0;
    while (pos < size) {        
        if (pos == 0 || arr[pos] >= arr[pos - 1]) {
            pos++;
        } else {
            swap(arr + pos, arr + pos - 1);
            pos--;

            step(arr, size);
        }
    }
    
}

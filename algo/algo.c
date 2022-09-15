#include "algo.h"

void (*algos[7])(int *, int, void (*)(int*, int)) = {
  bubble_sort,
  insertion_sort,
  bogo_sort,
  counting_sort,
  heap_sort,
  selection_sort,
  cocktail_shaker_sort  
};


bool is_sorted(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

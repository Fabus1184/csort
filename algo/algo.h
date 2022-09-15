#pragma once

#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

extern bool is_sorted(int *arr, int size);

typedef const void *sorting_function(int *, int, const void *(int*, int));

extern sorting_function bubble_sort;
extern sorting_function insertion_sort;
extern sorting_function bogo_sort;
extern sorting_function counting_sort;
extern sorting_function heap_sort;
extern sorting_function selection_sort;
extern sorting_function cocktail_shaker_sort;


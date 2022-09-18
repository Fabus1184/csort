#pragma once

#include <stdbool.h>
#include <memory.h>
#include <limits.h>
#include <stdlib.h>

extern int RAND_ARRAY_MAX;

extern bool is_sorted(int *arr, int size);

typedef const void *sorting_function(int *, int);

sorting_function bubble_sort;
sorting_function insertion_sort;
sorting_function bogo_sort;
sorting_function counting_sort;
sorting_function heap_sort;
sorting_function selection_sort;
sorting_function cocktail_shaker_sort;
sorting_function merge_sort;
sorting_function quicksort;
sorting_function bitonic_sort;

void swap(int *a, int *b);

extern void step(int*, int);

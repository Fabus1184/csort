#pragma once

#include <stdbool.h>
#include <memory.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef void sorting_function(uint32_t *, size_t);

extern size_t RAND_ARRAY_MAX;

extern bool is_sorted(uint32_t *arr, size_t size);

extern void step(uint32_t *arr, size_t size);

void swap(uint32_t *x, uint32_t *y);

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
sorting_function radix_sort;
sorting_function gnome_sort;

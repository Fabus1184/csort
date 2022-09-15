#pragma once

#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

extern bool is_sorted(int *arr, int size);

extern void bubble_sort(int *arr, int size, void (*step)(int*, int));
extern void insertion_sort(int *arr, int size, void (*step)(int*, int));
extern void bogo_sort(int *arr, int size, void (*step)(int*, int));
extern void counting_sort(int *arr, int size, void (*step)(int*, int));
extern void heap_sort(int *arr, int size, void (*step)(int*, int));
extern void selection_sort(int *arr, int size, void (*step)(int*, int));
extern void cocktail_shaker_sort(int *arr, int size, void (*step)(int*, int));

extern void (*algos[7])(int *, int, void (*)(int*, int));

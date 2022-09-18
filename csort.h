#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#include <math.h>
#include <sys/ioctl.h>

#include "algo/algo.h"

#define RESET "\033[0m"
#define UNDERLINE "\033[4m"
#define PREV_LINE "\033[A"

int RAND_ARRAY_MAX = 255;

void step(int*, int);

static const uint64_t algos[] = {
  (uint64_t) bubble_sort, 3, (uint64_t) "Bubble Sort",
  (uint64_t) insertion_sort, 50, (uint64_t) "Insertion Sort",
  (uint64_t) selection_sort, 100, (uint64_t) "Selection Sort",
  (uint64_t) merge_sort, 10, (uint64_t) "Merge Sort",
  (uint64_t) quicksort, 25, (uint64_t) "Quicksort",
  (uint64_t) heap_sort, 30, (uint64_t) "Heap Sort",
  (uint64_t) bitonic_sort, 30, (uint64_t) "Bitonic Sort",
  (uint64_t) cocktail_shaker_sort, 2, (uint64_t) "Cocktail Shaker Sort",
  (uint64_t) counting_sort, 20, (uint64_t) "Counting Sort",
  (uint64_t) bogo_sort, 1, (uint64_t) "Bogo Sort",
};

static const char blocks[][4] = {
    "\u2581",
    "\u2582",
    "\u2583",
    "\u2584",
    "\u2585",
    "\u2586",
    "\u2587",
    "\u2588",
};

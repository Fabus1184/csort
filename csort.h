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

static const void* algos[] = {
  bubble_sort,          (void*) 3L,      "Bubble Sort",
  insertion_sort,       (void*) 50L,     "Insertion Sort",
  selection_sort,       (void*) 100L,    "Selection Sort",
  merge_sort,           (void*) 10L,     "Merge Sort",
  quicksort,            (void*) 25L,     "Quicksort",
  heap_sort,            (void*) 30L,     "Heap Sort",
  bitonic_sort,         (void*) 30L,     "Bitonic Sort",
  cocktail_shaker_sort, (void*) 2L,      "Cocktail Shaker Sort",
  counting_sort,        (void*) 20L,     "Counting Sort",
  bogo_sort,            (void*) 1L,      "Bogo Sort",
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

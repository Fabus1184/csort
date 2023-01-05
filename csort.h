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

// delay between algorithms
#define SLEEP_MS 1000

// max element in random array (required for some sorting algorithms)
size_t RAND_ARRAY_MAX = (uint32_t) 0xFFFF;

void step(uint32_t *arr, size_t size);

static const void* algos[] = {
// function pointer   intra-step delay    display name
  bubble_sort,          (void*) 3L,      "Bubble Sort",
  insertion_sort,       (void*) 50L,     "Insertion Sort",
  selection_sort,       (void*) 100L,    "Selection Sort",
  gnome_sort,           (void*) 3L,      "Gnome Sort",
  cocktail_shaker_sort, (void*) 2L,      "Cocktail Shaker Sort",
  merge_sort,           (void*) 10L,     "Merge Sort",
  bitonic_sort,         (void*) 30L,     "Bitonic Sort",
  quicksort,            (void*) 25L,     "Quicksort",
  heap_sort,            (void*) 30L,     "Heap Sort",
  counting_sort,        (void*) 20L,     "Counting Sort",
  radix_sort,           (void*) 20L,     "Radix Sort",
  bogo_sort,            (void*) 1L,      "Bogo Sort",
};

// unicode block characters https://en.wikipedia.org/wiki/Block_Elements
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

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

const uint64_t algos[] = {
  (uint64_t) bubble_sort, 10,
  (uint64_t) insertion_sort, 10,
  (uint64_t) selection_sort, 10,
  (uint64_t) heap_sort, 10,
  (uint64_t) cocktail_shaker_sort, 10,
  (uint64_t) counting_sort, 10,
  (uint64_t) bogo_sort, 10,
};

const char blocks[][4] = {
    "\u2581",
    "\u2582",
    "\u2583",
    "\u2584",
    "\u2585",
    "\u2586",
    "\u2587",
    "\u2588",
};

const char colors[][8] = {
    "\e[0;32m",
    "\e[0;33m",
    "\e[0;36m",
    "\e[0;34m",
    "\e[0;35m",
    "\e[0;31m",
    "\e[0;30m",
    "\e[0;37m",
};

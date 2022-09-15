#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#include <sys/ioctl.h>

#include "algo/algo.h"

const char blocks[][3] = {
    "\u2581",
    "\u2582",
    "\u2583",
    "\u2584",
    "\u2585",
    "\u2586",
    "\u2587",
    "\u2588",
};

const char colors[][7] = {
    "\e[0;90m",
    "\e[0;91m",
    "\e[0;92m",
    "\e[0;93m",
    "\e[0;94m",
    "\e[0;95m",
    "\e[0;96m",
    "\e[0;97m"
};

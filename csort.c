#include "csort.h"

void print_array(int *arr, int size) {
    int n_colors = sizeof(colors) / sizeof(*colors);
    int n_blocks = sizeof(blocks) / sizeof(*blocks);
    for (int i = 0; i < size; i++) {
        printf("arr[i] = %d, n_colors = %d, div = %d\n", arr[i], n_colors, arr[i] / n_colors);
        const char *color = colors[arr[i] / n_colors];
        const char *block = blocks[arr[i] / n_blocks];
        printf("%s%s", color, block);
    }
}

void random_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (int) rand();
    }
}

void step(int *arr, int size) {
    print_array(arr, size);
    usleep(10 * 1000);
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    int n = w.ws_col;
    int *arr = malloc(n * sizeof(int));
    random_array(arr, n);

    for (int i = 0; i < (int) sizeof(algos) / (int) sizeof(algos[0]); i++) {
        algos[i](arr, n, step);
        random_array(arr, n);
    }

    free(arr);
}

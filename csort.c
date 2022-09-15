#include "csort.h"

void print_array(int *arr, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    printf("\r");
    for (int i = 0; i < size; i++) {
        printf("%s%s", colors[(int) round(7 * ((float) arr[i] / max))], blocks[(int) round(7 * ((float) arr[i] / max))]);
    }
    
    fflush(stdout);
}

void random_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    
    for (int i = 0; i < size; i++) {
        const int n = rand() % size;
        int tmp = arr[i];
        arr[i] = arr[n];
        arr[n] = tmp;
    }
}

const void *step(int *arr, int size) {
    static int ms_delay;
    print_array(arr, size);
    usleep(ms_delay * 1000);
    return NULL;
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    const int n = w.ws_col;
    int *arr = malloc(n * sizeof(int));
    int *tmp = malloc(n * sizeof(int));

    random_array(arr, n);
    memcpy(tmp, arr, n * sizeof(int));

    for (int i = 0; i < (int) sizeof(algos) / (int) sizeof(algos[0]); i += 2) {
        ((sorting_function*) algos[i])(tmp, n, step);
        printf("\n");
        memcpy(tmp, arr, n * sizeof(int));
    }

    free(arr);
    free(tmp);
}

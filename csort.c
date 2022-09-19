#include "csort.h"

static int ms_delay;

void print_array(int *arr, int size) {
	printf("\r");
    for (int i = 0; i < size; i++) {
        float x = M_PI * 5.f / 3.f * (float) arr[i] / (float) RAND_ARRAY_MAX;
        float p = -M_PI;
        printf("\033[38;2;%d;%d;%dm%s",
        	(int) round(127.f * sin(x + p + 0.f) + 128.f),
        	(int) round(127.f * sin(x + p + 2.f) + 128.f),
        	(int) round(127.f * sin(x + p + 4.f) + 128.f),
        	blocks[(int) round(7 * ((float) arr[i] / RAND_ARRAY_MAX))]
       	);
    }
    printf("%s", RESET);
    fflush(stdout);
}

void random_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RAND_ARRAY_MAX;
    }
}

void step(int *arr, int size) {
    print_array(arr, size);
    usleep(ms_delay * 1000);
}

void _atexit() {
	printf("%s\n", RESET);
}

int main() {
	atexit(_atexit);

    srand(time(NULL));
    setlocale(LC_ALL, "");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    const int n = w.ws_col;
    int *arr = malloc(n * sizeof(int));
    int *tmp = malloc(n * sizeof(int));

    random_array(arr, n);
    memcpy(tmp, arr, n * sizeof(int));

	printf("\n");
    for (int i = 0; i < (int) sizeof(algos) / (int) sizeof(algos[0]); i += 3) {
		ms_delay = (long) algos[i + 1];
		printf("%s\r%*s\r%s", PREV_LINE, n, " ", RESET);
		printf("%s%s:%s\n", UNDERLINE, (char*) algos[i + 2], RESET);
		printf("%*s\r", n, " ");
        ((sorting_function*) algos[i])(tmp, n);
		usleep(1000 * 1000);
        memcpy(tmp, arr, n * sizeof(int));
    }

    free(arr);
    free(tmp);
}

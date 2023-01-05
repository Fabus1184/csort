#include "csort.h"

void print_array(uint32_t *arr, size_t size) {
	printf("\r");
    for (size_t i = 0; i < size; i++) {
        float x = M_PI * 5.f / 3.f * (float) arr[i] / (float) RAND_ARRAY_MAX;
        printf("\033[38;2;%d;%d;%dm%s",
            // hue shifting https://en.wikipedia.org/wiki/HSL_and_HSV
        	(uint32_t) roundf(127.f * sin(x - M_PI + 0.f) + 128.f),
        	(uint32_t) roundf(127.f * sin(x - M_PI + 2.f) + 128.f),
        	(uint32_t) roundf(127.f * sin(x - M_PI + 4.f) + 128.f),
        	blocks[(uint32_t) roundf(7 * ((float) arr[i] / (float) RAND_ARRAY_MAX))]
       	);
    }
    printf("%s", RESET);
    fflush(stdout);
}

void random_array(uint32_t *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        // rand() may only return 16 bit integers
        arr[i] = ((rand() << 16) | rand()) % RAND_ARRAY_MAX;
    }
}

uint32_t ms_delay;
void step(uint32_t *arr, size_t size) {
    print_array(arr, size);
    usleep(ms_delay * 1000);
}

void _atexit() {
    // print reset character to not screw up the terminal
	printf("%s\n", RESET);
}

int main(int32_t argc, char **argv) {
    switch (argc) {
        case 1:
            break;
        // TODO: implement choice of algorithm(s?)
        default:
            printf("Usage: ./csort\n");
            exit(1);
            break;
    }

	atexit(_atexit);

    srand(time(NULL));
    setlocale(LC_ALL, "");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    const uint32_t n = w.ws_col;
    uint32_t arr[n];

	printf("\n");
    for (size_t i = 0; i < sizeof(algos) / sizeof(algos[0]); i += 3) {
        random_array(arr, n);
		ms_delay = (uint64_t) algos[i + 1];
		
		printf("%s\r%*s\r%s", PREV_LINE, n, " ", RESET);
		printf("%s%s:%s\n", UNDERLINE, (char*) algos[i + 2], RESET);
		printf("%*s\r", n, " ");

        ((sorting_function*) algos[i])(arr, n);

		usleep(1000 * SLEEP_MS);
    }
}

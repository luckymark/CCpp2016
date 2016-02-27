#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "prime.h"

#define RANGE 1000

int main(int argc, char const *argv[]) {
    clock_t start = 0, end = 0, during = 0;
    double timecost[2];

    // Miller Rabin test
    printf("Miller Rabin test running\n");
    start = clock();
    for (size_t i = 2; i < RANGE; i++) {
        if (is_prime(i)) {
            printf("%lu\n", i);
        }
    }
    end = clock();
    during = end - start;
    timecost[0] = (double) during / CLOCKS_PER_SEC;

    // sieve of Eratosthenes
    printf("sieve of Eratosthenes running\n");
    start = clock();
    int a[RANGE - 1];
    for (size_t i = 0; i < RANGE - 1; i++) {
        a[i] = i + 2;
    }
    erasieve(a, RANGE - 1);
    for (size_t i = 0; i < RANGE - 1; i++) {
        if (a[i]) {
            printf("%d\n", a[i]);
        }
    }
    end = clock();
    during = end - start;
    timecost[1] = (double) during / CLOCKS_PER_SEC;
    for (size_t i = 0; i < sizeof(timecost) / sizeof(timecost[0]); i++) {
        printf("method %lu cost %lf sec\n", i + 1, timecost[i]);
    }
    return 0;
}

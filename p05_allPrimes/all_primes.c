#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "prime.h"

#define RANGE 100000

int divider = 0;

int *erasieve(int a[], int length);

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
        printf("method %lu cost %lfb sec\n", i + 1, timecost[i]);
    }
    return 0;
}

// sieve of Eratothenes
int *filter(int a[], int length, int (*cond)(int)) {
    for (size_t i = 0; i < length; i++) {
        if (a[i] != 0 && !cond(a[i])) {
            a[i] = 0;
        }
    }
    return a;
}

int not_int_div(int x) {
    if (x <= divider) {
        return 1;
    } else {
        return x % divider;
    }
}

int (*gen_not_int_div(int n))(int) {
    divider = n;
    return not_int_div;
}

int next(int a[]) {
    static int p = -1;
    while (a[++p] == 0);
    return a[p];
}

int last(int a[]) {
    static int p = RANGE - 1;
    while (a[--p] == 0);
    return a[p];
}

int *erasieve(int a[], int length) {
    for (int n = next(a); n <= sqrt(last(a)); n = next(a)) {
        filter(a, length, gen_not_int_div(n));
    }
    return a;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "prime.h"

int *filter(int a[], int length, int *(cond)(int)) {
    for (size_t i = 0; i < length; i++) {
        if (!cond(a[i])) {
            a[i] = 0;
        }
    }
    return a;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", RAND_MAX);
    // Miller Rabin test
    clock_t start = 0, end = 0, during = 0;
    start = clock();
    // for (size_t i = 2; i < 1000000; i++) {
    //     printf("%lu\n", i);
    //     if (is_prime(i)) {
    //         printf("%lu\n", i);
    //     }
    // }
    printf("is prime 99979 %d\n", is_prime(99979));
    end = clock();
    during = end - start;
    printf("method 1 cost %lf sec\n", (double) during / CLOCKS_PER_SEC);

    // sieve of Eratosthenes
    start = clock();

    return 0;
}

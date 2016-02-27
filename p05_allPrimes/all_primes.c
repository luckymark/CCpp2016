#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "prime.h"

// int filter(int a[], int length, (int *(int)) cond) {
//     for (size_t i = 0; i < length; i++) {
//         /* code */
//     }
// }

int main(int argc, char const *argv[]) {
    printf("%d\n", RAND_MAX);
    // Miller Rabin test
    clock_t start = 0, end = 0, during = 0;
    start = clock();
    for (size_t i = 2; i < 1000000; i++) {
        if (is_prime(i)) {
            // printf("%lu\n", i);
        }
    }
    end = clock();
    during = end - start;
    printf("method 1 cost %lf sec\n", (double) during / CLOCKS_PER_SEC);

    // sieve of Eratosthenes
    start = clock();

    return 0;
}

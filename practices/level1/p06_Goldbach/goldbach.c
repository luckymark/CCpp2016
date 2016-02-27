#include <stdio.h>
#include "prime.h"

#define RANGE 100

int has_num(int list[], int num) {
    return list[num - 2];
}

int verified_num(int n, int prime_list[]) {
    for (int p = next(prime_list, 1); p <= n / 2; p = next(prime_list, 0)) {
        if (has_num(prime_list, n - p)) {
            return p;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    int prime_list[RANGE-1];
    for (size_t i = 0; i < RANGE - 1; i++) {
        prime_list[i] = i + 2;
    }
    erasieve(prime_list, RANGE - 1);

    for (int i = 4; i <= RANGE; i += 2) {
        int p = verified_num(i, prime_list);
        if (p) {
            printf("%d = %d + %d\n", i, p, i - p);
        } else {
            printf("Congradulation! You falsified the Goldbach's conjecture! "
                   "Maybe you should go ask for a Nobel Prize or something.\n");
        }
    }

    return 0;
}

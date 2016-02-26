#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long random_in(unsigned long range);

int square(int a) {
    return a * a;
}

int expmod(int base, int expo, int m) {
    if (expo == 0) {
        return 1;
    } else if (expo % 2 == 0) {
        return (square(expmod(base, expo / 2, m))) % 2;
    } else {
        return expmod(base, expo - 1, m);
    }
}

int is_prime(int p) {
    return 1;
}

int main(int argc, char const *argv[]) {
    unsigned long a = random_in(10);

    return 0;
}

// Thank to god that we have such a "convient" random funtion in C so that
// I have to write all of these useless function to genertae just one number

unsigned long random_in_dec(unsigned long range) {
    if (range == 0)
        return rand() % 10;
    else
        return rand() % 10 + 10 * random_in_dec(range / 10);
}

unsigned long random_in(unsigned long range) {
    unsigned long random_num;
    while ((random_num = random_in_dec(range)) > range);
    return random_num;
}

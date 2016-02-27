#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAGIC_NUM 100

unsigned long random_in(unsigned long range);

unsigned long square(unsigned long a) {
    return a * a;
}

unsigned long expmod(unsigned long base, unsigned long expo, unsigned long m) {
    if (expo == 0) {
        return 1;
    } else if (expo % 2 == 0) {
        unsigned long mod = expmod(base, expo / 2, m);
        unsigned long sqmod = square(mod);
        if (mod != 1 && mod != m - 1 && sqmod % m == 1) {
            return 0;
        } else {
            return sqmod % m;
        }
    } else {
        return expmod(base, expo - 1, m) * base % m;
    }
}

int is_prime(unsigned long p) {
    if (p % 2 == 0) {
        return 0;
    } else {
        unsigned long a;
        a = random_in(p);
        for (size_t i = 0; i < MAGIC_NUM; i++, a = random_in(p)) {
            int result = expmod(a, p - 1, p);
            if (result == 0 || result != 1) {
                return 0;
            }
        }
        return 1;
    }
}

int main(int argc, char const *argv[]) {
    unsigned long p = 0;
    printf("enter whatever you like as long as it's a number: ");
    scanf("%lu", &p);
    printf("%lu is a %s number.\n", p, is_prime(p) ? "prime" : "composite");
    return 0;
}

// Thank to god that we have such a "convient" random funtion in C so that
// I have to rewrite all of these useless function to genertae just one tiny
// number

unsigned long random_in_dec(unsigned long range) {
    if (range == 0) {
        return rand() % 10;
    } else {
        return rand() % 10 + 10 * random_in_dec(range / 10);
    }
}

unsigned long random_in(unsigned long range) {
    unsigned long random_num;
    while ((random_num = random_in_dec(range)) >= range || !random_num);
    return random_num;
}

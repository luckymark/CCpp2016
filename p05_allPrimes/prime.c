#include "prime.h"
#include <stdlib.h>

#define MAGIC_NUM 100


int random_in(int range);

int square(int a) {
    return a * a;
}

int expmod(int base, int expo, int m) {
    if (expo == 0) {
        return 1;
    } else if (expo % 2 == 0) {
        int mod = expmod(base, expo / 2, m);
        int sqmod = square(mod);
        if (mod != 1 && mod != m - 1 && sqmod % m == 1) {
            return 0;
        } else {
            return sqmod % m;
        }
    } else {
        return expmod(base, expo - 1, m) * base % m;
    }
}

int is_prime(int p) {
    if (p % 2 == 0) {
        return 0;
    } else {
        int a;
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

int random_in(int range) {
    int random_num;
    while ((random_num = rand() % range) >= range || !random_num);
    return random_num;
}

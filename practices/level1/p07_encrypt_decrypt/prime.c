#include "prime.h"
#include <stdlib.h>
#include <math.h>

static long long int divider = 0;

// Miller Rabin test
long long int random_in(long long int range);

static long long int square(long long int a) {
    return a * a;
}

static long long int expmod_for_miller_test(long long int base, long long int expo, long long int m) {
    if (expo == 0) {
        return 1;
    } else if (expo % 2 == 0) {
        long long int mod = expmod_for_miller_test(base, expo / 2, m);
        long long int sqmod = square(mod);
        if (mod != 1 && mod != m - 1 && sqmod % m == 1) {
            return 0;
        } else {
            return sqmod % m;
        }
    } else {
        return expmod_for_miller_test(base, expo - 1, m) * base % m;
    }
}

long long int is_prime(long long int p, int centeainty) {
    if (p % 2 == 0 && p != 2) {
        return 0;
    } else {
        long long int a;
        a = random_in(p);
        for (size_t i = 0; i < centeainty; i++, a = random_in(p)) {
            long long int result = expmod_for_miller_test(a, p - 1, p);
            if (result == 0 || result != 1) {
                return 0;
            }
        }
        return 1;
    }
}

long long int random_in(long long int range) {
    long long int random_num;
    while ((random_num = rand() % range) >= range || !random_num);
    return random_num;
}

// sieve of Eratothenes
static long long int *filter(long long int a[], long long int length, long long int (*cond)(long long int)) {
    for (size_t i = 0; i < length; i++) {
        if (a[i] != 0 && !cond(a[i])) {
            a[i] = 0;
        }
    }
    return a;
}

static inline long long int not_int_div(long long int x) {
    return x <= divider ? 1 : x % divider;
}

static long long int (*gen_not_int_div(long long int n))(long long int) {
    divider = n;
    return not_int_div;
}

long long int next(long long int a[], long long int init) {
    static long long int p = -1;
    if (init == 1) {
        p = -1;
    }
    while (a[++p] == 0);
    return a[p];
}

static long long int last(long long int a[], long long int length) {
    static long long int p = -1;
    if (p == -1) {
        p = length;
    }
    while (a[--p] == 0);
    return a[p];
}

long long int *erasieve(long long int a[], long long int length) {
    for (long long int n = next(a, 1); n <= sqrt(last(a, length)); n = next(a, 0)) {
        filter(a++, length, gen_not_int_div(n));
    }
    return a;
}

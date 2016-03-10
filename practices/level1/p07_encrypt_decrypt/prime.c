#include "prime.h"
#include <stdlib.h>
#include <math.h>

static int divider = 0;

// Miller Rabin test
int random_in(int range);

static int square(int a) {
    return a * a;
}

static int expmod_for_miller_test(int base, int expo, int m) {
    if (expo == 0) {
        return 1;
    } else if (expo % 2 == 0) {
        int mod = expmod_for_miller_test(base, expo / 2, m);
        int sqmod = square(mod);
        if (mod != 1 && mod != m - 1 && sqmod % m == 1) {
            return 0;
        } else {
            return sqmod % m;
        }
    } else {
        return expmod_for_miller_test(base, expo - 1, m) * base % m;
    }
}

int is_prime(int p, int centeainty) {
    if (p % 2 == 0 && p != 2) {
        return 0;
    } else {
        int a;
        a = random_in(p);
        for (size_t i = 0; i < centeainty; i++, a = random_in(p)) {
            int result = expmod_for_miller_test(a, p - 1, p);
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

// sieve of Eratothenes
static int *filter(int a[], int length, int (*cond)(int)) {
    for (size_t i = 0; i < length; i++) {
        if (a[i] != 0 && !cond(a[i])) {
            a[i] = 0;
        }
    }
    return a;
}

static inline int not_int_div(int x) {
    return x <= divider ? 1 : x % divider;
}

static int (*gen_not_int_div(int n))(int) {
    divider = n;
    return not_int_div;
}

int next(int a[], int init) {
    static int p = -1;
    if (init == 1) {
        p = -1;
    }
    while (a[++p] == 0);
    return a[p];
}

static int last(int a[], int length) {
    static int p = -1;
    if (p == -1) {
        p = length;
    }
    while (a[--p] == 0);
    return a[p];
}

int *erasieve(int a[], int length) {
    for (int n = next(a, 1); n <= sqrt(last(a, length)); n = next(a, 0)) {
        filter(a++, length, gen_not_int_div(n));
    }
    return a;
}

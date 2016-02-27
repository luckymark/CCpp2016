#include <stdio.h>
#include <math.h>

int len(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + len(n / 10);
    }
}

int bitexp(int x, int n) {
    if (x == 0) {
        return 0;
    } else {
        return (int)pow((x % 10), n) + bitexp(x / 10, n);
    }
}

int is_narcissus(int n) {
    return n == bitexp(n, len(n));
}

int main(int argc, char const *argv[]) {
    for (int i = 100; i < 1000; i++) {
        if (is_narcissus(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}

//
// Created by Administrator on 2016/3/3.
//

#include <stdio.h>

int isPrime(int num);

int main(void) {
    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

int isPrime(int num) {
    int i;

    for (i = 2; i < num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

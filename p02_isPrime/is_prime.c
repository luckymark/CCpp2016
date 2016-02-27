#include <stdio.h>
#include "prime.h"

int main(int argc, char const *argv[]) {
    unsigned long p = 0;
    printf("enter whatever you like as long as it's a number: ");
    scanf("%lu", &p);
    printf("%lu is a %s number.\n", p, is_prime(p) ? "prime" : "composite");
    return 0;
}

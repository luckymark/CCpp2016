#include <stdio.h>
#include "prime.h"

int main(int argc, char const *argv[]) {
    int p = 0;
    printf("enter whatever you like as long as it's a number: ");
    scanf("%d", &p);
    printf("%d is a %s number.\n", p, is_prime(p) ? "prime" : "composite");
    return 0;
}

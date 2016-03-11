#include "prime.h"
#include "rsa_cryptosystem.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    long long int public_key[2], private_key[2];
    generate_keys(public_key, private_key);
    return 0;
}

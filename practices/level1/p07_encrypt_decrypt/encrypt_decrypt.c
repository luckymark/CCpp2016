#include "prime.h"
#include "rsa_cryptosystem.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    long long int public_key[2], private_key[2];
    generate_keys(public_key, private_key);
    char m[] = "12345";
    int c[6];

    printf("m=%s\n", m);
    printf("encrypting...\n");
    rsa_string_encrypt(m, c, public_key);
    printf("decoding....\n");
    rsa_string_decode(c, m, private_key);
    printf("m=%s\n", m);
    return 0;
}

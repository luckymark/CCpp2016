#include "rsa_cryptosystem.h"
#include "prime.h"
#include <stdlib.h>
#include <time.h>

// 一个简单的 RSA 加密算法，＊＊千万不要真的使用它＊＊ (因为此版本的安全性也许还不如异或加密)

#define MAGIC_NUM 65537

static int square(int x) {
    return x * x;
}

static int expmod(int base, int expr, int m) {
    if (expr == 0) {
        return 1;
    } else if (expr % 2 == 0) {
        return square(expmod(base, expr / 2, m)) % m;
    } else {
        return (base * (expmod(base, expr - 1, m))) % m;
    }
}

static int rand_prime(int min) {
    long long int prime;
    prime = ((min % 2 == 0) ? (min + 1) : min);
    for (; !is_prime(prime, 10); prime += 2);
    return prime;
}

static int exgcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    } else {
        int gcd = exgcd(b % a, a, x, y);
        int tem = *x;
        *x = *y;
        *y = -(a / b * *y - tem);
        return gcd;
    }
}

// 防止生成比最大素数更大的随机数
static int safe_rand(int min) {
    static int flag = 0;
    if (flag == 0) {
        srand(time(NULL));
        flag = 1;
    }
    int rand_number = rand() + min;
    while (rand_number > 2147483647) {
        rand_number = rand() + min;
    }
    return rand_number;
}

static int rsa_general_operation(long long int key[], int x) {
    if (x > key[0]) {
        return -1;
    }
    int a = key[0];
    int b = key[1];
    int c = expmod(x, b, a);
    return c;
}

int rsa_encrypt(long long int public_key[], int m) {
    return rsa_general_operation(public_key, m);
}

int rsa_decode(long long int private_key[], int c) {
    return rsa_general_operation(private_key, c);
}

void generate_keys(long long int public_key[], long long int private_key[]) {
    int p = rand_prime(safe_rand(MAGIC_NUM));
    int q = rand_prime(safe_rand(MAGIC_NUM));
    long long int n = p * q;
    long long int phi = (p - 1) * (q - 1);
    int e = MAGIC_NUM;
    int x, y;
    exgcd(e, phi, &x, &y);
    public_key[0] = n;
    public_key[1] = e;
    private_key[0] = n;
    private_key[1] = x;
}

int rsa_string_encrypt(char *m, int *c, long long int public_key[]) {
    for (size_t i = 0; m[i-1] != '\0'; i++) {
        int result = rsa_encrypt(public_key, m[i]);
        if (result == -1) {
            return -1;
        } else {
            c[i] = m[i];
        }
    }
    return 0;
}

int rsa_string_decode(int *c, char *m, long long int private_key[]) {
    for (size_t i = 0; c[i-1] != '\0'; i++) {
        int result = rsa_decode(private_key, c[i]);
        if (result == -1) {
            return -1;
        } else {
            m[i] = result;
        }
    }
    return 0;
}

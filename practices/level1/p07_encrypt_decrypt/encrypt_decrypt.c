#include "prime.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUM 65537

// 一个简单的 RSA 加密算法，＊＊千万不要真的使用它＊＊ (因为此版本的安全性也许还不如异或加密)

int rand_prime(int min);

int safe_rand(int min);

int exgcd(int a, int b, int *x, int *y);

int expmod(int base, int expr, int m);

void generate_keys(int public_key[], int private_key[]);

int reciprocal_encrypt(char *m, char *c, int key);

int reciprocal_decode(char *c, char *m, int key);

int rsa_encrypt(int public_key[], int m);

int rsa_decode(int private_key[], int c);

int main(int argc, char const *argv[]) {
    int public_key[2], private_key[2];
    generate_keys(public_key, private_key);
    return 0;
}

int rand_prime(int min) {
    int prime = min;
    prime = ((prime % 2 == 0) ? (prime + 1) : prime);
    for (; !is_prime(prime, 30); prime -= 2);
    return prime;
}

int exgcd(int a, int b, int *x, int *y) {
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

int square(int x) {
    return x * x;
}

int expmod(int base, int expr, int m) {
    if (expr == 0) {
        return 1;
    } else if (expr % 2 == 0) {
        return square(expmod(base, expr / 2, m)) % m;
    } else {
        return (base * (expmod(base, expr - 1, m))) % m;
    }
}

// 防止生成比最大素数更大的随机数
int safe_rand(int min) {
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

void generate_keys(int public_key[], int private_key[]) {
    int p = rand_prime(safe_rand(MAGIC_NUM));
    int q = rand_prime(safe_rand(MAGIC_NUM));
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = MAGIC_NUM;
    int x, y;
    exgcd(e, phi, &x, &y);
    public_key[0] = n;
    public_key[1] = e;
    private_key[0] = n;
    private_key[1] = x;
}

int main_encrypt(char *m, char *c, int key, int public_key[]) {
    reciprocal_encrypt(m, c, key);
    int encrypted_key = rsa_encrypt(public_key, key);
    return encrypted_key;
}

int main_decode(char *c, char *m, int encrypted_key, int private_key[]) {
    int key = rsa_decode(private_key, encrypted_key);
    reciprocal_decode(c, m, key);
    return key;
}

int reciprocal_encrypt(char *m, char *c, int key) {
    // 用对称加密算法加密长明文
}

int reciprocal_decode(char *c, char *m, int key) {

}


int rsa_encrypt(int public_key[], int m) {
    int n = public_key[0];
    int e = public_key[1];
    int c = expmod(m, e, n);
    return c;
}

int rsa_decode(int private_key[], int c) {
    int n = private_key[0];
    int x = private_key[1];
    int m = expmod(c, x, n);
    return m;
}

#include<cstdio>
#define MAX 100
void selectAllPrime(bool primes[],int n);
bool goldbach(bool primes[],int n);
int main() {
    bool prime[MAX + 10];
    selectAllPrime(prime, MAX);
    printf("Goldbach is %s", goldbach(prime, MAX) ? "Truth" : "False");
    return 0;
}
void selectAllPrime(bool primes[],int n) {
    for (int i = 1; i <= MAX; ++i) {
        primes[i] = 1;//init;
    }
    for (int i = 2; i <= MAX; ++i) {
        if (!primes[i])continue;//because of it had been out
        for (int j = i + i; j <= MAX; j += i) {
            primes[j] = 0;//because of i is a factor of j
        }
    }
}
bool goldbach(bool primes[],int n) {
    int j;
    for (int i = 4; i <= n; i += 2) {
        for (j = 2; j < i; ++j) {
            int k = i - j;
            if (primes[k] && primes[j]) {
                break;//find it
            }
        }
        if (j == i) {//means no such a pair of j,k satisfied j+k==i && both j and k are primes
            return 0;
        }
    }
    return 1;
}

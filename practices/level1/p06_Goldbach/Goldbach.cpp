#include<cstdio>
#include<cstring>
const int MAX = 100;
void selectAllPrime(int n);
bool goldbach(int n);
bool prime[MAX+10];
int main() {
    selectAllPrime(MAX);
    printf("Goldbach is %s",goldbach(MAX)?"Truth":"False");
    return 0;
}
void selectAllPrime(int n) {
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (!prime[i])continue;//because of it had been out
        for (int j = i + i; j <= MAX; j += i) {
            prime[j] = 0;//because of i is a factor of j
        }
    }
}
bool goldbach(int n){
    int j;
    for(int i=4;i<=n;i+=2){
        for(j=2;j<i;++j){
            int k=i-j;
            if(prime[k]&&prime[j]){
                break;//find it
            }
        }
        if(j==i){//means no such a pair of j,k satisfied j+k==i && both j and k are primes
            return 0;
        }
    }
    return 1;
}

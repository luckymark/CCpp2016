#include<ctime>
#include<iostream>
using namespace std;
#define TIME 20 //Miller测试次数
long long quickPow(long long base, long long pow, long long mod);//计算(a^b) mod n
bool millerRabin(long long base, long long number);//以base为基对n进行Miller测试并实现二次探测
bool isPrime(long long number);
int main() {
    srand(time(NULL));
    long long number;
    cin >> number;
    cout << (isPrime(number) ? "Yes" : "No") << endl;
    return 0;
}
long long quickPow(long long base, long long pow, long long mod) {
    long long ans = 1LL;
    base = base % mod;
    while (pow >= 1) {
        if (pow & 1)ans = (ans * base) % mod;
        base = (base * base) % mod;
        pow = pow >> 1;
    }
    return ans;
}
bool millerRabin(long long base, long long number) {
    long long ans;
    int pow = 0;
    long long min = number - 1;
    while (!(min & 1)) {
        min = min >> 1;
        pow++;
    }//计算n = m * (2^j) + 1
    long long tem = quickPow(base, min, number);
    for (int i = 1; i <= pow; i++) {
        ans = (tem * tem) % number;
        if ((ans == 1) && (tem != 1) && (tem != number - 1)) {
            return true; //返回true时,n是合数
        }//二次探测
        tem = ans;
    }
    return (ans != 1);
}
bool isPrime(long long number) {
    if (number == 2) return true;
    if (number < 2 || (number & 1) == 0) return false;
    for (int i = 1; i <= TIME; i++) {
        long long base = rand() % (number - 2) + 2;//一个随机的[2,a)的整数作为底数
        if (millerRabin(base, number)) return false;//拉宾-米勒检测
    }
    return true;
}

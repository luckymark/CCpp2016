#include <iostream>
#include <cmath>

using namespace std;

inline bool isPrime(unsigned n) {
    for (unsigned i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    unsigned n;
    cin >> n;
    cout << isPrime(n) ? "yes" : "no";
    return 0;
}
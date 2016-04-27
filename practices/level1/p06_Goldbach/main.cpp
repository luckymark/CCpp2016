#include <iostream>
#include <list>
#include <cmath>

using namespace std;

bool isPrime(unsigned);

list<int> getPrimes(int max);

int main() {
    bool mainProved = true;
    for (int i = 4; i <= 100; i+=2) {
        list<int> primes = getPrimes(i - 1);
        bool subProved = false;
        for (int a : primes) {
            for (int b : primes) {
                if (a + b == i) {
                    subProved = true;
                    break;
                }
            }
            if (subProved) {
                break;
            }
        }
        if (!subProved) {
            mainProved = false;
            cout << "failed: " << i << endl;
            break;
        } else {
            cout << "proved: " << i << endl;
        }
    }
    cout << (mainProved ? "good" : "bad") << endl;
}

bool isPrime(unsigned n) {
    for (unsigned i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

list<int> getPrimes(int max) {
    list<int> l;
    for (int i = 2; i <= max; ++i) {
        if (isPrime(i)) {
            l.push_back(i);
        }
    }
    return l;
}

#include <iostream>
#include <cmath>
#include <sys/time.h>

using namespace std;

inline long getCurrentTime() {
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

inline bool isPrime(unsigned n) {
    for (unsigned i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    auto startT = getCurrentTime();
    for (unsigned i = 2; i <= 1000; ++i) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
    auto endT = getCurrentTime();
    cout << "time(us): " << endT - startT;
    return 0;
}
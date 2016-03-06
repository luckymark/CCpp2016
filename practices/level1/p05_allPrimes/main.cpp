#include <iostream>
#include <cmath>
#include <cstring>
#include <sys/time.h>

using namespace std;

long getCurrentTime();

#define MAX 1000

int main(int argc, char *argv[]) {
    int isPrime[MAX + 1];
    memset(isPrime, 1, MAX + 1);
    isPrime[1] = 0;
    auto startT = getCurrentTime();
    for (unsigned i = 2; i <= sqrt(MAX); ++i) {
        if (isPrime[i]) {
            for (unsigned j = 2; j <= MAX / i; ++j) {
                isPrime[i * j] = 0;
            }
        }
    }
    auto endT = getCurrentTime();
    for (unsigned i = 1; i < MAX + 1; ++i) {
        if (isPrime[i]) {
            cout << i << endl;
        }
    }
    cout << "time(us): " << endT - startT;
    return 0;
}

long getCurrentTime() {
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

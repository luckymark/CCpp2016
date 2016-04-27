#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    for (int i = 100; i <=999; ++i) {
        int b = i / 100;
        int s = (i - b * 100) / 10;
        int g = i - b * 100 - s * 10;
        if (pow(b, 3) + pow(s, 3), pow(g, 3) == i) {
            cout << i << endl;
        }
    }
    return 0;
}
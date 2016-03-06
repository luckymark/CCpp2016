#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void draw(int);

#define WINDOW_SIZE 20

int main(int argc, char *argv[]) {
    while (1) {
        for (int i = 0; i < WINDOW_SIZE * 2; ++i) {
            system("clear");
            draw(WINDOW_SIZE - abs(i - WINDOW_SIZE));
        }
    }
    return 0;
}

void draw(int offset) {
    for (int i = 0; i < offset; ++i) {
        cout << ' ';
    }
    cout << "Hello, World!";
}

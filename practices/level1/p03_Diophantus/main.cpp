#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int i;
#define WASTED_TIME ((i / 4 + i / 7) + 5)
#define SON_AGE (i - 4 - WASTED_TIME)
    for (i = 1; !((i % 12 * 7 == 0) && (SON_AGE == i / 2)); ++i);
    cout << i;
    return 0;
}
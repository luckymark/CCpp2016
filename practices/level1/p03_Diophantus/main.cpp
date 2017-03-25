#include <iostream>

using namespace std;

#define WASTED_TIME(i) ((i / 4 + i / 7) + 5)
#define SON_AGE(i) (i - 4 - WASTED_TIME(i))

int main(int argc, char *argv[]) {
    int i;
    for (i = 1; !((i % 12 * 7 == 0) && (SON_AGE(i) == i / 2)); ++i);
    cout << i;
    return 0;
}

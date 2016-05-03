#include <iostream>
#include "SafeArray.h"
const int SIZE = 100;
int main() {
    SafeArray safeArray(SIZE);
    safeArray.insert(5,100);
    safeArray.get(5);
    safeArray.get(100);
    return 0;
}

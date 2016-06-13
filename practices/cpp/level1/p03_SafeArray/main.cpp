#include <iostream>
#include "SafeArray.h"
using namespace std;

int main() {
    SafeArray<int, 10> myArray;
    myArray[0] = 5;
    printf("%d\n", myArray[0]);
    return 0;
}

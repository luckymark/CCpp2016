//
// Created by Administrator on 2016/4/19.
//

#include <iostream>
#include "safearray.h"

using namespace std;

int main() {
    SafeArray arr(100);
    for (int i = 1; i <= 99; ++i) {
        arr.set_data(i) = 1;
    }

    cout << arr.get_data(99) << endl;
    arr.set_data(99) = 1;
    cout << arr.get_data(99) << endl;

    arr.get_data(100) = 0; // error

    return 0;
}

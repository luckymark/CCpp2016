//
// Created by Administrator on 2016/4/24.
//

#include <cstdlib>
#include <iostream>
#include "safearray.h"

#define OUT_OF_LENGTH 1

int SafeArray::get_length() {
    return length;
}

int & SafeArray::set_data(int position) {
    if (position > length) {
        exit(OUT_OF_LENGTH);
    }
    else {
        std::cin >> data[position];
    }
}

int& SafeArray::get_data(int position) {
    if (position > length) {
        exit(OUT_OF_LENGTH);
    }
    else {
        return data[position];
    }

}
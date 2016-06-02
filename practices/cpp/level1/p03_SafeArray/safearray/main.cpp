//
//  main.cpp
//  safearray
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <iostream>
#include "safearray.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int array_size;
    int index, val;
    cout << "Please enter the size of the array: ";
    cin >> array_size;
    array_size = (array_size > 0)?array_size:100;
    SafeArray array(array_size, false);
    cout << "Set the array." << endl;
    cout << "Enter positive numbers. Enter a negative one to stop." << endl;
    index = 0;
    while(true){
        if(index >= array_size){
            break;
        }
        int value;
        cin >> value;
        if(value < 0){
            break;
        }
        array[index] = value;
        index ++;
    }
    cout << "Get the array." << endl;
    cout << "Enter index: ";
    cin >> index;
    try {
        val = array[index];
        cout << "Index " << index << " has value " << val << endl;
    } catch (const char *msg) {
        cout << msg << endl;
    }
    cout << array << endl;
    return 0;
}


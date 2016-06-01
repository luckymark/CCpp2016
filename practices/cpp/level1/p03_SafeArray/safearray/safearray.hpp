//
//  safearray.hpp
//  safearray
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef safearray_hpp
#define safearray_hpp

#include <stdio.h>
#include <iostream>
#define DEFAULT_SIZE 16

using namespace std;

class SafeArray
{
public:
    // Argument 'round': Determine whether to allow any range.
    SafeArray(int size, bool round=true);
    ~SafeArray();
    void set(int index, int value);
    int get(int index);
    int & operator [] (int index);
    friend ostream & operator<<(ostream & os, SafeArray & a);
private:
    int *data;
    int a_size;
    int processIndex(int index);
    void checkIndex(int index);
    bool round;
};
#endif /* safearray_hpp */

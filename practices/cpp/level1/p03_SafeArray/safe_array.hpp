//
//  safe_array.hpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef safe_array_hpp
#define safe_array_hpp

#include <stdio.h>
class Safe_array
{
public:
    Safe_array(int capbility);
    ~Safe_array()
    {
        delete data;
    }
    void set(int n ,int value);
    void get(int n);
    void check_index(int n );
    int &operator [] (int a);
private:
    int all;
    int *data;
};
#endif /* safe_array_hpp */

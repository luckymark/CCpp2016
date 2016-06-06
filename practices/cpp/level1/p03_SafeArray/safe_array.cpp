//
//  safe_array.cpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include "safe_array.hpp"
#include<iostream>
Safe_array::Safe_array(int capbility)
{
    data = new int[capbility];
    all = capbility;
}
void Safe_array::set(int n, int value)
{
    check_index(n);
    data[n] = value;
    std::cout<<"赋值成功!"<<std::endl;
}
void Safe_array::get(int n )
{
    check_index(n);
    std::cout<<"值为"<<data[n]<<std::endl;
}
void Safe_array::check_index(int n)
{
    if (n>=all || n<0)
        throw "数组访问越界！";
}
int &Safe_array::operator[](int a)
{
    check_index(a);
    return data[a];
}

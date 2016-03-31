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
    if (n>=all)
    {
        std::cout<<"数组访问越界！"<<std::endl;
        return ;
    }
    data[n] = value;
    std::cout<<"赋值成功!"<<std::endl;
}
void Safe_array::get(int n )
{
    if (n>=all)
    {
        std::cout<<"数组访问越界！"<<std::endl;
        return ;
    }
    std::cout<<"值为"<<data[n]<<std::endl;
}
//
//  main.cpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include <iostream>
#include "safe_array.hpp"
int main() {
    int capbility;
    std::cout<<"输入数组大小："<<std::endl;
    std::cin>>capbility;
    Safe_array<double> safe_array(capbility);
    std::cout<<"初始化数组元素："<<std::endl;
    for (int i = 0 ; i < capbility ;i++)
    {
        std::cout<<"第"<<i<<"个元素："<<std::endl;
        double value;
        std::cin>>value;
        safe_array[i] = value;
    }
    //    for (int i = 0 ;i < capbility ;i++)
    //        safe_array.set(i, i*10-2); //初始化
    std::cout<<"请输入需要修改元素的位置和值"<<std::endl;
    int n;
    double value;
    std::cin>>n>>value;
    try{
        safe_array[n] = value;
    } catch (const char * msg){
        std::cout<<msg<<std::endl;
    }
    for (int i = 0 ;i < capbility ; i++)
        std::cout<<safe_array[i]<<" ";
    //    safe_array.set(n, value);//赋值
    //    std::cin>>n;
    //    safe_array.get(n);//读取值
    return 0;
}

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
    int n ,value , capbility;
    std::cin>>capbility>>n>>value;
    Safe_array safe_array(capbility);
    for (int i = 0 ;i < capbility ;i++)
        safe_array.set(i, i*10-2); //初始化
    safe_array.set(n, value);//赋值
    std::cin>>n;
    safe_array.get(n);//读取值
    return 0;
}

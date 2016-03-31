//
//  main.cpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include <iostream>
#include "stack.hpp"
int main() {
    int capbility = 100;
    Stack stack(capbility);
    if (!stack.is_full())
    {
        stack.append(10);
    }
    if (!stack.is_empty())
    {
        std::cout<<stack.pop();
    }
    return 0;
}

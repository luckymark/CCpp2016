//
//  main.cpp
//  Queue
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include <iostream>
#include "queue.hpp"
Queue queue;
int main() {
    int n = 10;
    if (!queue.is_full())
    {
        queue.append(n);
    }
    if (!queue.is_empty())
    {
        std::cout<<queue.pop();
    }
    return 0;
}

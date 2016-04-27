//
//  stack.cpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include "stack.hpp"
Stack::Stack(int capibility)
{
    data = new int[capibility];
}
bool Stack::is_full()
{
    return (tail-head>=100);
}
bool Stack::is_empty()
{
    return (tail==head);
}
int Stack::pop()
{
    int n = data[tail];
    tail--;
    return n;
}
void Stack::append(int n )
{
    tail++;
    data[tail] = n;
}
//
//  stack.hpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>

class Stack
{
public:
    Stack(int capbility);
    bool is_full();
    bool is_empty();
    int pop();
    void append(int n);
    ~Stack()
    {
        delete [] data;
    }
private:
    int head = 0;
    int tail = 0;
    int *data;
};
#endif /* stack_hpp */

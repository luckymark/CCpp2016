//
//  Stack.hpp
//  Stack
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
class Stack{
public:
    Stack();
    ~Stack();
    void push(int num);
    int pop();
    bool isEmpty();
    int size();
private:
    int *data;
    int s_capacity;
    int s_size;
    void expand();
    void shrink();
};

#endif /* Stack_hpp */

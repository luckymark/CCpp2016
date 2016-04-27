//
//  queue.hpp
//  Queue
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
class Queue
{
public:
    bool is_full();
    bool is_empty();
    int pop();
    void append(int n);

private:
    int head = 0;
    int tail = 0;
    int data[101];
};
#endif /* queue_hpp */

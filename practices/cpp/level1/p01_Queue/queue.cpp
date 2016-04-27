//
//  queue.cpp
//  Queue
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include "queue.hpp"
int Queue::pop()
{
    int n = data[head];
    head = (head+1) % 100;
    return n;
}
bool Queue::is_full()
{
    return ((tail+1)%100 == head);
}
bool Queue::is_empty()
{
    return (head == tail);
}
void Queue::append(int item)
{
    data[tail] = item;
    tail = (tail+1)% 100;
}
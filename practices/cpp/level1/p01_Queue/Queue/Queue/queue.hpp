//
//  queue class.hpp
//  Queue
//
//  Created by 陈浩贤 on 16/3/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef queue_class_hpp
#define queue_class_hpp

#include <stdio.h>

#endif /* queue_class_hpp */
class Queue{
public:
    void append(int item);
    int pop();
    bool isEmpty();
    bool isFull();
    
    
private:
    int data[100];
    int head=0;
    int tail=0;
};
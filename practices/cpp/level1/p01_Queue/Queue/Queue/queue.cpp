//
//  queue class.cpp
//  Queue
//
//  Created by 陈浩贤 on 16/3/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "queue.hpp"

void Queue::append(int item){
    data[head]=item;
    head=(head+1)%100;
    
}

int Queue::pop(){
    tail=(tail+1)%100;
    
    return data[tail -1];
}

bool Queue::isEmpty(){
    
    return (head==tail);
}

bool Queue::isFull(){
    
    return ((head+1)%100==tail);
}




//
//  Stack.hpp
//  Queue
//
//  Created by 陈浩贤 on 16/3/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

#endif /* Stack_hpp */
class Stack{
public:
    
    Stack (int capbility);//构造函数
    Stack(){
        //析构函数
        delete [] element;
    }
    bool isFull();
    bool isEmpty();
    void push(int item);
    void pop();
    
    
private:
    int cap;
    int *element;
    
};
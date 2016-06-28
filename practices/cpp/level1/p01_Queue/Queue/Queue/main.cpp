//
//  main.cpp
//  Queue
//
//  Created by 陈浩贤 on 16/4/27.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <iostream>
#include "queue.hpp"
using namespace::std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Queue queue;
    if (queue.isEmpty()) {
        cout<<"队列是空的"<<endl;
    }
    int i=0;
    while (i<=2) {
        i++;
        if (!queue.isFull()) {
            
            cout<<"请输入加入队列的数字"<<endl;
            int n;
            cin>>n;
            queue.append(n);
            
        }
    }
    
    if (!queue.isEmpty()) {
        queue.pop();
        cout<<"pop了一个元素"<<endl;
    }
    
    
    return 0;
}

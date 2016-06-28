//
//  main.cpp
//  Stack
//
//  Created by 陈浩贤 on 16/4/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n,element;
    Stack stack=Stack(5);
    if (stack.isEmpty()) {
        cout<<"stack现在是空的"<<endl;
    }else{
        cout<<"stack现在不是空的"<<endl;
    }
    cout<<"请输入想要push的元素个数"<<endl;
    cin>>n;
    
    for (int i=0; i<n; i++) {
        if (!stack.isFull()) {
            cout<<"请输入push的元素"<<endl;
            cin>>element;
            stack.push(element);
        }else{
            cout<<"stack已满，停止push"<<endl;
            break;
        }
    }
    return 0;
}

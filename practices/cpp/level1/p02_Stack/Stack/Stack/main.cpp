//
//  main.cpp
//  Stack
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//


#include <iostream>
#include "stack.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Stack s;
    cout << "Please enter numbers. Enter -1 to break the loop." << endl;
    while(true){
        int a;
        cout << ">>";
        cin >> a;
        if(a == -1){
            break;
        }
        s.push(a);
    }
    cout << "The size of stack: " << s.size() << endl;
    while(!s.isEmpty()){
        cout << s.pop() << " ";
    }
    return 0;
}
//
//  main.cpp
//  SaveArray
//
//  Created by 陈浩贤 on 16/4/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <iostream>
#include "saveArray.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
        int element,i,n;
        printf("请输入数组的长度:\n");
        scanf("%d",&n);
        SaveArray array=SaveArray(n);
    
        printf("请输入元素的位置:\n");
        scanf("%d",&i);
        element = array.getElement(i);
        if (element!=-1) {
            printf("element:%d\n",element);
        }
    return 0;
}

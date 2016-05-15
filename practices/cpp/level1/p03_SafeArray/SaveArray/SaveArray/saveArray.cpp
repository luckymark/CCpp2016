//
//  saveArray.cpp
//  Queue
//
//  Created by 陈浩贤 on 16/3/31.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "saveArray.hpp"
SaveArray::SaveArray (int capbility){
    array=new int(capbility);
    cap=capbility;
    for (int i=0; i<capbility; i++) {
        array[i]=i;
        
    }
}


int SaveArray::getElement(int index){
    if (index>=0&&index<=cap) {
        return array[index];
        
    }else{
        printf("无法获取数组元素\n");
        return -1;
    }
}
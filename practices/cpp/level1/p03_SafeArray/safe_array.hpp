//
//  safe_array.hpp
//  stack
//
//  Created by iam24 on 16/3/31.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef safe_array_hpp
#define safe_array_hpp

#include <stdio.h>
class Safe_array
{
public:
    Safe_array(int capbility);
    void set(int n ,int value);
    void get(int n);
    
private:
    int all;
    int *data;
};
#endif /* safe_array_hpp */

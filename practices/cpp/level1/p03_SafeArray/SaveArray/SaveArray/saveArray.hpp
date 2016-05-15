//
//  saveArray.hpp
//  Queue
//
//  Created by 陈浩贤 on 16/3/31.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef saveArray_hpp
#define saveArray_hpp

#include <stdio.h>

#endif /* saveArray_hpp */

class SaveArray{
    
    public:
        SaveArray (int capbility);
        int getElement(int index);
        void setElement();
    
    private:
        int *array;
        int cap;
};
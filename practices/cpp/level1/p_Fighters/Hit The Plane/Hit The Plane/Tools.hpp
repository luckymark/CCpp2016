//
//  Tools.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Tools_hpp
#define Tools_hpp

#include <stdio.h>
#include "Ghost.hpp"

class Tool:public Ghost{
public:
    Tool(int kind);
    int type;
    void refresh();
    bool needClear();
private:
    int existTime=1000;
};
#endif /* Tools_hpp */

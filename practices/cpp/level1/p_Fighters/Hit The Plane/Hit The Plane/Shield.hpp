//
//  Shield.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/27.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Shield_hpp
#define Shield_hpp

#include <stdio.h>
#include "Ghost.hpp"

class Shield:public Ghost{
public:
    void setOwner(Ghost *owner);
    void open();
    void charge();
    void refresh();
    bool isOpen();
private:
    bool isOpened;
    int energy=300;
    Ghost *shieldOwner;
};
#endif /* Shield_hpp */

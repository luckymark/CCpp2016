//
//  Player.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Plane.hpp"

class Player:public Plane{
public:
    Player();
    
    void moveToLeft();
    void moveToRight();
    
};
#endif /* Player_hpp */

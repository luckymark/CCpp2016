//
//  Ghost.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Ghost_hpp
#define Ghost_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Ghost:public sf::Sprite{
public:
    virtual void refresh(){};
    void draw();
    bool intersects(Ghost *other);
};
#endif /* Ghost_hpp */

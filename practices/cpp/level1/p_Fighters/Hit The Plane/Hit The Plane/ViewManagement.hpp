//
//  ViewManagement.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef ViewManagement_hpp
#define ViewManagement_hpp

#include <stdio.h>
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>

class ViewManagement{
public:
    static sf::Texture PLAYER;
    static sf::Texture SKY;
    
    static void load();
    
};
#endif /* ViewManagement_hpp */

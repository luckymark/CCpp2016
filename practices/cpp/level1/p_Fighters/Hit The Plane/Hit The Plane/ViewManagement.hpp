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
    static sf::Texture BULLET;
    static sf::Texture ENEMY;
    static sf::Texture GAMEOVER;
    static sf::Texture ENEMYBULLET;
    static sf::Texture BOSS01;
    static sf::Texture BOSS02;
    static sf::Texture BOSS03;
    static sf::Texture BOSSBULLET;
    static sf::Texture SHIELD;
    static sf::Texture SHIELDBORDER;
    static sf::Texture SHIELDENERGY;
    static sf::Texture THREE;
    static sf::Texture TWO;
    static sf::Texture ONE;
    static sf::Texture PLUSONE;
    static sf::Texture CHOOSER;
    static sf::Texture EXPLOSION;
    static void load();
    
};
#endif /* ViewManagement_hpp */

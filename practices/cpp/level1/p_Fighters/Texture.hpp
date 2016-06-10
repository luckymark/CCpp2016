//
//  Texture.hpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/19.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Texture{
public:
    static sf::Texture player_texture;
    static sf::Texture enemy_texture;
    static sf::Texture player_bullet_texture;
    static sf::Texture enemy_bullet_texture;
    static sf::Texture background_texture;
    static sf::Texture gameover_texture;
    static sf::Texture player_destory;
    static sf::Texture enemy_boss_texture;
    static sf::Texture score_texture[10];
    static void load();
};
#endif /* Texture_hpp */

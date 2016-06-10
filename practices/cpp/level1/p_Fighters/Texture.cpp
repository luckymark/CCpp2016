//
//  Texture.cpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/19.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include "Texture.hpp"
#include "ResourcePath.hpp"

sf::Texture Texture::player_texture;
sf::Texture Texture::enemy_texture;
sf::Texture Texture::player_bullet_texture;
sf::Texture Texture::enemy_bullet_texture;
sf::Texture Texture::background_texture;
sf::Texture Texture::gameover_texture;
sf::Texture Texture::player_destory;
sf::Texture Texture::enemy_boss_texture;
sf::Texture Texture::score_texture[10];
void Texture::load()
{
    std::string path = resourcePath() + "shoot.png";
    enemy_texture.loadFromFile(path, sf::IntRect(0, 0, 69, 99));
    player_texture.loadFromFile(path, sf::IntRect(0, 99, 102, 126));
    player_bullet_texture.loadFromFile(path, sf::IntRect(1004, 987, 9, 21));
    enemy_bullet_texture.loadFromFile(path, sf::IntRect(69, 78, 9, 21));
    //enemy_bullet_texture.loadFromFile(resourcePath()+"200分.png");
    background_texture.loadFromFile(resourcePath()+"background.png");
    gameover_texture.loadFromFile(resourcePath()+"gameover.png");
    player_destory.loadFromFile(path, sf::IntRect(432, 624, 102, 126));
    enemy_boss_texture.loadFromFile(path, sf::IntRect(335, 759, 169, 258));
//    for (int i = 3;i <= 7 ;i++)
//    {
//        char filename[15];
//        sprintf(filename, "\"score%d.png\"",i);
//        printf("\n%s\n",filename);
//        score_texture[i].loadFromFile(resourcePath()+filename);
//    }
    score_texture[3].loadFromFile(resourcePath()+"score3.png");
    score_texture[4].loadFromFile(resourcePath()+"score4.png");
    score_texture[5].loadFromFile(resourcePath()+"score5.png");
    score_texture[6].loadFromFile(resourcePath()+"score6.png");
    score_texture[7].loadFromFile(resourcePath()+"score7.png");
}
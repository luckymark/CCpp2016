//
//  Texture.cpp
//  Fighters
//
//  Created by luckymark on 13-10-28.
//  Copyright (c) 2013年 luckymark. All rights reserved.
//

#include "Texture.hpp"
//#define resourcePath() (std::string)("")
#include <cstring>
sf::Texture Texture::HERO;
sf::Texture Texture::ENEMY_1;
sf::Texture Texture::ENEMY_2;
sf::Texture Texture::ENEMY_3;
sf::Texture Texture::ENEMY_4;
sf::Texture Texture::ENEMY_5;
sf::Texture Texture::ENEMY_BULLET_2;
sf::Texture Texture::BULLET;
sf::Texture Texture::ENEMY_BULLET;
sf::Texture Texture::MAIN_MENU_BACK_GROUND;
sf::Texture Texture::BLOOD[4];
sf::Texture Texture::STAGE_BACK_GROUND;
sf::Texture Texture::HELP_BACK_GROUND;
sf::Texture Texture::VICTORY_BACK_GROUND;
sf::Texture Texture::PICKUP[PICKUP_NUMBER];
sf::Texture Texture::CHOOSE_DIFFICULTY;
sf::Texture Texture::PARTICLE;
sf::Texture Texture::CLOUD;
void Texture::load() {
    for (int i = 0; i < PICKUP_NUMBER; ++i) {
        PICKUP[i].loadFromFile(resourcePath() + "pickup" + std::to_string(i) +
                               ".png");
    }
    for (int i = 0; i < 4; ++i) {
        BLOOD[i].loadFromFile(resourcePath() + "blood" + std::to_string(i + 1) +
                              ".png");
    }
    ENEMY_BULLET_2.loadFromFile(resourcePath() + "bullet3.png");
    HELP_BACK_GROUND.loadFromFile(resourcePath() + "help.png");
    MAIN_MENU_BACK_GROUND.loadFromFile(resourcePath() + "background.jpg");
    PARTICLE.loadFromFile(resourcePath() + "Particle.psd");
    STAGE_BACK_GROUND.loadFromFile(resourcePath() + "stage.png");
    HERO.loadFromFile(resourcePath() + "plane.psd");
    ENEMY_1.loadFromFile(resourcePath() + "enemy0.png");
    ENEMY_3.loadFromFile(resourcePath() + "enemy1.png");
    ENEMY_2.loadFromFile(resourcePath() + "enemy2.png");
    ENEMY_4.loadFromFile(resourcePath() + "enemy3.png");
    BULLET.loadFromFile(resourcePath() + "bullet1.psd");
    ENEMY_5.loadFromFile(resourcePath() + "enemy4.png");
    ENEMY_BULLET.loadFromFile(resourcePath() + "bullet2.psd");
    VICTORY_BACK_GROUND.loadFromFile(resourcePath() + "victory.jpg");
    CHOOSE_DIFFICULTY.loadFromFile(resourcePath() + "chooseDifficulty.jpg");
    CLOUD.loadFromFile(resourcePath()+"CLOUD.png");
}
//
//  Help.cpp
//  plane
//
//  Created by mac on 16/5/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Help.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#define STAGE_1 1
#define VICTORY 98
#define MAIN_MENU 0
#define HELP 99
Help::Help() { setTexture(Texture::HELP_BACK_GROUND); }
int Help::run(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        // Close window: exit
        switch (event.type) {
        case sf::Event::KeyPressed:
            return MAIN_MENU;
            break;
        default:
            break;
        }
    }
    return HELP;
}

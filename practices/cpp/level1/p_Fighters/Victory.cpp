//
//  Victory.cpp
//  plane
//
//  Created by mac on 16/5/6.
//  Copyright © 2016年 CCPP. All rights reserved.
//
#include "Hero.hpp"
#include "Score.hpp"
#include "Stage.hpp"
#include "Victory.hpp"
#define STAGE 1
#define VICTORY 98
#define MAIN_MENU 0
#define HELP 99
Victory::Victory() {
    setTexture(Texture::VICTORY_BACK_GROUND);
    font.loadFromFile(resourcePath() + "STHUPO.TTF");
    text.setFont(font);
    text.setCharacterSize(60);
    text.setPosition(900, 100);
}
int Victory::run(sf::RenderWindow &window) {
    window.draw(*this);
    text.setColor(sf::Color(0, 0, 0, 50 * clock.getElapsedTime().asSeconds()));
    window.draw(text);
    if (clock.getElapsedTime().asSeconds() < 5) {
        return VICTORY;
    } else {
        return STAGE;
    }
}
void Victory::pass() {
    Stage::getInstance()->initial();
    Hero::getInstance()->setPosition(100, 500);
    clock.restart();
    text.setString("# " +
                   std::to_string((Stage::getInstance()->stage + 1) / 10) +
                   std::to_string((Stage::getInstance()->stage + 1) % 10));
}
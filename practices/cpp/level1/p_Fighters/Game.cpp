//
//  Game.cpp
//  plane
//
//  Created by mac on 16/4/30.
//  Copyright © 2016年 CCPP. All rights reserved.
//
#include "ChooseDifficulty.hpp"
#include "Game.hpp"
#include "Help.hpp"
#include "Hero.hpp"
#include "MainMenu.hpp"
#include "Stage.hpp"
#include "Victory.hpp"
#define STAGE 1
#define VICTORY 98
#define MAIN_MENU 0
#define HELP 99
#define CHOOSE_DIFFICULTY 97
void Game::run(sf::RenderWindow &window) {
    while (window.isOpen()) {
        window.clear();
        switch (state) {
        case MAIN_MENU:
            state = MainMenu::getInstance()->run(window);
            MainMenu::getInstance()->draw(window);
            break;
        case HELP:
            state = Help::getInstance()->run(window);
            window.draw(*Help::getInstance());
            break;
        case STAGE:
            Hero::getInstance()->run(window);
            state = Stage::getInstance()->run();
            if (state == VICTORY) {
                Victory::getInstance()->pass();
                break;
            }
            state = Stage::getInstance()->collision();
            if (state != STAGE) {
                break;
            }
            Stage::getInstance()->draw(window);
            Hero::getInstance()->draw(window);
            break;
        case VICTORY:
            state = Victory::getInstance()->run(window);
            break;
        case CHOOSE_DIFFICULTY:
            state = ChooseDifficulty::getInstance()->run(window);
            ChooseDifficulty::getInstance()->draw(window);
            break;
        default:
            break;
        }
        window.display();
    }
}

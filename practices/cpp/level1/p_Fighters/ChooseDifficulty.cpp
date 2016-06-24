//
//  ChooseDifficulty.cpp
//  plane
//
//  Created by mac on 16/5/16.
//  Copyright © 2016年 CCPP. All rights reserved.
//
#define STAGE_1 1
#define VICTORY 98
#define MAIN_MENU 0
#define HELP 99
#define LOW 490
#define MID 620
#define HIGH 780
#include "Stage.hpp"
const int CHOOSE_DIFFICULTY = 97;
#include "ChooseDifficulty.hpp"
ChooseDifficulty::ChooseDifficulty() {
    setTexture(Texture::CHOOSE_DIFFICULTY);
    font.loadFromFile(resourcePath() + "STHUPO.TTF");
    arrow = sf::Text(L">", font, 60);
    arrow.setColor(sf::Color::Black);
    arrow.move(850, LOW);
    // 850 490
    // 850 620
    // 850 780
}
int ChooseDifficulty::run(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        // Close window: exit
        switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Return:
                if (arrow.getPosition().y == LOW) {
                    Stage::getInstance()->difficulty = 3;
                }
                if (arrow.getPosition().y == MID) {
                    Stage::getInstance()->difficulty = 2;
                }
                if (arrow.getPosition().y == HIGH) {
                    Stage::getInstance()->difficulty = 1;
                }
                return VICTORY;
                break;
            case sf::Keyboard::Up:
                if (arrow.getPosition().y == MID) {
                    arrow.setPosition(850, LOW);
                }
                if (arrow.getPosition().y == HIGH) {
                    arrow.setPosition(850, MID);
                }
                break;
            case sf::Keyboard::Down:
                if (arrow.getPosition().y == MID) {
                    arrow.setPosition(850, HIGH);
                }
                if (arrow.getPosition().y == LOW) {
                    arrow.setPosition(850, MID);
                }
                break;
            case sf::Keyboard::Escape:
                window.close();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    return CHOOSE_DIFFICULTY;
}
void ChooseDifficulty::draw(sf::RenderWindow &window) {
    window.draw(*this);
    window.draw(arrow);
}
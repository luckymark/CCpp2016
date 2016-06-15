//
//  Score.cpp
//  plane
//
//  Created by mac on 16/5/5.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Score.hpp"
#include <cstring>
void Score::initial() { score = 0; }
Score::Score() {
    score = 0;
    font.loadFromFile(resourcePath() + "STHUPO.TTF");
    setFont(font);
    setCharacterSize(40);
    setPosition(1630, 30);
}
void Score::getScore(int score) { this->score += score; }
void Score::draw(sf::RenderWindow &window) {
    setString(L"当前分数:" + std::to_wstring(score));
    window.draw(*this);
}
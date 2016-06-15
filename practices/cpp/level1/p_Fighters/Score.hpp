//
//  Score.hpp
//  plane
//
//  Created by mac on 16/5/5.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp
#include "ResourcePath.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Score : public sf::Text {
  private:
    Score();
    sf::Font font;
    int score;

  public:
    void initial();
    void draw(sf::RenderWindow &window);
    void getScore(int score);
    static Score *getInstance() {
        static Score *singleton;
        if (singleton == NULL) {
            singleton = new Score();
        }
        return singleton;
    }
};
#endif
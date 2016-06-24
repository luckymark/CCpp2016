//
//  ChooseDifficulty.hpp
//  plane
//
//  Created by mac on 16/5/16.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef ChooseDifficulty_hpp
#define ChooseDifficulty_hpp
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class ChooseDifficulty : public sf::Sprite {
private:
    ChooseDifficulty();
    sf::Text arrow;
    sf::Font font;
public:
    static ChooseDifficulty *getInstance() {
        static ChooseDifficulty *singleton;
        if (singleton == NULL) {
            singleton = new ChooseDifficulty();
        }
        return singleton;
    }
    int run(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
};
#endif /* ChooseDifficulty_hpp */

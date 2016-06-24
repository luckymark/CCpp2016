//
//  Help.hpp
//  plane
//
//  Created by mac on 16/5/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Help_hpp
#define Help_hpp
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#define WIDTH 870
#define LOW 500
#define MID 560
#define HIGH 920
class Help : public sf::Sprite {
  private:
    Help();

  public:
    static Help *getInstance() {
        static Help *singleton;
        if (singleton == NULL) {
            singleton = new Help();
        }
        return singleton;
    }
    int run(sf::RenderWindow &window);
};
#endif /* Help_hpp */

//
//  MainMenu.hpp
//  plane
//
//  Created by mac on 16/4/30.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

class MainMenu {
  public:
    int run(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    static MainMenu *getInstance() {
        static MainMenu *singleton;
        if (singleton == NULL) {
            singleton = new MainMenu();
        }
        return singleton;
    }

  private:
    MainMenu();
    void move(bool operation);
    sf::Sprite backGround;
    sf::Text arrow;
    sf::Font font;
};
#endif /* MainMenu_hpp */

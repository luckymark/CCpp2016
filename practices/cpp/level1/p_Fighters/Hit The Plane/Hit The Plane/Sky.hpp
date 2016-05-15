//
//  Sky.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Sky_hpp
#define Sky_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Sky{
public:
    static Sky *getInstance();
    sf::RenderWindow *getWindow(){
        return this->window;
    }
    void refresh();
    
    
private:
    Sky();
    
    sf::RenderWindow *window;
    
    sf::Sprite *backgroud=nullptr;
    
    static Sky *instance;
    
    void clear();
    void collision();
    void creatEnemies();
    
};

#endif /* Sky_hpp */

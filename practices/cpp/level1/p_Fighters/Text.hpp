//
//  Text.hpp
//  My first app
//
//  Created by macintosh on 16/5/13.
//  Copyright © 2016年 interesting. All rights reserved.
//

#ifndef Text_hpp
#define Text_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <stdio.h>
using namespace std;
class Text{
public:
    sf::Text start[2];
    sf::Text gameOver;
    sf::Text rePlay;
    sf::Text grade;
    sf::Text point;
    sf::Text pri;
    sf::Text lifeNum;
    sf::Text bigFireNum;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Text life;
    int size,p,k1,k2,time;
    double posy,posx;
    Text(sf::Font &font)
    {
        k1=0; k2=0; time=1000;
        
        texture.loadFromFile(resourcePath()+"箭头.png");
        sprite.setTexture(texture);
        sprite.setPosition(560,455);
        
        p=0;
        size=50;
        
        lifeNum.setFont(font);
        
        bigFireNum.setFont(font);
        bigFireNum.setCharacterSize(20);
        bigFireNum.setString(L"大招:");
        bigFireNum.setPosition(0,77);
        
        life.setFont(font);
        life.setCharacterSize(20);
        life.setString(L"生命:");
        life.setPosition(0,102);
        
        start[0].setFont(font);
        start[0].setCharacterSize(size);
        start[0].setString(L"开始游戏");
        start[0].setPosition(650,450);
        
        start[1].setFont(font);
        start[1].setCharacterSize(size);
        start[1].setString(L"退出游戏");
        start[1].setPosition(650,500);

        gameOver.setFont(font);
        gameOver.setCharacterSize(150);
        gameOver.setString(L"游戏结束");
        gameOver.setPosition(460,100);
        
        grade.setFont(font);
        grade.setCharacterSize(size);
        grade.setString(L"最终得分:");
        grade.setPosition(510,300);
        
        rePlay.setFont(font);
        rePlay.setCharacterSize(size);
        rePlay.setString(L"再玩一次");
        rePlay.setPosition(650,450);
        
        point.setFont(font);
        point.setCharacterSize(30);
        point.setString(L"得分:");
        point.setPosition(5,960);
    }
    void move()
    {
        time=min(time+1,10000);
        if (time<50 || (k1+k2)==0) return;
        p=(p+abs(k1+k2))%2;
        if (p==0)
        {
            posy=560;
            posx=455;
        }
        if (p==1)
        {
            posy=560;
            posx=507;
        }
        sprite.setPosition(posy,posx);
        time=0;
    }
};
#endif /* Text_hpp */

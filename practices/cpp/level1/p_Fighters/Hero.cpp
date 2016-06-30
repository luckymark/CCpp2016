#include "Hero.h"
#include"Rect.h"
#include"Sky.h"
#include"Bullet.h"
#include"Win_end.h"
#include<SFML/Graphics.hpp>
    int Hero::hx=230;
    int Hero::hy=500;
    int Hero::heartlife=0;
    sf::Sprite Hero::shero;
void Hero::build(){
    heartlife=3;
}
void Hero::draw_myself(){

    this->hero.loadFromFile("F:\\reso\\fighter1.png",sf::IntRect(0,3,48,68));
    this->shero.setPosition(sf::Vector2f(hx,hy));
    this->shero.setTexture(this->hero);
}
void Hero::move(){
    if(this->heartlife>0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(hx>0){
            hx-=2;
        }
        else{
            hx=0;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(hx<460){
            hx+=2;
        }
        else{
            hx=460;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(hy>0){
            hy-=2;
        }
        else{
            hy=0;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(hy<580){
            hy+=2;
        }
        else{
            hy=580;
        }
    }
    Hero::draw_myself();
    }
    else{
        Win_end *winend=new Win_end;
        while(winend->Win_end->isopen()){
        sf::Texture endPicture;
        endPicture.loadFromFile("F:\\reso\\end.jpg");
        sf::Sprite sendPicture;
        sendPicture.setTexture(endPicture);
        winend->win_end->draw(sendPicture);
        winend->win_end->display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            Win_end->win_end->close();
        }
    }
        }

}









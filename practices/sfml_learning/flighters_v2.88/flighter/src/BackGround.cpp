
#include "BackGround.h"
#include "GameTexture.h"
#include <SFML/Window.hpp>
#include "GameWindow.h"
BackGround* BackGround::_instance=0;
BackGround::BackGround()
{

}
void BackGround::load() {
    //IniBackGround=*GameSprite::background;
    window=GameWindow::instance();
    topBackGround.setTexture(GameTexture::background);
    bottomBackGround.setTexture(GameTexture::background);
    //topBackGround.setColor(sf::Color::Black);
    //bottomBackGround.setColor(sf::Color::Black);
    speed=100.f;
    partline=GameWindow::windowHeight;
}

void BackGround::refresh(float detalTime) {
    partline-=speed*detalTime;
    if(partline < 0)
        partline+=GameWindow::windowHeight;
    //topBackGround.setTextureRect(0.f,)
    topBackGround.setPosition(sf::Vector2f(0.f,-partline));
    bottomBackGround.setPosition(sf::Vector2f(0.f,GameWindow::windowHeight-partline));
}
void BackGround::draw()
{
    window->draw(topBackGround);
    window->draw(bottomBackGround);
}
BackGround* BackGround::instance() {
    if(_instance==0)
        _instance=new BackGround;
    return _instance;
}

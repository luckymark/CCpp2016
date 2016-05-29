
#include "BackGround.h"
#include "GameTexture.h"
#include <SFML/Window.hpp>
#include "GameWindow.h"
BackGround* BackGround::_instance=0;
BackGround::BackGround()
{

}
void BackGround::load() {
    window=GameWindow::instance();
    topBackGround.setTexture(GameTexture::background);
    bottomBackGround.setTexture(GameTexture::background);
    setIniPosition();
    speed=100.f;
}
void BackGround::setIniPosition()
{
    topBackGround.setPosition(0,-GameWindow::windowHeight);
    bottomBackGround.setPosition(0,0);
}
void BackGround::refresh(float detalTime) {
    topBackGround.move(sf::Vector2f(0,speed*detalTime));
    bottomBackGround.move(sf::Vector2f(0,speed*detalTime));
    if(topBackGround.getPosition().y >= 0 )
        setIniPosition();
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

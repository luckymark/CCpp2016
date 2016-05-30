
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
    setColor();
    shader=Shader::instance();
    shader->load();
    speed=100.f;
}
void BackGround::setColor()
{
    topBackGround.setColor(sf::Color(128,128,128));
    bottomBackGround.setColor(sf::Color(128,128,128));
}
void BackGround::setIniPosition()
{
    topBackGround.setPosition(0,-GameWindow::windowHeight);
    bottomBackGround.setPosition(0,0);
}
void BackGround::refresh(float detalTime) {
    //setColor();
    topBackGround.move(sf::Vector2f(0,speed*detalTime));
    bottomBackGround.move(sf::Vector2f(0,speed*detalTime));
    if(topBackGround.getPosition().y >= 0 )
        setIniPosition();
}
void BackGround::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(topBackGround, shader->getInvertShader());
    target.draw(bottomBackGround, shader->getInvertShader());
}

BackGround* BackGround::instance() {
    if(_instance==0)
        _instance=new BackGround;
    return _instance;
}

#include "GameWindow.h"
#include <SFML/Window.hpp>
int GameWindow::windowHeight=600;
int GameWindow::windowWidth=480;
float GameWindow::iniHeight=500.f;
float GameWindow::iniWidth=190.f;
GameWindow* GameWindow::_instance=0;
GameWindow* GameWindow::instance()
{
    if(_instance==0)
        _instance=new GameWindow;
    return _instance;
}
void GameWindow::initializeWindow()
{
    _instance->create(sf::VideoMode(windowWidth,windowHeight),"flighter");
    _instance->setVerticalSyncEnabled(true);
    _instance->setFramerateLimit(60);
}
GameWindow::GameWindow()
{

}

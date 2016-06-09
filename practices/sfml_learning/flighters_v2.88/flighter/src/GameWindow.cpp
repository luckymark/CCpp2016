#include "GameWindow.h"
#include <SFML/Window.hpp>
int GameWindow::windowHeight=800;
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
    _instance->create(sf::VideoMode(sf::VideoMode::getDesktopMode().height * 0.8 * windowWidth / windowHeight, sf::VideoMode::getDesktopMode().height * 0.8),"flighter");
    myView.setCenter(windowWidth / 2, windowHeight / 2);
	myView.setSize(windowWidth, windowHeight);
	_instance->setView(myView);
    _instance->setVerticalSyncEnabled(true);
    _instance->setFramerateLimit(60);
}
GameWindow::GameWindow()
{

}

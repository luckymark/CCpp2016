#include "GameText.h"
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
std::string GameText::path = "resources/font/";
GameText* GameText::_instance = 0;
GameText::GameText()
{
    window=GameWindow::instance();
}
GameText* GameText::instance()
{
    if(_instance==0)
        _instance = new GameText;
    return _instance;
}
void GameText::loadFont()
{
    _font.loadFromFile(path+"STHeiti Light.ttc");
    text.setFont(_font);
    text.setCharacterSize(15);
    text.setPosition(10.f,10.f);
    text.setColor(sf::Color::White);
    gameOverText.setFont(_font);
    gameOverText.setCharacterSize(30);
    gameOverText.setPosition(GameWindow::windowWidth/5.f,GameWindow::windowHeight/3.f);
    text.setColor(sf::Color::White);
}
void GameText::showGameInfo(int _score,int _hp)
{
    toString(_hp,hp);
    toString(_score,score);
    text.setString("score: "+score+"\n\nlife: "+hp);
    window->draw(text);
}
void GameText::showGameOverInfo(int _score)
{
    toString(_score,score);
    gameOverText.setString("score: "+score+"\n\nPress Esc to exit game\n\nPress R to continue");
    window->draw(gameOverText);
}
void GameText::toString(int u,std::string& t)
{
    ache.clear();
    ache << u;
    ache >> t;
}



#ifndef GAMETEXT_H
#define GAMETEXT_H
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include <sstream>
class GameText
{
public:
    void loadFont();
    void showGameInfo(int,int);
    void showScore(int);
    void showHP(int);
    void toString(int,std::string&);
    static GameText* instance();
    void showGameOverInfo(int);
protected:
    GameText();
private:
    sf::Font _font;
    static GameText* _instance;
    static std::string path;
    sf::Text text;
    sf::Text gameOverText;
    GameWindow* window;
    std::string score,hp;
    std::stringstream ache;
};

#endif // GAMETEXT_H

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class GameWindow:public sf::RenderWindow
{
public:
    static int windowWidth;
    static int windowHeight;
    static float iniWidth;
    static float iniHeight;
    static GameWindow* instance();
    void initializeWindow();
    //void create(VideoMode mode, const String &title, Uint32 style=Style::Default, const ContextSettings &settings=ContextSettings());
protected:
    GameWindow();
private:
    static GameWindow* _instance;
    sf::View myView;

};

#endif // GAMEWINDOW_H

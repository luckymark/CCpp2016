#ifndef FONT_H
#define FONT_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Font
{
public:
    static void LoadFont();
    static sf::Font font;
};

#endif // FONT_H

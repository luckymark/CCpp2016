#include "Font.h"
#include "Sound.h"

sf::Font Font::font;

void Font::LoadFont()
{
    font.loadFromFile("cour.ttf");
}

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Background
{
public:
    static sf::Texture BackgroundTexture;
    static sf::Sprite BackgroundSprite;
    static sf::Texture BeforeGameStartTexture;
    static sf::Sprite BeforeGameStartSprite;
    static sf::Texture GameoverTexture;
    static sf::Sprite GameoverSprite;
    static void LoadBackground();
    static void show (sf::RenderWindow& window);
};

#endif // BACKGROUND_H

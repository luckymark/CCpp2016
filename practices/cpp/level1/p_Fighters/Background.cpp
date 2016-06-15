#include "Background.h"

sf::Texture Background::BackgroundTexture;
sf::Sprite Background::BackgroundSprite;
sf::Texture Background::BeforeGameStartTexture;
sf::Sprite Background::BeforeGameStartSprite;
sf::Texture Background::GameoverTexture;
sf::Sprite Background::GameoverSprite;

void Background::LoadBackground()
{
        BackgroundTexture.loadFromFile("background.png");
        BackgroundSprite.setTexture(BackgroundTexture);
        BeforeGameStartTexture.loadFromFile("before_game_start.png");
        BeforeGameStartSprite.setTexture(BeforeGameStartTexture);
        GameoverTexture.loadFromFile("gameover.png");
        GameoverSprite.setTexture(GameoverTexture);
}

void Background::show(sf::RenderWindow& window)
{
    window.draw(Background::BackgroundSprite);
}


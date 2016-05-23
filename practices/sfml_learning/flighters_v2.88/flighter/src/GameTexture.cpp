#include "GameTexture.h"
#include <SFML/Graphics.hpp>
sf::Texture GameTexture::background;
sf::Texture GameTexture::shoot;
sf::Texture GameTexture::gameover;
std::string GameTexture::path="resources/image/";
void GameTexture::load()
{
    background.loadFromFile(path+"background.png");
    shoot.loadFromFile(path+"shoot.png");
    gameover.loadFromFile(path+"gameover.png");
}

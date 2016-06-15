#include "Sprites.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

sf::Texture Sprites::shoot;
sf::Sprite Sprites::hero;
sf::Sprite Sprites::bullet;
sf::Sprite Sprites::enemy1;
sf::Sprite Sprites::enemy2;
sf::Sprite Sprites::enemy2_hit;
sf::Sprite Sprites::enemy3_n2;
sf::Sprite Sprites::enemy3_n1;
sf::Sprite Sprites::enemy3_hit;
sf::Sprite Sprites::enemy1_down1;
sf::Sprite Sprites::enemy1_down2;
sf::Sprite Sprites::enemy1_down3;
sf::Sprite Sprites::enemy1_down4;
sf::Sprite Sprites::enemy2_down1;
sf::Sprite Sprites::enemy2_down2;
sf::Sprite Sprites::enemy2_down3;
sf::Sprite Sprites::enemy2_down4;
sf::Sprite Sprites::enemy3_down1;
sf::Sprite Sprites::enemy3_down2;
sf::Sprite Sprites::enemy3_down3;
sf::Sprite Sprites::enemy3_down4;
sf::Sprite Sprites::enemy3_down5;
sf::Sprite Sprites::enemy3_down6;

void Sprites::LoadSprites()
{
    shoot.loadFromFile("shoot.png");
    hero.setTexture(shoot);
    bullet.setTexture(shoot);
    enemy1.setTexture(shoot);
    enemy1_down1.setTexture(shoot);
    enemy1_down2.setTexture(shoot);
    enemy1_down3.setTexture(shoot);
    enemy1_down4.setTexture(shoot);
    enemy2.setTexture(shoot);
    enemy2_hit.setTexture(shoot);
    enemy2_down1.setTexture(shoot);
    enemy2_down2.setTexture(shoot);
    enemy2_down3.setTexture(shoot);
    enemy2_down4.setTexture(shoot);
    enemy3_n2.setTexture(shoot);
    enemy3_n1.setTexture(shoot);
    enemy3_hit.setTexture(shoot);
    enemy3_down1.setTexture(shoot);
    enemy3_down2.setTexture(shoot);
    enemy3_down3.setTexture(shoot);
    enemy3_down4.setTexture(shoot);
    enemy3_down5.setTexture(shoot);
    enemy3_down6.setTexture(shoot);
    hero.setTextureRect(sf::IntRect(0,99,102,126));
    bullet.setTextureRect(sf::IntRect(69,78,9,21));
    enemy1.setTextureRect(sf::IntRect(534,612,57,43));
    enemy1_down1.setTextureRect(sf::IntRect(267,347,57,51));
    enemy1_down2.setTextureRect(sf::IntRect(873,697,57,51));
    enemy1_down3.setTextureRect(sf::IntRect(267,296,57,51));
    enemy1_down4.setTextureRect(sf::IntRect(930,697,57,51));
    enemy2.setTextureRect(sf::IntRect(0,0,69,95));
    enemy2_hit.setTextureRect(sf::IntRect(432,525,69,95));
    enemy2_down1.setTextureRect(sf::IntRect(534,655,69,95));
    enemy2_down2.setTextureRect(sf::IntRect(603,655,69,95));
    enemy2_down3.setTextureRect(sf::IntRect(672,653,69,95));
    enemy2_down4.setTextureRect(sf::IntRect(741,653,69,95));
    enemy3_n2.setTextureRect(sf::IntRect(504,750,169,258));
    enemy3_n1.setTextureRect(sf::IntRect(335,750,169,258));
    enemy3_hit.setTextureRect(sf::IntRect(166,750,169,258));
    enemy3_down1.setTextureRect(sf::IntRect(0,486,169,258));
    enemy3_down2.setTextureRect(sf::IntRect(0,225,169,258));
    enemy3_down3.setTextureRect(sf::IntRect(839,748,169,258));
    enemy3_down4.setTextureRect(sf::IntRect(165,486,169,258));
    enemy3_down5.setTextureRect(sf::IntRect(673,748,169,258));
    enemy3_down6.setTextureRect(sf::IntRect(0,747,169,258));
    hero.setScale(0.6,0.6);
    enemy3_n2.setScale(0.6,0.6);
    enemy3_n1.setScale(0.6,0.6);
    enemy3_hit.setScale(0.6,0.6);
    enemy3_down1.setScale(0.6,0.6);
    enemy3_down2.setScale(0.6,0.6);
    enemy3_down3.setScale(0.6,0.6);
    enemy3_down4.setScale(0.6,0.6);
    enemy3_down5.setScale(0.6,0.6);
    enemy3_down6.setScale(0.6,0.6);
}

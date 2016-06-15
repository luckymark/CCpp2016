#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <cstdlib>
#include "Background.h"
#include "Sound.h"
#include "Sprites.h"
#include "Hero.h"
#include "Enemys.h"
#include "Font.h"
int shot_counter=0;
sf::RenderWindow window(sf::VideoMode(400,600),"fighters");
int main()
{
    srand(time(NULL));
    Background::LoadBackground();
    Sound::LoadSounds();
    Sprites::LoadSprites();
    Font::LoadFont();
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shot_counter==0){
            break;
        }
        window.draw(Background::BeforeGameStartSprite);
        window.display();
    }
    Hero hero;
    Enemys enemys;
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shot_counter++;
        shot_counter%=10;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shot_counter==0)
        {
            hero.fire();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            hero.MoveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            hero.MoveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            hero.MoveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            hero.MoveDown();
        }
        Sound::PlayBackgroundMusic();
        Background::show(window);
        hero.turn(window);
        enemys.turn(window);
        window.display();

        if (hero.GetHealth()<=0) break;
    }

    return 0;
}

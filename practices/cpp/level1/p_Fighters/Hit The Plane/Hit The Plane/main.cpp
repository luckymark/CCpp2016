
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

#include "Sky.hpp"
#include "Player.hpp"
#include "ViewManagement.hpp"

int main(int, char const**)
{
    // Load a music to play
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile(resourcePath() + "RUOK.ogg")) {
        return EXIT_FAILURE;
    }
    // Play the music
    backgroundMusic.play();
    
    ViewManagement ::load();
    Sky *sky=Sky::getInstance();
    sf::RenderWindow *window=sky->getWindow();
    
    Player player;
    sky->addPlayer(&player);
    
    // Start the game loop
    while (window->isOpen())
    {
        
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
            if (event.key.code==sf::Keyboard::Space) {
                player.fire();
            }
        }
        
        if (!player.isDead()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                player.moveToLeft();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                player.moveToRight();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                player.moveToUp();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                player.moveToDown();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                player.openShield();
            }else{
                player.closeShield();
            }
        }else{
            int chosserPosition;
            sky->clearAll();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sky->moveChosser(0);
                chosserPosition=0;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sky->moveChosser(1);
                chosserPosition=1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                if (chosserPosition==0) {
                    player.reborn();
                    sky->restartGame();
                    // Play the music
                    backgroundMusic.play();
                }else if (chosserPosition==1)
                    window->close();
            }
        }
        sky->refresh();
    }

    return EXIT_SUCCESS;
}

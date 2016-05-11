#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"My window");
    sf::Music music;
    if(!music.openFromFile("resources/music/bgm/th07_01.ogg"))
        return -1;
    music.play();
    music.setLoop(true);
    window.clear(sf::Color::Black);
    sf::Texture Hero;
    if(!Hero.loadFromFile("resources/image/flighter.png"))
        return -1;
    Hero.setSmooth(true);
    sf::Sprite heroSprite(Hero);
    heroSprite.setColor(sf::Color::Red);
    heroSprite.setPosition(sf::Vector2f(400,500));
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        sf::FloatRect nowPosition=heroSprite.getGlobalBounds();
        float left=nowPosition.left,right=left+nowPosition.width,top=nowPosition.top,bottom=top+nowPosition.height;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left>0)
            heroSprite.move(-0.1,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && right<800)
            heroSprite.move(0.1,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && top>0)
            heroSprite.move(0,-0.1);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bottom<600)
            heroSprite.move(0,0.1);
        window.draw(heroSprite);
        window.display();
    }
    return 0;
}

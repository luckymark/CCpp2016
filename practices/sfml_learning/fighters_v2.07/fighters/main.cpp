#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define RecHero 0, 99, 102, 126
#define RecBullet 1004, 987, 9, 21
int main()
{
    const int gameWidth=800;
    const int gameHeight=600;
    const float flightSpeed=400.f;
    sf::RenderWindow window(sf::VideoMode(gameWidth,gameHeight),"My window");
    window.setVerticalSyncEnabled(true);
    sf::Music music;
    if(!music.openFromFile("resources/music/bgm/th07_01.ogg"))
        return -1;
    music.play();
    music.setLoop(true);

    sf::Texture shoot;
    if(!shoot.loadFromFile("resources/image/shoot.png"))
        return -1;

    shoot.setSmooth(true);
    sf::Sprite heroSprite(shoot),BulletSprite(shoot);
    heroSprite.setTextureRect(sf::IntRect(RecHero));
    BulletSprite.setTextureRect(sf::IntRect(RecBullet));
    heroSprite.setColor(sf::Color::Red);
    heroSprite.setPosition(sf::Vector2f(400,500));
    sf::Clock clock;
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
        float detalTime=clock.restart().asSeconds();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left>0)
            heroSprite.move(-flightSpeed*detalTime,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && right<800)
            heroSprite.move(flightSpeed*detalTime,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && top>0)
            heroSprite.move(0,-flightSpeed*detalTime);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bottom<600)
            heroSprite.move(0,flightSpeed*detalTime);
        window.clear(sf::Color::Black);
        window.draw(heroSprite);
        window.display();
    }
    return 0;
}

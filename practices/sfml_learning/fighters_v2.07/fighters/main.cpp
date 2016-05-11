#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define RecHero 0, 99, 102, 126
#define RecBullet 1004, 987, 9, 21

sf::Sprite makeBullet(sf::Sprite aBullet,sf::Vector2f bulletRec);
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
    sf::Sprite heroSprite(shoot),singleBullet(shoot);
    std::vector<sf::Sprite>Bullets;
    heroSprite.setTextureRect(sf::IntRect(RecHero));
    singleBullet.setTextureRect(sf::IntRect(RecBullet));
    //singleBullet.setColor(sf::Color::Blue);
    heroSprite.setColor(sf::Color::Red);
    heroSprite.setPosition(sf::Vector2f(400,500));
    sf::Clock clock,PressSpace;
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
        float centerX=(left+right)/2.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            sf::Clock temp(PressSpace);
            float detalPressSpace=temp.restart().asSeconds();
            if(detalPressSpace>0.2f)
            {
                PressSpace.restart();
                Bullets.push_back(makeBullet(singleBullet,sf::Vector2f(centerX,top)));
            }

        }

        window.clear(sf::Color::Black);
        for(auto &c:Bullets)
        {
            c.move(0,-flightSpeed*detalTime);
            window.draw(c);
        }
        window.draw(heroSprite);
        window.display();
    }
    return 0;
}
sf::Sprite makeBullet(sf::Sprite aBullet,const sf::Vector2f bulletRec)
{
    sf::Sprite tarBullet(aBullet);
    tarBullet.setPosition(bulletRec);
    return tarBullet;
}

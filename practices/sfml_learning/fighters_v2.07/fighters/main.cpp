#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <iostream>
#include <ctime>
#define RecHero 0, 99, 102, 126
#define RecBullet 1004, 987, 9, 21
#define RecEnemy 534, 612, 57, 43
#define RecEnemyBomb1 267, 347, 57, 51
#define RecEnemyBomb2 873, 697, 57, 51
#define RecEnemyBomb3 267, 296, 57, 51
#define RecEnemyBomb4 930, 697, 57, 51
sf::Sprite makeBullet(sf::Sprite aBullet,sf::Vector2f bulletRec);
void creatEnemyFlighters(sf::Sprite aEnemy,std::list<sf::Sprite>& EnemyFlighters);
//void checkCollision(std::list<sf::Sprite>&Bullets,std::list<sf::Sprite>& EnemyFlighters,std::list<sf::Sprite> &EnemyBombImage);
//void showCollision(std::list<)
const int gameWidth=800;
const int gameHeight=600;
const float flightSpeed=400.f;
const float HerobulletSpeed=600.f;
const float EnemySpeed = 100.f;
int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    //sf::RenderWindow window(sf::VideoMode(gameWidth,gameHeight),"My window");
    sf::RenderWindow window;
    window.create(sf::VideoMode(gameWidth,gameHeight),"My window");
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
    sf::Sprite heroSprite(shoot),singleBullet(shoot),singleEnemy(shoot),bomb1(shoot),bomb2(shoot),bomb3(shoot);
    std::list<sf::Sprite>Bullets;
    std::list<sf::Sprite>EnemyFlighters;
    std::list<sf::Sprite>EnemyBombImage;
    heroSprite.setTextureRect(sf::IntRect(RecHero));
    singleBullet.setTextureRect(sf::IntRect(RecBullet));
    singleEnemy.setTextureRect(sf::IntRect(RecEnemy));
    //singleBullet.setColor(sf::Color::Blue);
    heroSprite.setColor(sf::Color::Red);
    heroSprite.setPosition(sf::Vector2f(400,500));
    sf::Clock clock,PressSpace,creatEnemy;
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
        if(true)
        {

            sf::Clock temp(creatEnemy);
            float detalCreatEnemy=temp.restart().asSeconds();
            if(detalCreatEnemy>3.f)
            {
                creatEnemy.restart();
                creatEnemyFlighters(singleEnemy,EnemyFlighters);
            }
        }
        window.clear(sf::Color::Black);
        //checkCollision(Bullets,EnemyFlighters);
        for(auto it=Bullets.begin();it!=Bullets.end();++it)
        {
            //detalTime = clock.restart().asSeconds();
           // std::cout<<"The total bullets "<<Bullets.size()<<std::endl;
            if(it->getGlobalBounds().top>5.f)
            {
                it->move(0,-detalTime*HerobulletSpeed);
                window.draw(*it);
            }
            else
                it=Bullets.erase(it);
        }

        for(auto it=EnemyFlighters.begin();it!=EnemyFlighters.end();++it)
        {
            //detalTime = clock.restart().asSeconds();
            //std::cout<<"The total bullets "<<Bullets.size()<<std::endl;
            if(it->getGlobalBounds().top<gameHeight)
            {
                it->move(0,detalTime*EnemySpeed);
                window.draw(*it);
            }
            else
                it=Bullets.erase(it);
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
void creatEnemyFlighters(sf::Sprite aEnemy,std::list<sf::Sprite>& EnemyFlighters)
{

    int isCreat=std::rand()%10;
    if(isCreat>3)
        return ;
    sf::Sprite tarEnemy(aEnemy);
    tarEnemy.setPosition(sf::Vector2f(std::rand()%gameWidth,0.f));
    EnemyFlighters.push_back(tarEnemy);
    std::cout<<"creat successfuly!"<<std::endl;
}
/*
void checkCollision(std::list<sf::Sprite>&Bullets,std::list<sf::Sprite>& EnemyFlighters,std::list<sf::sprite> &EnemyBombImage)
{
    for(auto itBullets=Bullets.begin();itBullets!=Bullets.end();itBullets++)
    {
        for(auto itEnemy=EnemyFlighters.begin();itEnemy!=EnemyFlighters.end();itEnemy++)
            if(itBullets->getGlobalBounds().intersects(itEnemy->getGlobalBounds()))
            {
                itBullets=Bullets.erase(itBullets);
                itEnemy=EnemyFlighters.erase(itEnemy);
               // showCollision(EnemyBombImage);
            }
    }
}
*/

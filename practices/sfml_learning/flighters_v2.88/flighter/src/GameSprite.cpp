#include "GameSprite.h"
#include "GameTexture.h"
#include <list>
std::vector<sf::Sprite>GameSprite::Hero;
std::vector<sf::Sprite>GameSprite::HeroBomb;

sf::Sprite GameSprite::HeroBullet;
sf::Sprite GameSprite::EnemyBullet;

sf::Sprite GameSprite::Copter;
sf::Sprite GameSprite::CopterHit;
std::vector<sf::Sprite>GameSprite::CopterBomb;

sf::Sprite GameSprite::Warplane;
std::vector<sf::Sprite>GameSprite::WarplaneBomb;

std::vector<sf::Sprite>GameSprite::Warship;
sf::Sprite GameSprite::WarshipHit;
std::vector<sf::Sprite>GameSprite::WarshipBomb;

std::vector<sf::Sprite>GameSprite::ufo;

sf::Sprite GameSprite::background;
sf::Sprite GameSprite::gameover;

//std::list<sf::Sprite>GameSprite::plane;
//std::list<sf::Sprite>GameSprite::bullet;
void GameSprite::load()
{
    Hero.push_back(sf::Sprite(GameTexture::shoot,sf::IntRect(0, 99, 102,126)));
    Hero.push_back(sf::Sprite(GameTexture::shoot,sf::IntRect(165, 360, 102, 126)));
    for(auto& c:Hero)
        c.setColor(sf::Color::Red);
    HeroBomb.push_back(sf::Sprite(GameTexture::shoot,sf::IntRect(165, 234, 102, 126)));
    HeroBomb.push_back(sf::Sprite(GameTexture::shoot,sf::IntRect(330, 624, 102, 126)));
    HeroBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(330, 498, 102 ,126)));
    HeroBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(432, 624, 102, 126)));
    for(auto& c:HeroBomb)
        c.setColor(sf::Color::Red);

    HeroBullet= sf::Sprite(GameTexture::shoot,sf::IntRect(1004, 987, 9, 21));
    HeroBullet.setColor(sf::Color::Red);

    EnemyBullet= sf::Sprite(GameTexture::shoot,sf::IntRect(69, 78, 9, 21));
    EnemyBullet.setColor(sf::Color::Blue);

    Copter= sf::Sprite(GameTexture::shoot,sf::IntRect(0, 0, 69, 99));
    Copter.setColor(sf::Color::Blue);
    CopterHit= sf::Sprite(GameTexture::shoot,sf::IntRect(432, 525, 69, 99));
    Copter.setColor(sf::Color::Blue);
    CopterBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(534, 655, 69, 99)));
    CopterBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(603, 655, 69, 99)));
    CopterBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(672, 653, 69, 99)));
    CopterBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(741, 653, 69, 99)));
    for(auto& c:CopterBomb)
        c.setColor(sf::Color::Blue);

    Warplane= sf::Sprite(GameTexture::shoot,sf::IntRect( 534, 612, 57, 43));
    Warplane.setColor(sf::Color::Blue);
    WarplaneBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(267, 347, 57, 51)));
    WarplaneBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(873, 697, 57, 51)));
    WarplaneBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(267, 297, 57, 51)));
    WarplaneBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(930, 697, 57, 51)));
    for(auto& c:WarplaneBomb)
        c.setColor(sf::Color::Blue);

    Warship.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(335, 750, 169, 258)));
    Warship.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(504, 750, 169, 258)));
    for(auto& c:Warship)
        c.setColor(sf::Color::Blue);
    WarshipHit= sf::Sprite(GameTexture::shoot,sf::IntRect(166, 750, 169, 258));
    WarshipHit.setColor(sf::Color::Blue);
    WarshipBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(0, 486, 165, 261)));
    WarshipBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(0, 255, 165, 261)));
    WarshipBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(839, 748, 165, 261)));
    WarshipBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(165, 486, 165, 261)));
    WarshipBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(673, 748, 166, 260)));
    WarshipBomb.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(0, 747, 166, 261)));
    for(auto& c:WarshipBomb)
        c.setColor(sf::Color::Blue);

    ufo.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(267, 398, 58, 88)));
    ufo.push_back( sf::Sprite(GameTexture::shoot,sf::IntRect(102, 118, 60, 107 )));

   // background= sf::Sprite(GameTexture::background);
    gameover= sf::Sprite(GameTexture::gameover);
}
/*
GameSprite::~GameSprite()
{
    delete Hero;
    for(auto c:HeroBomb)
        delete c;
    HeroBomb.clear();

    delete HeroBullet;
    delete EnemyBullet;

    delete Copter;
    delete CopterHit;
    for(auto c:CopterBomb)
        delete c;
    CopterBomb.clear();

    delete Warplane;
    for(auto c:WarplaneBomb)
        delete c;
    WarplaneBomb.clear();

    for(auto c:Warship)
        delete c;
    Warship.clear();
    delete WarshipHit;
    for(auto c:WarshipBomb)
        delete c;
    WarshipBomb.clear();

    for(auto c:ufo)
        delete c;
    ufo.clear();

    //delete background;
    delete gameover;
}
*/

#include "Hero.h"
#include "Sprites.h"
#include "Bullet.h"
#include "Sound.h"
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

std::list<Bullet> Hero::HeroBullets;

Hero::Hero()
{
    hero_sprite=Sprites::hero;
    health=3;
    score=0;
    move_dis=8;
    x=165;
    y=530;
    level=0;
    hero_sprite.setPosition(x,y);
}

void Hero::DecreaseHealth()
{
    health--;
}

void Hero::turn(sf::RenderWindow& window)
{
    BulletMove();
    BulletClear();
    ResetText();
    hit();
    show(window);
}

int Hero::GetHealth()
{
    return health;
}

int Hero::GetScore()
{
    return score;
}

void Hero::MoveDown()
{
    y=y+move_dis;
    y=std::min(530,y);
    hero_sprite.setPosition(x,y);
}

void Hero::MoveRight()
{
    x=x+move_dis;
    x=std::min(x,340);
    hero_sprite.setPosition(x,y);
}

void Hero::ResetText()
{
    char s[100];
    text.setFont(Font::font);
    text.setColor(sf::Color::Black);
    text.setPosition(0,0);
    sprintf(s,"Health:%d",health);
    text.setString(s);
    text.setScale(0.7,0.7);
}
void Hero::MoveLeft()
{
    x=x-move_dis;
    x=std::max(0,x);
    hero_sprite.setPosition(x,y);
}

void Hero::MoveUp()
{
    y=y-move_dis;
    y=std::max(y,0);
    hero_sprite.setPosition(x,y);
}

void Hero::show(sf::RenderWindow& window)
{
    window.draw(hero_sprite);
    window.draw(text);
    for (std::list<Bullet>::iterator it=HeroBullets.begin();it!=HeroBullets.end();it++)
    {
            window.draw(it->GetSprite());
    }
}

void Hero::fire()
{
    HeroBullets.push_back(Bullet(x+27,y,0,-10));
    Sound::bullet_music.play();
}

void Hero::IncreaseScore(int get_score)
{
    score=score+get_score;
}

void Hero::BulletClear()
{
    for (std::list<Bullet>::iterator it=HeroBullets.begin();it!=HeroBullets.end();it++)
    {
            if (it->IsOut())
            {
                    std::list<Bullet>::iterator tmpit=it++;
                    HeroBullets.erase(tmpit);
            }
    }
}

void Hero::BulletMove()
{
    for (std::list<Bullet>::iterator it=HeroBullets.begin();it!=HeroBullets.end();it++)
    {
            it->move();
    }
}

void Hero::hit()
{
    for (std::list<Bullet>::iterator it=Enemys::EnemyBullets.begin();it!=Enemys::EnemyBullets.end();it++)
    {
            if (hero_sprite.getGlobalBounds().intersects(it->GetSprite().getGlobalBounds()))
            {
                    std::list<Bullet>::iterator tmpit=it++;
                    Enemys::EnemyBullets.erase(tmpit);
                    DecreaseHealth();
            }
    }
}

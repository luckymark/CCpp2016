#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Enemys.h"

std::list<EnemyPlane> Enemys::EnemyPlanes;
std::list<Bullet> Enemys::EnemyBullets;

Enemys::Enemys()
{
    BasicCreatFrequence=70;
    CreatCounter=0;
    score=0;
}

void Enemys::turn(sf::RenderWindow& window)
{
    LevelControl();
    CreatCounterProgress();
    EnemyPlanesMove();
    EnemyPlanesFire();
    EnemyPlanesClear();
    EnemyPlanesHit();
    EnemyPlanesResetSprite();
    BulletsMove();
    BulletsClear();
    ResetText();
    show(window);
}

void Enemys::CreatCounterProgress()
{
    CreatCounter=(CreatCounter+1)%CreatFrequency;
    if (CreatCounter==0) CreatNewEnemy(rand()%100);
}

void Enemys::CreatNewEnemy(int random_number)
{
    if (random_number>=0 && random_number<60) EnemyPlanes.push_back(EnemyPlane(1));
    if (random_number>=60 && random_number<90) EnemyPlanes.push_back(EnemyPlane(2));
    if (random_number>=90 && random_number<100) {
            Sound::big_ship_music.play();
            EnemyPlanes.push_back(EnemyPlane(3));
    }
}

void Enemys::EnemyPlanesMove()
{
    for (std::list<EnemyPlane>::iterator it=EnemyPlanes.begin();it!=EnemyPlanes.end();it++){
            it->move();
    }
}

void Enemys::EnemyPlanesFire()
{
    for (std::list<EnemyPlane>::iterator it=EnemyPlanes.begin();it!=EnemyPlanes.end();it++)
        {
            if (it->fire())
            {
                    if (it->GetFlag()==1)
                    {
                            EnemyBullets.push_back(Bullet(it->GetSprite().getPosition().x+it->GetSprite().getGlobalBounds().width/2-3,it->GetSprite().getPosition().y+it->GetSprite().getGlobalBounds().height,0,7));
                            Sound::bullet_music.play();
                    }
                    if (it->GetFlag()==2)
                    {
                            EnemyBullets.push_back(Bullet(it->GetSprite().getPosition().x+it->GetSprite().getGlobalBounds().width/2+2,it->GetSprite().getPosition().y+it->GetSprite().getGlobalBounds().height,0,7));
                            EnemyBullets.push_back(Bullet(it->GetSprite().getPosition().x+it->GetSprite().getGlobalBounds().width/2-8,it->GetSprite().getPosition().y+it->GetSprite().getGlobalBounds().height,0,7));
                            Sound::bullet_music.play();
                    }
                    if (it->GetFlag()==3)

                    {
                            EnemyBullets.push_back(Bullet(it->GetSprite().getPosition().x+it->GetSprite().getGlobalBounds().width/2+25,it->GetSprite().getPosition().y+it->GetSprite().getGlobalBounds().height,0,7));
                            EnemyBullets.push_back(Bullet(it->GetSprite().getPosition().x+it->GetSprite().getGlobalBounds().width/2-35,it->GetSprite().getPosition().y+it->GetSprite().getGlobalBounds().height,0,7));
                            EnemyBullets.push_back(Bullet(it->GetSprite().getPosition().x+it->GetSprite().getGlobalBounds().width/2-5,it->GetSprite().getPosition().y+it->GetSprite().getGlobalBounds().height,0,7));
                            Sound::bullet_music.play();
                    }
            }
    }
}

void Enemys::EnemyPlanesClear()
{
    for (std::list<EnemyPlane>::iterator it=EnemyPlanes.begin();it!=EnemyPlanes.end();it++)
        {
            if (it->IsOut() || it->IsDestoryed())
            {
                    std::list<EnemyPlane>::iterator tmpit=it++;
                    EnemyPlanes.erase(tmpit);
            }
    }
}

void Enemys::EnemyPlanesHit()
{
    for (std::list<EnemyPlane>::iterator it1=EnemyPlanes.begin();it1!=EnemyPlanes.end();it1++)
        {
            for (std::list<Bullet>::iterator it2=Hero::HeroBullets.begin();it2!=Hero::HeroBullets.end();it2++)
            {
                    if (it1->GetSprite().getGlobalBounds().intersects(it2->GetSprite().getGlobalBounds()))
                    {
                            it1->DecreaseHealth();
                            if (it1->GetHealth()==0)
                            {
                                    if (it1->GetFlag()==1) Sound::enemy1_down_music.play();
                                    if (it1->GetFlag()==2) Sound::enemy2_down_music.play();
                                    if (it1->GetFlag()==3) Sound::enemy3_down_music.play();
                            }
                            if (it1->GetHealth()==0) score=score+it1->GetFlag();
                            std::list<Bullet>::iterator tmpit=it2++;
                            Hero::HeroBullets.erase(tmpit);
                    }
            }
    }
}

void Enemys::EnemyPlanesResetSprite()
{
    for (std::list<EnemyPlane>::iterator it=EnemyPlanes.begin();it!=EnemyPlanes.end();it++){
            it->ResetSprite();
    }
}

void Enemys::BulletsMove()
{
    for (std::list<Bullet>::iterator it=EnemyBullets.begin();it!=EnemyBullets.end();it++){
            it->move();
    }
}

void Enemys::BulletsClear()
{
    for (std::list<Bullet>::iterator it=EnemyBullets.begin();it!=EnemyBullets.end();it++)
    {
            if (it->IsOut())
            {
                    std::list<Bullet>::iterator tmpit=it++;
                    EnemyBullets.erase(tmpit);
            }
    }
}

void Enemys::LevelControl()
{
    CreatFrequency=BasicCreatFrequence-score/10;
}

void Enemys::ResetText()
{
    char s[100];
    text.setFont(Font::font);
    text.setColor(sf::Color::Black);
    text.setPosition(175,0);
    sprintf(s,"Score:%d Level:%d",score,score/10+1);
    text.setString(s);
    text.setScale(0.7,0.7);
}

void Enemys::show(sf::RenderWindow& window)
{
    for (std::list<EnemyPlane>::iterator it=EnemyPlanes.begin();it!=EnemyPlanes.end();it++)
    {
            window.draw(it->GetSprite());
    }
    for (std::list<Bullet>::iterator it=EnemyBullets.begin();it!=EnemyBullets.end();it++)
    {
            window.draw(it->GetSprite());
    }
    window.draw(text);
}

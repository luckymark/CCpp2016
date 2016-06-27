#include "Game.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include "GameWindow.h"
#include "GameMusic.h"
//#include "GameTexture.h"
#include "GameSprite.h"
#include "BackGround.h"
#include "Hero.h"
#include "Copter.h"
#include "Warplane.h"
#include "Warship.h"
#include "ShootUfo.h"
#include "BombUfo.h"
std::list<Plane*>Game::bombingPlane;
std::list<Plane*>Game::existEnemyPlane;
std::list<Plane*>Game::heroBullet;
std::list<Plane*>Game::enemyBullet;
std::list<Plane*>Game::existUfo;
std::vector<Plane*>Game::originEnemyPlane;
std::vector<Plane*>Game::originUfo;
Game* Game::_instance=0;
int Game::sumBomb    =0;
bool Game::isPlaying  =true;
bool Game::isExitGame =false;
enum EnemyFlighterNum
{
    _WarPlane,
    _Copter,
    _WarShip
};
void Game::initializeGame() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    loadBGM();
    loadShader();
    loadWindow();
    loadTexture();
    loadSprite();
    loadLightShader();
    loadBackGround();
    loadHero();
    loadEnemyFlighter();
    loadUfo();
    loadTime();
    loadText();
}
void Game::GameStart() {
    while(window->isOpen() && !isExitGame)
    {
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                exitGame();
        }
        if(!isPlaying)
        {
            GameOver();
            continue;
        }
        updateSumTime();
        getKeyBoard(tick);
        creatEnemy();
        creatUfo();
        checkCollison();
        checkInside();
        refresh(tick);
        heroFlash();
        if(sumPlayFlyingSound > detalPlayFlyingSoundTime)
        {
            //printf("playFlyingMusic\n");
            doPlayFlyingSound();
            sumPlayFlyingSound = 0.f;
        }
        if(sumDraw > detalDraw)
        {
            draw();
            window->display();
            sumDraw = 0.f;
        }
    }
}
void Game::updateSumTime()
{
    tick = gameClock->restart().asSeconds();
    sumPlayFlyingSound +=tick;
    sumHeroFire        +=tick;
    sumFlash           +=tick;
    sumMakeEnemy       +=tick;
    sumDraw            +=tick;
    sumMakeUfo         +=tick;
    sumBombingTime     +=tick;
}
void Game::loadText()
{
    text=GameText::instance();
    text->loadFont();
    //text->showGameInfo(0,3);
}
void Game::loadTime()
{
    gameClock    = new sf::Clock;
    detalPlayFlyingSoundTime = 2.5f;
    detalHeroFire            = 0.2f;
    detalFlash               = 1.5f;
    detalDraw                = 0.01f;
    bombTime                 = 0.8;
    getRandomCreatEnemyTime();
    getRandomCreatUfoTime();

    sumPlayFlyingSound       = 0.f;
    sumHeroFire              = 0.f;
    sumFlash                 = 0.f;
    sumMakeEnemy             = 0.f;
    sumDraw                  = 0.f;
    sumMakeUfo               = 0.f;
    sumBombingTime           = 0.f;
}
void Game::getRandomCreatEnemyTime()
{
    detalMakeEnemy = (100+rand()%201)/100.f;
}
void Game::getRandomCreatUfoTime()
{
    detalMakeUfo = (500+rand() % 501)/100.f;
}
void Game::GameExit() {
    window->close();
}
void Game::GameOver()
{
    //printf("GameOver\n");
    tick     = gameClock->restart().asSeconds();
    sumDraw +=tick;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        exitGame();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        if(hero->getLife() <= 0)
            restartGame();
        isPlaying = true;
    }
    background->refresh(tick);
    if(sumDraw > detalDraw)
    {
        window->clear();
        background->draw();
        text->showGameOverInfo(score);
        window->display();
        sumDraw = 0.f;
    }
}
void Game::restartGame()
{
    score   = 0;
    sumBomb = 0;
    heroBullet.clear();
    enemyBullet.clear();
    bombingPlane.clear();
    existEnemyPlane.clear();
    existUfo.clear();
    hero -> initializePlane(sf::Vector2f(GameWindow::iniWidth,GameWindow::iniHeight));
}
void Game::exitGame()
{
    printf("Exit!\n");
    window->close();
    isExitGame = true;
}
void Game::heroFlash()
{
    if(hero->checkBeHited() && sumFlash > detalFlash)
        hero->recoverNormal();
}
void Game::getKeyBoard(float detalTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        hero->moveLeft(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        hero->moveRight(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        hero->moveUp(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        hero->moveDown(detalTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && sumHeroFire > detalHeroFire)
    {
        hero->fire();
        music->playShoot();
        sumHeroFire = 0.f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        useBomb();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        isPlaying = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        isExitGame= true;
}
void Game::getBomb()
{
    if(sumBomb<3)
        ++sumBomb;
}
void Game::useBomb()
{
    if (!isBombing && sumBomb>0)
    {
        sumBombingTime   = 0;
        isBombing        = true;
        --sumBomb;
        music->playUseBomb();
    }
}
void Game::clearScreen()
{
    for(auto c:existEnemyPlane)
        kill_a_plane(c);
    enemyBullet.clear();
    existEnemyPlane.clear();
}
void Game::doPlayFlyingSound()
{
    for(auto& c:existEnemyPlane)
        c->playFlyingSound();
}
void Game::refresh(float detalTime)
{
    background->refresh(detalTime);
    hero->refresh(detalTime);
    if (isBombing)
	{
	    clearScreen();
		if (sumBombingTime < bombTime)
		{
			drawLight(sf::Vector2f(GameWindow::windowWidth / 2, GameWindow::windowHeight / 2), sf::Color(255, 128, 128), 0.2 / sumBombingTime);
		}
		else if (sumBombingTime < bombTime*1.5)
		{
			drawLight(sf::Vector2f(GameWindow::windowWidth / 2, GameWindow::windowHeight / 2), sf::Color(255, 128, 128), 0.2 / (bombTime * 3 - sumBombingTime * 2));
		}
		else
		{
			isBombing = false;
		}
	}
    for(auto& itb:enemyBullet)
        itb->refresh(detalTime);
    for(auto& itp:existEnemyPlane)
        itp->refresh(detalTime);
    for(auto& itb:heroBullet)
        itb->refresh(detalTime);
    for(auto& itu:existUfo)
        itu->refresh(detalTime);

}
void Game::draw()
{
    window->clear();
    background->draw();
    hero -> draw();
    text->showGameInfo(score,hero->getLife());
    for(auto& itp:existEnemyPlane)
        itp->draw();
    for(auto& itb:heroBullet)
    {
        drawLight(sf::Vector2f(itb->getX(),itb->getY()),itb->getLightColor(),100);
        itb->draw();
    }
    for(auto& itb:enemyBullet)
    {
        drawLight(sf::Vector2f(itb->getX(),itb->getY()),itb->getLightColor(),100);
        itb->draw();
    }
    for(auto& itu:existUfo)
        itu->draw();
    for(auto itbp=bombingPlane.begin();itbp!=bombingPlane.end();itbp++)
        if(!(*itbp)->isBombing(tick))
            itbp=bombingPlane.erase(itbp);
    for(auto& itbp:bombingPlane)
        itbp->draw();
    sf::Sprite tempBomb(GameSprite::bomb);
    int bombHeight=tempBomb.getTextureRect().height;
    int bombWidth =tempBomb.getTextureRect().width;
    for(int i=0;i<sumBomb;i++)
    {
        tempBomb.setPosition(10+i*(bombWidth+20),GameWindow::windowHeight-bombHeight-5);
        window->draw(tempBomb);
    }
    window->draw(lightSprite,sf::BlendAdd);
    if(sumBombingTime < bombTime && isBombing)  return;
    isBombing = false;
    lightRenderTexture.clear(sf::Color::Transparent);
}
void Game::drawLight(const sf::Vector2f& lightPosition,sf::Color color,float lightAttenuation)
{
    lightShader->setParameter("frag_LightAttenuation", lightAttenuation);
    lightShader->setParameter("frag_LightOrigin", lightPosition);
    lightShader->setParameter("frag_LightColor", color.r, color.g, color.b, color.a);
    lightRenderTexture.draw(lightSprite, lightRenderState);
}
void Game::loadBackGround()
{
    background=BackGround::instance();
    background->load();
}
void Game::loadBGM()
{
    music=GameMusic::instance();
    music->load();
    music->playBGM();
}
void Game::loadEnemyFlighter()
{
    originEnemyPlane.push_back(new Warplane);
    originEnemyPlane.push_back(new Copter);
    originEnemyPlane.push_back(new Warship);
}
void Game::loadUfo()
{
    originUfo.push_back(new ShootUfo);
    originUfo.push_back(new BombUfo);
}
void Game::loadTexture()
{
    GameTexture::load();
}
void Game::loadSprite()
{
    GameSprite::load();
}
void Game::loadLightShader()
{
    lightTexture.create(GameWindow::windowWidth,GameWindow::windowHeight);
    lightShader = shader->getLightShader();
    lightRenderState.shader = lightShader;
    lightRenderState.blendMode = sf::BlendAdd;
    lightRenderTexture.create(GameWindow::windowWidth,GameWindow::windowHeight);
    lightSprite.setTexture(lightRenderTexture.getTexture());
}
void Game::loadHero()
{
    hero = Hero::instance(sf::Vector2f(GameWindow::iniWidth,GameWindow::iniHeight));
}
void Game::loadWindow()
{
    window=GameWindow::instance();
    window->initializeWindow();
}
void Game::kill_a_plane(Plane* plane)
{
    score+=plane->getScore();
}
void Game::loadShader()
{
    shader=Shader::instance();
}
void Game::creatEnemy()
{
    if(sumMakeEnemy > detalMakeEnemy)
    {
        int type=getRandomType();
        sf::Vector2f nowPosition = getRandomPosition(originEnemyPlane[type]);
        existEnemyPlane.push_back(originEnemyPlane[type]->clone()->setPosition(nowPosition));
        sumMakeEnemy = 0.f;
        getRandomCreatEnemyTime();
    }
}
void Game::creatUfo()
{
    if(sumMakeUfo > detalMakeUfo)
    {
        int type=rand() % 2;
        sf::Vector2f nowPosition = getRandomPosition(originUfo[type]);
        existUfo.push_back(originUfo[type]->clone()->setPosition(nowPosition));
        sumMakeUfo = 0.f;
        getRandomCreatUfoTime();
    }
}
int Game::getRandomType()
{
    int u = rand() % 12;
    if(u<7)return 0;
    if(u<11)return 1;
    return 2;
}
sf::Vector2f Game::getRandomPosition(Plane* aEnemy)
{
    int x =rand()% (GameWindow::windowWidth - 100);
    return sf::Vector2f(x,aEnemy->getTop());
}
sf::Vector2f Game::getRandomDirection()
{
    return sf::Vector2f(0.1,1.f);
}
void Game::checkCollison()
{
    checkHeroBulletAndEnemyCollision();
    checkHeroAndUfoCollision();
    checkHeroAlive();
    if(hero->checkBeHited())return ;
    checkEnemyBulletAndHeroCollision();
    checkEnemyAndHeroCollision();
}
void Game::checkHeroBulletAndEnemyCollision()
{
    for(auto ithb=heroBullet.begin();ithb!=heroBullet.end();ithb++)
    {
        bool isHit=false;
        for(auto itep=existEnemyPlane.begin();itep!=existEnemyPlane.end();itep++)
            if((*ithb) -> intersects((*itep)->getCollisionArea()))
            {
                //printf("beHited!\n");
                isHit=true;
                (*itep)->beHited((*ithb)->getHarm());
                music->playBeHited();
                if(!(*itep) -> isAlive())
                {
                    //printf("Add a Plane\n");
                    bombingPlane.push_back((*itep)->clone());
                    (*itep)->playBombSound();
                    kill_a_plane((*itep));
                    itep=existEnemyPlane.erase(itep);
                }
                break;
            }
        if(isHit)
            ithb=heroBullet.erase(ithb);
    }
}
void Game::checkHeroAndUfoCollision()
{
    for(auto ithb=existUfo.begin();ithb!=existUfo.end();ithb++)
    {
        if(hero->intersects((*ithb)->getCollisionArea()))
        {
            (*ithb)->playBombSound();
            (*ithb)->getSkill(hero);
            ithb = existUfo.erase(ithb);
        }
    }
}
void Game::checkEnemyBulletAndHeroCollision()
{
    for(auto ithb=enemyBullet.begin();ithb!=enemyBullet.end();ithb++)
    {
        bool isHit=false;
        if(hero->intersects((*ithb)->getCollisionArea()))
        {
            isHit=true;
            hero->beHited((*ithb)->getHarm());
            sumFlash = 0.f;
            break;
        }
        if(isHit)
        {
            ithb=enemyBullet.erase(ithb);
            return ;
        }
    }
}
void Game::checkEnemyAndHeroCollision()
{
    for(auto ithb=existEnemyPlane.begin();ithb!=existEnemyPlane.end();ithb++)
    {
        if(hero->intersects((*ithb)->getCollisionArea()))
        {
            //printf("beHited!\n");
            hero->beHited((*ithb)->getHarm());
            sumFlash = 0.f;
            //music->playBeHited();

            break;
        }
    }
}
void Game::checkHeroAlive()
{
    if(!hero -> isAlive())
    {
        isPlaying = false;
        bombingPlane.push_back(hero->clone());
        hero->playBombSound();
        return ;
    }
}
Game* Game::instance() {
    if(_instance==0)
        _instance=new Game;
    return _instance;
}
void Game::checkInside()
{
    for(auto it=existEnemyPlane.begin();it!=existEnemyPlane.end();it++)
        if((*it)->getTop() > GameWindow::windowHeight)
            it=existEnemyPlane.erase(it);
    for(auto it=enemyBullet.begin();it!=enemyBullet.end();it++)
        if((*it)->getTop() > GameWindow::windowHeight)
            it=existEnemyPlane.erase(it);
    for(auto it=heroBullet.begin();it!=heroBullet.end();it++)
        if((*it)->getBottom() < 0)
            it=heroBullet.erase(it);
    for(auto it=existUfo.begin();it!=existUfo.end();it++)
        if((*it)->getTop() > GameWindow::windowHeight)
            it=heroBullet.erase(it);
}
Game::Game()
{

}

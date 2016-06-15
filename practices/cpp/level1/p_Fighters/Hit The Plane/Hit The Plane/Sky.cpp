//
//  Sky.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "ResourcePath.hpp"
#include "Sky.hpp"
#include "ViewManagement.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
Sky *Sky::instance=nullptr;
Ghost *border;
Ghost *three;
Ghost *two;
Ghost *one;
Game *game=Game::getInstance();
sf::Text *score;
sf::Text *restart;
sf::Text *quit;
sf::Text *highestScore;
sf::Sprite *chooser;
bool haveGot=0;
Sky *Sky::getInstance(){
    if (!instance) {
        instance=new Sky;
        
        
    }
    return instance;
}

Sky::Sky(){
    this->window=new sf::RenderWindow(sf::VideoMode(500,800),L"Hit The Plane");
    
    //set icon
    sf::Image icon;
    if (icon.loadFromFile(resourcePath()+"icon.JPG")) {
        this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }
    border=new Ghost;
    border->setTexture(ViewManagement::SHIELDBORDER);
    border->setPosition(20, 700);
    
    three=new Ghost;
    three->setPosition(350, 650);
    three->setTexture(ViewManagement::THREE);
    
    two=new Ghost;
    two->setPosition(350, 650);
    two->setTexture(ViewManagement::TWO);
    
    one=new Ghost;
    one->setPosition(350, 650);
    one->setTexture(ViewManagement::ONE);
    
    score=new sf::Text;
    score->setPosition(20, 20);
    score->setColor(sf::Color::Red);
    
    sf::Font *font=new sf::Font;
    font->loadFromFile(resourcePath()+"sansation.ttf");
    
    score->setFont(*font);
    score->setCharacterSize(100);
    
    restart=new sf::Text;
    restart->setPosition(170, 400);
    restart->setColor(sf::Color::Black);
    restart->setFont(*font);
    restart->setCharacterSize(40);
    restart->setString("Restart");
    
    quit=new sf::Text;
    quit->setPosition(170, 450);
    quit->setColor(sf::Color::Black);
    quit->setFont(*font);
    quit->setCharacterSize(40);
    quit->setString("Quit");
    
    chooser=new sf::Sprite;
    chooser->setTexture(ViewManagement::CHOOSER);
    chooser->setPosition(100, 400);
    
    highestScore=new sf::Text;
    highestScore->setPosition(150,100);
    highestScore->setFont(*font);
    highestScore->setColor(sf::Color::Cyan);
    highestScore->setCharacterSize(30);
    
    this->backgroud=new sf::Sprite(ViewManagement::SKY);
    
}


void Sky::addMyBullet(Bullet *bullet){
    this->myBullets.insert(bullet);
}

void Sky::addEnemyBullet(Bullet *bullet){
    this->enemyBullets.insert(bullet);
}

void Sky::addPlayer(Player *ghost){
    this->player=ghost;
}

void Sky::addBars(Ghost *bar){
    this->bars.insert(bar);
}

void Sky::refresh(){
    this->window->draw(*this->backgroud);
    
    this->drawStatic();
                      
    this->clear();
    
    this->creatEnemies();
    
    this->loopTheEnemyBullet();
    
    this->loopTheTools();
    
    
    for (auto &enemy:this->enemies) {
        enemy->goDown();
        enemy->shoot();
        this->window->draw(*enemy);
    }
    
    for (auto &bullet:this->myBullets) {
        bullet->goUp();
        this->window->draw(*bullet);
    }
    
    for (auto &bar:this->bars) {
        bar->refresh();
        this->window->draw(*bar);
    }
    
    for (auto &deadEnemy:this->deadEnemies) {
         this->window->draw(*deadEnemy);
        deadEnemy->deadTime++;
        if (deadEnemy->deadTime==100) {
            delete deadEnemy;
            this->deadEnemies.erase(deadEnemy);
            break;
        }
    }
    
    if (this->player->isDead()) {
        this->playerIsDead();
    }
    
    (this->window)->draw(*player);

    this->window->display();
}

void Sky::creatEnemies(){
    count++;
    if (count>=spacing) {
        Enemy *enemy=new Enemy(0);
        this->enemies.insert(enemy);
        enemyCount++;
        count=0;
    }
    if (enemyCount%10==0) {
        Enemy *boss=new Enemy(enemyCount/10);
        this->bosses.insert(boss);
        this->enemies.insert(boss);
        if (enemyCount/10==3) {
            enemyCount=1;
            Tool *plusone=new Tool(1);
            this->tools.insert(plusone);
        }
        enemyCount++;
    }
    
}

void Sky::clear(){
        
    for (auto theEnemy=this->enemies.begin();theEnemy!=enemies.end();++theEnemy){
        
        for (auto theBullet=this->myBullets.begin();theBullet!=this->myBullets.end();++theBullet) {
            if ((*theBullet)->isOutOfWindow()) {
                delete *theBullet;
                (this->myBullets).erase(theBullet);
                break;
            }
            
            if ((*theEnemy)->intersects(*theBullet)) {
                delete *theBullet;
                game->scored();
                (this->myBullets).erase(theBullet);
                (*theEnemy)->hit();
                break;
            }
            
        }
        
        if ((*theEnemy)->intersects(this->player)) {
            if (!player->ifShieldOpened()) {
                (*theEnemy)->dieNow();
                player->isHit();
            }else{
                (*theEnemy)->hit();
            }
            
        }
        
        if ((*theEnemy)->needClear()) {
            delete *theEnemy;
            this->enemies.erase(theEnemy);
            break;
        }
        if ((*theEnemy)->isDead()) {
            (*theEnemy)->explode();
            this->enemies.erase(theEnemy);
            this->deadEnemies.insert(*theEnemy);
            break;
        }
        
    }
    
}

void Sky::playerIsDead(){
    this->backgroud->setTexture(ViewManagement::GAMEOVER);
    this->window->draw(*chooser);
    this->window->draw(*restart);
    this->window->draw(*quit);
    
    
    if (!haveGot) {
        int theScore;
        char bestScore[20];
        sprintf(bestScore, "BEST SCORE:\n    %d",game->getBestScore());
        highestScore->setString(bestScore);
        haveGot=true;
    }
    
    this->window->draw(*highestScore);
}

void Sky::loopTheEnemyBullet(){
    for (auto &enemyBullet:this->enemyBullets) {
        enemyBullet->goDown();
        this->window->draw(*enemyBullet);
        
        if (enemyBullet->isOutOfWindow()) {
            delete enemyBullet;
            (this->enemyBullets).erase(enemyBullet);
            break;
        }
        if (enemyBullet->intersects(this->player)) {
            if (!(this->player)->ifShieldOpened()) {
                player->isHit();
            }
            delete enemyBullet;
            (this->enemyBullets).erase(enemyBullet);
            break;
        }
    }
}

void Sky::drawStatic(){
    if (player->getState()==1) {
        this->window->draw(*one);
    }
    if (player->getState()==2) {
        this->window->draw(*two);
    }
    if (player->getState()==3) {
        this->window->draw(*three);
    }
    this->window->draw(*border);
    
    char currentScore[10];
    sprintf(currentScore,"%d",game->getScore());
    score->setString(currentScore);
    this->window->draw(*score);
    
}

void Sky::loopTheTools(){
    for (auto &theTool:this->tools) {
        this->window->draw(*theTool);
        theTool->refresh();
        if (theTool->intersects(this->player)) {
            delete theTool;
            this->tools.erase(theTool);
            this->player->plusone();
            break;
        }
        if (theTool->needClear()) {
            delete theTool;
            this->tools.erase(theTool);
            break;
        }
    }
}

void Sky::moveChosser(int position){
    if (position==0) {
        chooser->setPosition(100, 400);
    }else if (position==1){
        chooser->setPosition(100, 450);
    }
}


void Sky::clearAll(){
    for (auto theEnemy=this->enemies.begin();theEnemy!=enemies.end();++theEnemy){
        delete *theEnemy;
        this->enemies.erase(theEnemy);
        break;
    }
    for (auto theBullet=this->myBullets.begin();theBullet!=this->myBullets.end();++theBullet) {
        delete *theBullet;
        this->myBullets.erase(theBullet);
        break;
    }
    for (auto &enemyBullet:this->enemyBullets) {
        delete enemyBullet;
        (this->enemyBullets).erase(enemyBullet);
        break;
    }
    for (auto &theTool:this->tools) {
        delete theTool;
        (this->tools).erase(theTool);
        break;
    }

}

void Sky::restartGame(){
    haveGot=false;
    this->backgroud->setTexture(ViewManagement::SKY);
    game->restartGame();
}


#include "System.h"

#include <time.h>
#include <windows.h>
#include <Plane_enemy.h>

System::System()
{
    window.create(sf::VideoMode(480, 800), "hit the plane");
    font.loadFromFile("resource/font/STHeiti Light.ttc");
    textScore.setCharacterSize(24);
    textScore.setColor(sf::Color::Red);
    textScore.setPosition(350,700);
    textScore.setFont(font);
    textLife.setCharacterSize(24);
    textLife.setColor(sf::Color::Red);
    textLife.setPosition(370,720);
    textLife.setFont(font);
    sound.load();
    sound.BACK_GROUND.play();
    //ctor
}

System::~System()
{
    //dtor
}

void System::add(Plane plane){
    this->plane = plane;
}


void System::add(Bullet bullet){
    //this->bullet = bullet;
    bulletList.push_back(bullet);
}

void System::add(Plane_enemy enemy){
    //this->bullet = bullet;
    enemyList.push_back(enemy);
}

void System::add(EnemyBullet enemyBullet){
    //this->bullet = bullet;
    enemyBulletList.push_back(enemyBullet);
}

void System::manage(){
    //重绘计时
    sf::Clock clock;
    //出现敌机计时
    sf::Clock clock2;
    //敌机打子弹计时
    sf::Clock clock3;
    this->loadBackground();
    this->loadGameOver();
    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time refresh = sf::seconds(0.01f);
        sf::Time enemyMake = clock2.getElapsedTime();
        sf::Time enemyMakerefresh = sf::seconds(1);
        sf::Time bulletMake = clock3.getElapsedTime();
        sf::Time bulletMakerefresh = sf::seconds(2);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){

                plane.movePlane(event);
                if(event.key.code == sf::Keyboard::Space&& plane.getLife()>0){
                    sf::Vector2f planePosition = plane.sprite.getPosition();
                    planePosition.x = planePosition.x + 25;
                    planePosition.y = planePosition.y - 15;
                    static Bullet bullet(planePosition.x,planePosition.y);
                    bullet.sprite.setPosition(planePosition.x,planePosition.y);
                    this->add(bullet);
                    sound.SHOOT.play();
                }
            }

        }
        //时间到了就出现敌机
        if(enemyMake>enemyMakerefresh&&plane.getLife()>0){
            static Plane_enemy enemy;
            enemy.sprite.setPosition((rand() % (350-0))+ 0,20);
            this->add(enemy);
            clock2.restart();
            window.draw(enemy.sprite);
            window.display();
        }

        //时间到了敌机就发射子弹
        if(bulletMake>bulletMakerefresh&&plane.getLife()>0){
            static EnemyBullet enemyBullet;
            for(int i=0;i<enemyList.size();i++){
                enemyBullet.sprite.setPosition(enemyList[i].sprite.getPosition().x+10,enemyList[i].sprite.getPosition().y+80);
                this->add(enemyBullet);
            }
            clock3.restart();
        }


        //重新绘制每一帧图并显示
        if(elapsed>refresh){
        //清屏
        window.clear();




        if(plane.getLife()>0){
            //所有子弹和敌机移动
            this->intersects();
            this->moveAllBullet();
            this->moveALLPlane_Enemy();

            //显示子弹和敌机

            this->showBackground();
            this->showBullet();
            this->showPlane();
            this->showEnemy();
            this->showBoomPlane();

        }else{
            //显示GameOver
            showGameOver();
        }
        //显示得分
        showScore();
        showLife();
        //显示
        window.display();
        clock.restart();
        }
    }
}



void System::showPlane(){
    window.draw(plane.sprite);
}

void System::showBullet(){
    window.draw(bullet.sprite);
    for(int i=0;i<bulletList.size();i++){
        window.draw(bulletList[i].sprite);
    }
    for(int i=0;i<enemyBulletList.size();i++){
        window.draw(enemyBulletList[i].sprite);
    }
}

void System::showEnemy(){
    for(int i=0;i<enemyList.size();i++){
        window.draw(enemyList[i].sprite);
    }
}

void System::showBoomPlane(){
    for(int i=0;i<boomPlaneList.size();i++){
        //cout<<"boom"<<boomPlaneList[i].text.getPosition().y<<endl;
        window.draw(boomPlaneList[i].text);
        boomPlaneList[i].stateChange();
        string s = boomPlaneList[i].text.getString();
        if(boomPlaneList[i].state == 10){
            boomPlaneList[i].text.setString("BOOM!");
        }
        if(boomPlaneList[i].state == 20){
            boomPlaneList[i].text.setString("BOOM!!");
        }
        if(boomPlaneList[i].state == 30){
            boomPlaneList[i].text.setString("BOOM!!!");
        }
        if(boomPlaneList[i].state == 40){
            boomPlaneList[i].text.setString("BOOM!!!!");
        }
        if(boomPlaneList[i].state == 50){
            boomPlaneList[i].text.setString("BOOM!!!!!");
        }
        if(boomPlaneList[i].state>60){
            boomPlaneList.erase(boomPlaneList.begin()+i);
        }
    }
}

void System::showScore(){

    string s = "Score:    ";
    stringstream ss;
    ss<<score;
    scoreS = ss.str();
    s = s +scoreS;
    textScore.setString(s);
    //textScore.setString((string)score);
    window.draw(textScore);
}

void System::showLife(){

    string s = "Life:    ";
    stringstream ss;
    ss<<plane.getLife();
    lifeS = ss.str();
    s = s +lifeS;
    textLife.setString(s);
    //textScore.setString((string)score);
    window.draw(textLife);
}


void System::moveAllBullet(){
    for(int i=0;i<bulletList.size();i++){
        if(bulletList[i].moveBullet()){
            bulletList.erase(bulletList.begin()+i);
        }
    }
    for(int i=0;i<enemyBulletList.size();i++){
        if(enemyBulletList[i].moveBullet()){
            enemyBulletList.erase(enemyBulletList.begin()+i);
        }
    }
}

void System::moveALLPlane_Enemy(){
    for(int i=0;i<enemyList.size();i++){
        if(enemyList[i].moveEnemyPlane()){
            enemyList.erase(enemyList.begin()+i);
        }
    }
}

//碰撞检测和处理
void System::intersects(){
    //检测自己的子弹是否打到敌机
    for(int i=0;i<bulletList.size();i++){
        for(int j=0;j<enemyList.size();j++){
            if(bulletList[i].sprite.intersects(enemyList[j].sprite)){
                static BoomPlane boomPlane;
                //cout<<"boom"<<enemyList[j].sprite.getPosition().x<<","<<enemyList[j].sprite.getPosition().y<<endl;
                boomPlane.text.setString("BOOM");
                boomPlane.text.setPosition(enemyList[j].sprite.getPosition().x+25,enemyList[j].sprite.getPosition().y+50);
                boomPlaneList.push_back(boomPlane);
                bulletList.erase(bulletList.begin()+i);
                enemyList.erase(enemyList.begin()+j);
                score ++;
                sound.ENEMY_DOWN.play();

            }
        }
    }
    //检测敌机撞自己
    for(int i=0;i<enemyList.size();i++){
        if(enemyList[i].sprite.intersects(plane.sprite)){
            enemyList.erase(enemyList.begin()+i);
            plane.hited();
            break;
        }
    }
    //检测敌机子弹是否打到自己
    for(int i=0;i<enemyBulletList.size();i++){
        if(enemyBulletList[i].sprite.intersects(plane.sprite)){
            enemyBulletList.erase(enemyBulletList.begin()+i);
            plane.hited();
            break;
        }
    }
}

//载入背景
void System::loadBackground(){

    backgroundt.loadFromFile("resource/background.png");
    backgrounds.setTexture(backgroundt);
    backgrounds.setPosition(sf::Vector2f(0,0));
}

//画背景
void System::showBackground(){
     window.draw(backgrounds);
}

//载入GameOver背景
void System::loadGameOver(){

    gameovert.loadFromFile("resource/gameover.png");
    gameovers.setTexture(gameovert);
    gameovers.setPosition(sf::Vector2f(0,0));
}

void System::showGameOver(){
    window.draw(gameovers);
}



//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "MovePlane.hpp"
#include "bullet.hpp"
#include "EnemyPlane.hpp"
#include "Touch.hpp"
#include "health.hpp"
#include "Text.hpp"
#include "F16.hpp"
#include "F35.hpp"
#include "addPlane.hpp"
double levelTime=20;
int i,j,p;
int step=0;
int f22Limit,f35Limit,f16Limit,f22Time,f35Time,f16Time,now=1;
sf::Texture startTexture;
sf::Texture overTexture;
sf::Sprite startSprite;
sf::Sprite overSprite;
sf::Clock Time;
sf::Text Level;
sf::Text level;
int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "SFML window");
    window.setFramerateLimit(200);//设置帧数
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    startTexture.loadFromFile(resourcePath()+"雷电.jpg");
    startSprite.setTexture(startTexture); startSprite.setPosition(0,0);
    startSprite.setScale(4.8,4.9);
    
    overSprite.setTexture(startTexture); overSprite.setPosition(0,0);
    overSprite.setScale(4.8, 4.9);
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "战斗机.png")) {
        return EXIT_FAILURE;
    }
    F35BoomTexture.loadFromFile(resourcePath()+"F35爆炸原件.png");
    F16Texture.loadFromFile(resourcePath()+"F16.png");
    F35Texture.loadFromFile(resourcePath()+"F35.png");
    enemyTexture.loadFromFile(resourcePath()+"敌机.png");
    bulletTexture.loadFromFile(resourcePath()+"敌方子弹.png");
    sf::Sprite sprite(texture);
    health health;//创建我方血量
    sprite.setPosition(posy,posx);//列  行
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "华文仿宋.ttf")) {
        return EXIT_FAILURE;
    }
    Level.setFont(font); level.setFont(font);
    Level.setPosition(0,50); Level.setString(L"当前关数:"); Level.setCharacterSize(20);
    level.setPosition(90,50); level.setCharacterSize(20);
    Text text(font);//创建一个文本
    // Load a music to play
    sf::Music bigMusic;
    bigMusic.openFromFile(resourcePath()+"大招爆炸.wav");
    bigMusic.setPitch(0.5);
    bigMusic.setVolume(1000.0);
    
    sf::Music music;
    music.setLoop(true);
    if (!music.openFromFile(resourcePath() + "巨♀~9地区.ogg")) {
        return EXIT_FAILURE;
    }
    sf::Music boomMusic;
    boomMusic.setLoop(false);
    boomMusic.openFromFile(resourcePath()+"F35爆炸.wav");
    boomMusic.setPitch(1.0);
    boomMusic.setVolume(150.0);
    
    // Play the music
    // Start the game loop
    MovePlane moveplane;
    vector <EnemyPlane> f22;
    f22Limit=400;
    Bullet myFire(5,30,font);
    vector <F16> f16;
    vector <F35> f35;
    while (window.isOpen())
    {
    sf::Event event;
    
        
        
    if (step==0){
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                text.k1=1;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
                text.k1=0;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                text.k2=-1;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
                text.k2=0;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                if (text.p==1) window.close(); else
                {
                    step=1;
                    Time.restart();
                    now=1; getLimit(now,f22Limit,f16Limit,f35Limit);
                    music.play();
                }
            }
        }
        text.move();
        window.clear();
        window.draw(startSprite);
        window.draw(text.sprite);
        window.draw(text.start[0]);
        window.draw(text.start[1]);
        window.display();
        }//初始界面
        
        
        
        
    if (step==1){
        if (health.deadTime!=0)
        {
            health.boomTime--;
            myFire.bigFireNum=5;
            if (health.boomTime>0)
            {
                health.boomSprite.setScale((health.boomScale-health.boomTime)/health.boomScale/health.ki, (health.boomScale-health.boomTime)/health.boomScale/health.ki);
                health.boomSprite.setPosition(jy-30,jx);
            }
        } else health.boomTime=10;
        health.time=max(0,health.time-1);
        health.deadTime=max(0,health.deadTime-1);
        f22Time=min(f22Time+1,10000);
        f35Time=min(f35Time+1,10000);
        f16Time=min(f16Time+1,10000);
      // Process events
        if (Time.getElapsedTime().asSeconds()<levelTime || now==6)
        {
            addF22(f22,f22Time,f22Limit,now);
            addF16(f16,f16Time,f16Limit,now);
            addF35(f35,f35Time,f35Limit,now);
        }
        deleteEnemy(f22);
        deleteF16(f16);
        deleteF35(f35);
        for (i=0;i<f22.size();i++)
        {
            f22[i].moveBullet();
            if (f22[i].exist)
            {
                f22[i].getDirection();
                f22[i].movePlane();
                f22[i].addBullet();
            }
        }
        
        for (i=f16.size()-1;i>=0;i--)
        {
            f16[i].moveBullet();
            if (f16[i].exist)
            {
                f16[i].movePlane();
                f16[i].addBullet(posy,posx);
        
            }
        }
        for (i=0;i<f35.size();i++) if (health.deadTime==0 && f35[i].exsit) f35[i].movePlane(posy,posx);
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                myFire.fire=true;
                
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
                myFire.fire=false;
                
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            {
                direction[0]=true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
            {
                direction[0]=false;
            }
            
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            {
                direction[1]=true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
            {
                direction[1]=false;
            }
            
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            {
                direction[2]=true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
            {
                direction[2]=false;
            }
            
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            {
                direction[3]=true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
            {
                direction[3]=false;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
            {
                if (health.deadTime==0 && myFire.bigFireTime>300 && myFire.bigFireNum>0)
                {
                    myFire.addBigFire(posy,posx);
                }
            }
        }
        
        touchEnemy(f22,myFire);
        touchF16(f16,myFire);
        touchF35(f35,myFire);
        if (myFire.bigFireBoomTime==10) touchBigFire(f16,f22,f35,myFire);
        myFire.updatePoint();
        
        if (myFire.fire && health.deadTime==0) myFire.addBullet(posy,posx);//我方处于开火状态
        myFire.moveBullet();//移动我方子弹
        
        if (health.deadTime==0)
        {
            if (direction[1])  moveplane.left();
            if (direction[0])  moveplane.up();
            if (direction[2])  moveplane.right();
            if (direction[3]) moveplane.down();//移动我方飞机
            sprite.setPosition(posy,posx);//我方飞机位置固定
            if (health.time==0)
            {
                health.touchBullet(posy,posx,f22);
                health.touchF16Fire(posy, posx,f16);
                health.touchPlane(posy,posx,f22);
                health.touchF16Plane(posy,posx,f16);
                health.touchF35Plane(sprite,f35);
            }
        }
        if (health.life==0)
        {
            step=2;
            music.stop();
            myFire.grade.setCharacterSize(50);
            myFire.grade.setPosition(730,303);
        }
        if (health.time%40>20) sprite.setColor(sf::Color(255,255,255,100)); else
        sprite.setColor(sf::Color(255,255,255,255));
        //红色 绿色 蓝色 清晰度 范围0-255
        level.setString(to_string(now));
        health.updateLife(text.lifeNum);
        window.clear();
        window.draw(text.lifeNum);
        window.draw(text.life);
        window.draw(text.bigFireNum);
        window.draw(myFire.bigFireText);
        window.draw(Level);
        window.draw(level);
        window.draw(health.sprite[4-health.bloodStain]);
        if (myFire.bigFireP) window.draw(myFire.bigFireSprite);
        // Draw the sprite
        if (health.deadTime==0) window.draw(sprite); else if (health.boomTime<10 && health.boomTime>0) window.draw(health.boomSprite);
        if (health.boomTime==9) boomMusic.play();
        if (myFire.bigFireBoomTime==19) bigMusic.play();
        for (i=0;i<f35.size();i++)
        {
            if (!f35[i].exsit && f35[i].boomtime>0)
            {
                window.draw(f35[i].boomSprite);
                if (f35[i].boomtime==9) boomMusic.play();
            }
        }
        for (i=0;i<f16.size();i++)
        {
            if (!f16[i].exist && f16[i].boomtime>0)
            {
                window.draw(f16[i].boomSprite);
                if (f16[i].boomtime==9) boomMusic.play();
            }
        }
        for (i=0;i<f22.size();i++)
        {
            if (!f22[i].exist && f22[i].boomtime>0)
            {
                window.draw(f22[i].boomSprite);
                if (f22[i].boomtime==9) boomMusic.play();
            }
        }
        for (i=0;i<f22.size();i++) if (f22[i].exist) window.draw(f22[i].sprite);//画出敌机
        for (i=0;i<f16.size();i++) if (f16[i].exist) window.draw(f16[i].sprite);
        for (i=0;i<f35.size();i++) if (f35[i].exsit) window.draw(f35[i].sprite);
        
        for (i=0;i<myFire.list.size();i++) window.draw(myFire.list[i].sprite);//画出我方子弹
        for (j=0;j<f22.size();j++)
        {
            for (i=0;i<f22[j].list.size();i++) window.draw(f22[j].list[i].sprite);//画出敌机子弹
        }
        
        for (j=0;j<f16.size();j++)
        {
            for (i=0;i<f16[j].list.size();i++) window.draw(f16[j].list[i].sprite);//画出敌机子弹
        }
        // Update the window
        window.draw(text.point);
        window.draw(myFire.grade);
        if (myFire.bigFireBoomTime!=0) window.draw(myFire.bigFireBoomSprite);
        window.display();
        
        if (Time.getElapsedTime().asSeconds()>=levelTime && f16.size()==0 && f35.size()==0 && f22.size()==0 && now<=5)
        {
            now++;
            getLimit(now,f22Limit,f16Limit,f35Limit);
            Time.restart();
        }
        
        }
        
        
        
        
        if (step==2)
        {
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            
                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                    text.k1=1;
                }
                if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
                    text.k1=0;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                    text.k2=-1;
                }
                if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
                    text.k2=0;
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                    if (text.p==1) window.close(); else
                    {
                        music.play();
                        f22.clear();
                        f16.clear();
                        f35.clear();
                        health.clear();
                        moveplane.clear();
                        myFire.clear();
                        step=1;
                        now=1; Time.restart();
                        getLimit(now,f22Limit,f16Limit,f35Limit);
                    }
                }
            }
            text.move();
            window.clear();
            window.draw(overSprite);
            window.draw(text.sprite);
            window.draw(text.gameOver);
            window.draw(text.grade);
            window.draw(text.rePlay);
            window.draw(text.start[1]);
            window.draw(myFire.grade);
            window.display();
        }
        
        
    }
    return EXIT_SUCCESS;
}

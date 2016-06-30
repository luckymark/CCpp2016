#include"Sky.h"
#include"Hero.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Enemy2.h"
#include"Enemy3.h"
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
#include"math.h"
#include"Win.h"
#include"Rect.h"
int main(){
    Win* w=new Win;
    while(w->win->isOpen()){
        sf::Texture menuPicture;
        menuPicture.loadFromFile("F:\\reso\\menu.jpg");
        sf::Sprite smenuPicture;
        smenuPicture.setTexture(menuPicture);
        w->win->draw(smenuPicture);
        w->win->display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            w->win->close();
        }
    }
    Sky* sky=new Sky;

    while(sky->window->isOpen()){
        int score=0;
        Sky::game_time++;
        Sky::game_time2++;
        Bullet::bullet_life++;

        if(Bullet::bullet_life=60){
            Bullet::bullet_life=0;
        }

        Hero he;
        Enemy en;
        Enemy2 en2;
        Enemy3 en3;
        Bullet bu;
        he.build();
        if(Sky::game_time%1200==0||Sky::game_time==0){
                en.move();
                en2.move();
               Sky::game_time=0;
        }
        if(Sky::game_time2%1200==0||Sky::game_time2==0){
            en3.move();
            Sky::game_time2=0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        bu.move();

    }
    int rh1=Rect::rect_judge(hx,hy,en.ex,en.ey);
    int rh2=Rect::rect_judge(hx,hy,en2.ex,en2.ey);
    int rh3=Rect::rect_judge(hx,hy,en3.ex,en3.ey);
    int rb1=Rect::rect_judge(bu.a,bu.b,en.ex,en.ey);
    int rb2=Rect::rect_judge(bu.a,bu.b,en2.ex,en2.ey);
    int rb2=Rect::rect_judge(bu.a,bu.b,en3.ex,en3.ey);
    if(rb1>10&&rb2>10&&rb>10){
        bu.draw_myself();
    }
    else{
        score++;
    }
    if(rh1>10&&rb1>10){
         en.draw_myself();
    }
       if(rh2>10&&rb2>10){
         en2.draw_myself();
    }
        if(rh3>10&&rb3>10){
         en3.draw_myself();
    }
       if(rh1>10&&rh2>10&&rh3>10){
          he.move();
    }
    else{
        Hero::heartlife-=1;
    }

        sky->refresh();

    }
    return 0;

}


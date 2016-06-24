#ifndef Enemy_hpp
#define Enemy_hpp
#include "SecondaryObject.hpp"
#include <Bullet.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Enemy : public SecondaryObject {
  protected:
    double life = 4.0;
    sf::Clock clock;
    Enemy(int position);

  public:
    int point;
    virtual bool isDead();
    virtual void fire() = 0;
    void hit(Bullet *bullet);
};
#endif /* Enemy_hpp */

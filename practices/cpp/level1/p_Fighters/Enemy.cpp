#include "Enemy.hpp"
#include "Hero.hpp"
bool Enemy::isDead() { return (life <= 1e-6); };
void Enemy::hit(Bullet *bullet) { life -= bullet->damage; }
Enemy::Enemy(int position) {
    setPosition(1800, position);
    deviation.x = 50;
    deviation.y = 50;
    radius = 50;
}
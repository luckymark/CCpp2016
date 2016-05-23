/**
 * Project Untitled
 */


#ifndef _ENEMYBULLET_H
#define _ENEMYBULLET_H

#include "Bullet.h"


class EnemyBullet: public Bullet {
public: 
    
    void move();
    
    EnemyBullet* creat();
};

#endif //_ENEMYBULLET_H
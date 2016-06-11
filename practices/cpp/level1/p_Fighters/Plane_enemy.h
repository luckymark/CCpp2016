#ifndef PLANE_ENEMY_H
#define PLANE_ENEMY_H

#include <Plane.h>


class Plane_enemy : public Plane
{
    public:
        Plane_enemy();
        virtual ~Plane_enemy();
        int moveEnemyPlane();
    protected:
    private:
};

#endif // PLANE_ENEMY_H

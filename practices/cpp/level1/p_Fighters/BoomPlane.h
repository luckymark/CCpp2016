#ifndef BOOMPLANE_H
#define BOOMPLANE_H
#include<Sprite.h>

class BoomPlane
{
    public:
        BoomPlane();
        virtual ~BoomPlane();
        sf::Font font;
        sf::Text text;
        int state = 0;
        void stateChange();
    protected:
    private:
};

#endif // BOOMPLANE_H

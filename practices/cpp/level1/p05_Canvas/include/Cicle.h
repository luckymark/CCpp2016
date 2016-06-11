#ifndef CICLE_H
#define CICLE_H

#include <Shape.h>


class Cicle : public Shape
{
    public:
        Cicle();
        Cicle(int x,int y,int r);
        virtual ~Cicle();
    protected:
    private:
        int r;
};

#endif // CICLE_H

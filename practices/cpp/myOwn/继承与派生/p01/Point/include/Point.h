#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int x1=0,int y1=0):x(x1),y(y1){};
        void showXY();
        void move(int offx=0,int offy=0);
    protected:
        int x,y;
};

#endif // POINT_H

#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int x,int y);
        void moveTo(int x,int y);
        virtual ~Point();
    protected:
    private:
        int x=0,y=0;
};

#endif // POINT_H

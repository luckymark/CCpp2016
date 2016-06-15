#ifndef POINT_H
#define POINT_H
class Point
{
    public:
        Point(int X,int Y);
        ~Point();
        void move(int offX,int offY);
        void ShowXY();
    protected:
    private:
        int X,Y;
};

#endif // POINT_H

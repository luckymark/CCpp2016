#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
    public:
        Shape();
        virtual ~Shape();
        int keyPointX=0,keyPointY=0;//确定图形位置的点,如圆的圆心,长方形的左上角点等
    protected:
    private:
};

#endif // SHAPE_H

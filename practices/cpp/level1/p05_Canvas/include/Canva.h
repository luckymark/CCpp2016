#ifndef CANVA_H
#define CANVA_H
#include<vector>
#include<Shape.h>
#include<Rect.h>
#include<Circle.h>

#include<iostream>

using namespace std;
class Canva
{
    public:
        Canva();
        virtual ~Canva();
        void draw(Circle circle);
        void draw(Rect rect);
        void showAllShape();
    protected:
    private:
        vector<Circle> circleList;
        vector<Rect> rectList;
    friend class Shape;
};

#endif // CANVA_H

//
// Created by Administrator on 2016/4/21.
//

#ifndef P_CIRCLEANDPOINT_SHAPE_H
#define P_CIRCLEANDPOINT_SHAPE_H


class Point {
public:
    Point(int x, int y) : x(x), y(y) { };

};

class Shape {
public:
    Shape(char type) : type(type) { };

    char getType() { return type; };

    virtual void show() { };

    virtual float area() { return 0.0; };
private:
    char type;
};

class Circle : public Shape {
public:
    Circle(Point center, float r) : center(center), r(r), Shape(0) { };

    vitrual void show() { };

    float area() {
        return 3.14 * r * r;
    }
};

class Rect : public Shape {
public:
    Rect(float a, float b) : a(a), b(b), c(c) { };

    virtual void show() { };

    float area() {
        return a * b;
    }
};



#endif //P_CIRCLEANDPOINT_SHAPE_H

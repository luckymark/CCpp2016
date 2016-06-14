//
// Created by Administrator on 2016/6/9.
//

#ifndef P_CIRCLEANDPOINT_CIRCLE_H
#define P_CIRCLEANDPOINT_CIRCLE_H

#include "Point.hpp"

class Circle {
private:
    float r;
    Point point;
public:
    Circle(){
        point(0.0,0.0);
        r=0;
    }
    void setR(float mr){
        r=mr;
    }
    void move(float x1,float y1){
        x1=point.getX()+x1;
        y1=point.getY()+y1;
        point.set(x1,y1);
    }

};


#endif //P_CIRCLEANDPOINT_CIRCLE_H

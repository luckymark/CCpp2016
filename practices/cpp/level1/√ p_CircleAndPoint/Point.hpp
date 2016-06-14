//
// Created by Administrator on 2016/6/9.
//

#ifndef P_CIRCLEANDPOINT_POINT_H
#define P_CIRCLEANDPOINT_POINT_H


class Point {
private:
    float x;
    float y;
public:
    Point(float mx,float my){
        x=mx;
        y=my;
    }
    void set(float mx,float my){
        x=mx;
        y=my;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
};


#endif //P_CIRCLEANDPOINT_POINT_H

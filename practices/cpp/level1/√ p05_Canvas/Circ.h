//
// Created by Administrator on 2016/6/13.
//

#ifndef P05_CANVAS_CIRC_H
#define P05_CANVAS_CIRC_H


class Circ {
private:
    float X;
    float Y;
    float r;
public:
    Rect(float mR, float mX,float mY){
        X=mX;
        Y=Y;
        r=mR;
    }
    float getX(){
        return X;
    }
    float getY(){
        return Y;
    }
    float getArea(){
        return 3.14*r*r;
    }
};


#endif //P05_CANVAS_CIRC_H

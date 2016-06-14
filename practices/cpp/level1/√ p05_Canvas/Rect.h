//
// Created by Administrator on 2016/6/13.
//

#ifndef P05_CANVAS_RECT_H
#define P05_CANVAS_RECT_H


class Rect {
private:
    float Width;
    float Height;
public:
    Rect(float mWidth,float mHeight){
        Width=mWidth;
        Height=mHeight;
    }
    float getHeight(){
        return Height;
    }
    float getWidth(){
        return Width;
    }
    float getArea(){
        return Width*Height;
    }
};


#endif //P05_CANVAS_RECT_H

#include "Canva.h"

Canva::Canva()
{
    //ctor
}

Canva::~Canva()
{
    //dtor
}

void Canva::draw(Circle circle){
    circleList.push_back(circle);
}

void Canva::draw(Rect rect){
    rectList.push_back(rect);
}


void Canva::showAllShape(){
    for(int i=0;i<circleList.size();i++){
        cout<<"圆心坐标：（"<<circleList[i].keyPointX<<"，"<<circleList[i].keyPointY<<"）,"<<"半径为："<<circleList[i].r<<endl;
    }
    for(int i=0;i<rectList.size();i++){
        cout<<"长方形左上角坐标：（"<<rectList[i].keyPointX<<"，"<<rectList[i].keyPointY<<"），长为："<<rectList[i].length<<",宽为："<<rectList[i].width<<""<<endl;
    }
}


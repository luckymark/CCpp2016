#include "Rect.h"

Rect::Rect()
{
    //ctor
}

Rect::Rect(int x,int y,int length,int width)
{
    this->keyPointX = x;
    this->keyPointY = y;
    this->length = length;
    this->width = width;
}

Rect::~Rect()
{
    //dtor
}

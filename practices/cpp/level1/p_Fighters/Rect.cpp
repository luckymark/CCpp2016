#include "Rect.h"

int Rect::rect_judge(int x1,int y1,int x2,int y2){
    m=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return m;
}

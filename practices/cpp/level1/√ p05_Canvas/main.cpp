//
// Created by Administrator on 2016/6/9.
//

#include <iostream>
#include <list>

void addRect();

void addCirc();

void show();

list <Rect> list1;
list <Circ> list2;

int main() {
    int ch;
    std::cin >> ch;
    switch (ch) {
        case 1:
            addCirc();
            break;
        case 2:
            addRect();
            break;
        case 3:
            show();
            break;
        default:
            break;
    }
}

void addCirc() {
    float r, x, y;
    cin >> x;
    cin >> y;
    cin >> r;
    Circ circle(r, x, y);
    list2.push_back(circle);
}

void addRect() {
    float W, H;
    cin >> W;
    cin >> H;
    Rect rect(W, H);
    list1.push_back(rect);
}

void show() {
    std::cout << "Shape\t" << "Attribution\t\t" << "Area\n";
    for (Rect &s:list1) {
        std::cout << "Rectangle\t" << "Width: " << s.getWidth() << "\tHeight: " << s.getHeight() << "\t" <<
        "s.getArea()\n";
    }
    for (Circ &s:list2) {
        std::cout << "Circle\t" << "Point: (" << s.getX() << s.getY() << "\t\t" << "s.getArea()\n";
    }
}
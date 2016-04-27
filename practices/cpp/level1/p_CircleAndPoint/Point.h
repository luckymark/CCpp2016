#ifndef POINT_H
#define POINT_H

#ifdef DEBUG
#include <iostream>
#endif

#include <vector>
#define BY_HUMAN 1
#define BY_POINT 0
class Point
{
private:
  int coorX = 0;
  int coorY = 0;
  std::vector<Point *> childPoint;
public:
  Point();
  Point(int X, int Y) : coorX(X), coorY(Y) {}
  //isCenter mean this call is require by human or another Point
  void move(int deltaX, int deltaY, bool isCenter = BY_POINT);
  void bind(Point *);
  Point *toBind();
#ifdef DEBUG
  void printStatus()
  {
    std::cout << "===========start=========" << std::endl;
    std::cout << "(x, y)" << coorX << "," << coorY << std::endl;
    std::cout << "This is the binded point : " << std::endl;
    for(auto it = childPoint.begin(); it != childPoint.end(); it++)
    {
      std::cout << *it << std::endl;
    }
    std::cout << "============end===========" << std::endl;
  }
#endif
};
#endif

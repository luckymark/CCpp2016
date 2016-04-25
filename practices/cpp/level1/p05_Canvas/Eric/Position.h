#ifndef POSITION_H
#define POSITION_H
class Position
{
public:
  Position(int x, int y) : locationX(x), locationY(y){}
  int getX() const {return locationX;}
  int getY() const {return locationY;}
private:
  int locationX;
  int locationY;
};
#endif

#ifndef SHAPES_H
#define SHAPES_H
class Shape
{
public:
	Shape() = default;
	Shape(int sourceX, int sourceY) : locationX(sourceX), locationY(sourceY){}
	virtual void print() const = 0;
	virtual ~Shape() = default;
protected:
	int locationX = 0;
	int locationY = 0;
};
#endif

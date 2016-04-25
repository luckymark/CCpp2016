#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
public:
	Shape() = default;
	virtual void print() const = 0;
	virtual ~Shape() = default;
};
#endif

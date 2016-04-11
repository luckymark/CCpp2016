#ifndef SHARP_H
#define SHARP_H

class Sharp
{
public:
	Sharp() = default;
	Sharp(int sourceX, int sourceY) : locationX(sourceX), locationY(sourceY){}
	virtual void print() const = 0;
	virtual ~Sharp() = default;
protected:
	int locationX = 0;
	int locationY = 0;
};
#endif
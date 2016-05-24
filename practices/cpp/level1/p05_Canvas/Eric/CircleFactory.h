#ifndef CIRCLE_FACTORY_H
#define CIRCLE_FACTORY_H

#include "ShapeFactory.h"
#include "Circle.h"

class CircleFactory : public ShapeFactory
{
public:
  Shape *createShape() override;
};
#endif

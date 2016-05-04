#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "Shape.h"

class ShapeFactory
{
public:
  virtual Shape *createShape() = 0;
};
#endif

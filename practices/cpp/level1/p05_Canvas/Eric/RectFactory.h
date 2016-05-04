#ifndef RECT_FACTORY_H
#define RECT_FACTORY_H

#include "ShapeFactory.h"
#include "Rect.h"

class RectFactory : public ShapeFactory
{
public:
  Shape *createShape() override;
};
#endif

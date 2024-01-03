#include "shape.h"


bool Shape::operator<(const Shape& shape) const
{
	return this->getArea() < shape.getArea();
}
#ifndef INDV_4_SHAPE_H_
#define INDV_4_SHAPE_H_
#include "point.h"
#include <string>
class Shape
{
public:

	virtual ~Shape() = default;;
	virtual double getArea() const = 0;
	virtual void scale(double factor) = 0;
	virtual Point getCenter()const = 0;
	virtual std::string getName()const = 0;
	virtual bool operator<( const Shape& shape) const;
};
#endif
 
#include "ring.h"
#define _USE_MATH_DEFINES
#include <math.h>

Ring::Ring (const Point& centre, double internalRadius, double externalRadius)
{
	if (internalRadius <= 0.0 || externalRadius == 0.0 || internalRadius > externalRadius)
	{
		throw std::exception("Error while creating (Ring) Obj: incorrect input value!");
	}

	centre_ = centre;
	internalRadius_ = internalRadius;
	externalRadius_ = externalRadius;
}

double Ring::getArea() const
{
	
	return (M_PI * pow(externalRadius_, 2) - M_PI * pow(internalRadius_, 2));
}

Point Ring::getCenter() const
{
	return centre_;
}

std::string Ring::getName() const
{
	return "Ring";
}

void Ring::scale(double factor)
{
	if (factor == 0.0)
	{
		throw std::exception("Error while scaling Ring: incorrect factor value!");
	}
	externalRadius_ *= factor;
	internalRadius_ *= factor;
}
#ifndef INDV_4_RING_H_
#define INDV_4_RING_H_
#include "shape.h"

class Ring:public Shape
{
public:
	Ring(const Point& centre, double internalRadius, double externalRadius);

	double getArea() const override;

	void scale(double factor) override;

	Point getCenter() const override;

	std::string getName() const override;

private:
	Point centre_;
	double internalRadius_;
	double externalRadius_;


};
#endif


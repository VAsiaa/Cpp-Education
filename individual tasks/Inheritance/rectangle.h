#ifndef INDV_4_RECTANGLE_H_
#define INDV_4_RECTANGLE_H_
#include "shape.h"


class Rectangle:public Shape
{
public:
	Rectangle(Point& leftBottom, Point& rightTop);
	double getArea() const override;
	void scale(double factor) override;
	Point getCenter() const override;
	std::string getName() const override;

private:
	Point leftBottom_;
	Point rightTop_;
};
#endif

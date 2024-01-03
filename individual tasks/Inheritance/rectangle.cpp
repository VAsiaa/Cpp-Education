#include "rectangle.h"

Rectangle::Rectangle(Point& leftBottom, Point& rightTop)
{

	if (leftBottom.x > rightTop.x || leftBottom.y > rightTop.y) // Низ не дожен быть выше верха, право не должно быть больше лево
	{
		throw std::exception("Error while creating(Rectangle) Obj: incorrect input value!");
	}
	leftBottom_.x = leftBottom.x;
	leftBottom_.y = leftBottom.y;

	rightTop_.x = rightTop.x;
	rightTop_.y = rightTop.y;
}

double Rectangle::getArea() const
{
	double height = rightTop_.y - leftBottom_.y;
	double width = rightTop_.x - leftBottom_.x;
	return (height * width);

}

Point Rectangle::getCenter() const
{
	Point tmp = { ((rightTop_.x + leftBottom_.x) / 2), ((rightTop_.y + leftBottom_.y) / 2) };
	return tmp;
}

std::string Rectangle::getName() const
{
	return "Rectangle";
}

void Rectangle::scale(double factor)
{
	if (factor == 0.0)
	{
		throw std::exception("Error while scaling Rectangle: incorrect factor value!");
	}
	Point massCenter = getCenter();
	rightTop_.x = massCenter.x + factor * (rightTop_.x - massCenter.x); // right
	rightTop_.y = massCenter.y + factor * (rightTop_.y - massCenter.y); // top

	leftBottom_.x = massCenter.x + factor * (leftBottom_.x - massCenter.x); //left
	leftBottom_.y = massCenter.y + factor * (leftBottom_.y - massCenter.y); // bottom
}
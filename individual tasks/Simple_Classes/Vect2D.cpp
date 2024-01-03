#include "Vect2D.h"
#include <cmath> // для скалярного произведения


std::ostream& operator<<(std::ostream& stream, const Vect2D& vect2D)
{
	return stream << "X = " << vect2D.x_ << "  " << "Y = " << vect2D.y_ << "\n";
}


Vect2D::Vect2D(const double x, const double y)
{
	x_ = x;
	y_ = y;
}

Vect2D Vect2D::operator*(double value) const
{
	Vect2D tmp = {(x_ * value), y_ * value };
	return tmp;
}

Vect2D Vect2D::operator+(const Vect2D& v2d2) const{

	Vect2D tmp = {(x_ + v2d2.x_), (y_ + v2d2.y_)};
	return tmp;
}

double Vect2D::operator*(const Vect2D& v2d2) const
{
	return (x_ * v2d2.x_ + y_ * v2d2.y_);
}

double Vect2D::getSize() const
{
	return (std::abs(std::sqrt(std::pow(x_, 2) + std::pow(y_, 2))));  // ТО Пифагора
}